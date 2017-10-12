#pragma once

#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;


class Tcp_Connection :public boost::enable_shared_from_this<Tcp_Connection>
{
public:
	typedef boost::shared_ptr<Tcp_Connection> pointer;

	static pointer Create(boost::asio::io_service& io_service);
	tcp::socket &Sokcet();
private:
	Tcp_Connection(boost::asio::io_service &io_service);
	tcp::socket sock_;
};

class SocketItem
{
public:
	SocketItem(Tcp_Connection::pointer tcp_connection,int index);
	void Close();
	boost::asio::ip::address GetClientAddress();
	long GetConnectTime();
	int GetIndex();
	void GetRound();
	bool IsConnect();
	void SendData(char *pData);
	Tcp_Connection::pointer GetPoint();
	~SocketItem();
private:
	Tcp_Connection::pointer tcp_connection_;
	long connecttime_;
	int index_;
	bool isConnect_;
};

#endif