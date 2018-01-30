#include "TcpServer.h"
#include "AsyncServer.h"
#include "ServerMgr.h"
#include "HttpRequest_Parser.hpp"
#include "HttpRequest.hpp"
#include "Tool.hpp"
#include "Log.h"
#include <iostream>
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
	try
	{
		acceptor_ = new TCP::acceptor(ServerMgr::GetInstance()->GetAsyncServer()->GetIOService(), TCP::endpoint(TCP::v4(), Port_));
		this->StartAcceptor();
	}catch(boost::system::error_code ec)
	{
		std::string err = ec.message();
		throw(err);
	}
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
		boost::bind(&TcpServer::AcceptorHandle, this,
			tcp_connect, boost::asio::placeholders::error));
}

void TcpServer::AcceptorHandle(Tcp_Connection::pointer tcp_connect, boost::system::error_code err)
{
	if (err)
	{
		throw err.message();
	}
	int itemID = SocketItemMap_.size();
	SocketItem *item = new SocketItem(tcp_connect, itemID);
	SocketItemMap_.insert(std::map<int, SocketItem*>::value_type(itemID, item));
	TcpObserver_->OnSocketAccept(itemID);
	this->DoRead(item->GetPoint()->Sokcet(),itemID);

	this->StartAcceptor();
}

void TcpServer::SendData(int index, char *pData)
{
	for (auto Target : SocketItemMap_)
	{
		if (Target.first == index)
		{
			Target.second->SendData(pData);
		}
	}
}

void TcpServer::SendDataBatch(char *pData)
{
	for (auto Target : SocketItemMap_)
	{
		Target.second->SendData(pData);
	}
}



 

void TcpServer::DoRead(boost::asio::ip::tcp::socket &sock,int index)
{
	std::array<char, 8192> buffer_;
	sock.async_read_some(boost::asio::buffer(buffer_),
		boost::bind(&TcpServer::RecvData, this,
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred,
		index, buffer_.data()));
}

void TcpServer::RecvData(boost::system::error_code ec, std::size_t bytes_transferred,int index, char *pData)
{
	request_parser request_parser_;
	request request_;
	request_parser::result_type result;

	if (!ec)
	{
		std::tie(result, std::ignore) = request_parser_.parse(
			request_, pData, pData + bytes_transferred);
		if (result == request_parser::good)//��������ɹ�
		{
			 
			TcpObserver_->OnHttpAccept(index, request_, HttpFilterJson(pData));

			//this->DoRead(this->GetSocketItem(index)->GetPoint()->Sokcet(), index);

		}
		else if (result == request_parser::bad)//��������ʧ��
		{
			TcpObserver_->OnSocketRead(index, pData);
			this->DoRead(this->GetSocketItem(index)->GetPoint()->Sokcet(), index);
		}
		else if (result == request_parser::indeterminate)
		{
			//std::cout << "indeterminate" << std::endl;
			TcpObserver_->OnSocketRead(index, pData);
			this->DoRead(this->GetSocketItem(index)->GetPoint()->Sokcet(), index);
		}

	}
	else
	{
		std::cout << pData << std::endl;
		std::cout << "boost error:" << ec.message() << std::endl;
		Log::Error(pData);
	}
 
}


void TcpServer::SetTcpObserver(TcpObserver *pTcpObserver)
{
	TcpObserver_ = pTcpObserver;
}

SocketItem * TcpServer::GetSocketItem(int index)
{
	for (auto Target : SocketItemMap_)
	{
		if (Target.first == index)
		{
			return Target.second;
		}
	}
	return nullptr;
}

TcpServer::~TcpServer()
{

}
