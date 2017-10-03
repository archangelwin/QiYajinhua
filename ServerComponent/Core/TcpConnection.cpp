#include "TcpConnection.h"
namespace Core
{

	Tcp_Connection::pointer Tcp_Connection::Create(boost::asio::io_service& io_service)
	{
		return pointer(new Tcp_Connection(io_service));
	}

	tcp::socket & Tcp_Connection::Sokcet()
	{
		return sock_;
	}

	Tcp_Connection::Tcp_Connection(boost::asio::io_service &io_service):
		sock_(io_service)
	{

	}

	SocketItem::SocketItem(Tcp_Connection::pointer tcp_connection,int index):
		tcp_connection_(tcp_connection),
		connecttime_(0),
		index_(index),
		isConnect_(false)
	{

	}

	void SocketItem::Close()
	{
		tcp_connection_->Sokcet().close();
	}

	boost::asio::ip::address SocketItem::GetClientAddress()
	{
		boost::asio::ip::tcp::endpoint remote_ep = tcp_connection_->Sokcet().remote_endpoint();
		return remote_ep.address();
	}

	long SocketItem::GetConnectTime()
	{
		return connecttime_;
	}

	int SocketItem::GetIndex()
	{
		return index_;
	}

	void SocketItem::GetRound()
	{

	}

	bool SocketItem::IsConnect()
	{
		return isConnect_;
	}

	void SocketItem::SendData()
	{

	}

	SocketItem::~SocketItem()
	{

	}

}