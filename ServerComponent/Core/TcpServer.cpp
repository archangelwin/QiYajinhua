#include "TcpServer.h"
namespace Core
{

	TcpServer::TcpServer(int Port):
		Port_(Port)
	{

	}

	void TcpServer::Run()
	{
		if (TcpObserver_ == nullptr)
		{
			throw("TcpObserver is null");
			return;
		}
		if (isRun_)
		{
			throw("TcpObserver is run");
			return;
		}
		acceptor_ = new TCP::acceptor(ServerMgr::GetInstance()->GetAsyncServer()->GetIOService(),TCP::endpoint(TCP::v4(), Port_));
		this->StartAcceptor();
	}

	void TcpServer::Stop()
	{

	}

	bool TcpServer::isRun()
	{
		return isRun_;
	}

	void TcpServer::CloseSocket(int index)
	{
		for (auto Target : SocketItemMap_)
		{
			if (Target.first == index)
			{
				Target.second->Close();
				//SocketItemMap_.erase(Target);
			}
		}
	}

	void TcpServer::StartAcceptor()
	{
		auto tcp_connect= Tcp_Connection::Create(ServerMgr::GetInstance()->GetAsyncServer()->GetIOService());
		acceptor_->async_accept(tcp_connect->Sokcet(),
			boost::bind(TcpServer::AcceptorHandle, this,
				tcp_connect, boost::asio::placeholders::error));
	}

	void TcpServer::AcceptorHandle(Tcp_Connection::pointer tcp_connect, boost::system::error_code err)
	{
		if (err)
		{

		}
		SocketItem *item = new SocketItem(tcp_connect, SocketItemMap_.size());
		SocketItemMap_.insert(std::map<int, SocketItem*>::value_type(SocketItemMap_.size(), item));
		TcpObserver_->OnSocketAccept();
		this->StartAcceptor();
	}


	void TcpServer::SendData(int index)
	{
		for (auto Target : SocketItemMap_)
		{
			if (Target.first == index)
			{
				Target.second->SendData();
			}
		}
	}

	void TcpServer::SendDataBatch()
	{
		for (auto Target : SocketItemMap_)
		{
			Target.second->SendData();
		}
	}

	void TcpServer::SetTcpObserver(TcpObserver *pTcpObserver)
	{
		TcpObserver_ = pTcpObserver;
	}

	TcpServer::~TcpServer()
	{

	}

}