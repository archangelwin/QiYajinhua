#pragma once

#ifndef TCPSERVER_H
#define TCPSERVER_H
#include "BaseServer.h"
#include "TcpConnection.h"
#include "HttpRequest.hpp"
class AsyncServer;

typedef boost::asio::ip::tcp TCP;

class TcpObserver
{
public:
	virtual void OnSocketAccept(int SockIndex)=0;
	virtual void OnSocketClose(int SockIndex)=0;
	virtual void OnSocketRead(int SockIndex, char *pData) = 0;
	virtual void OnHttpAccept(int SockIndex, request Data,std::string json) = 0;
};

class TcpServer:public BaseServer
{
public:
	TcpServer(int Port);
	void Run() override;
	void Stop() override;
	bool isRun() override;
	void CloseSocket(int index);
	void StartAcceptor();
	void AcceptorHandle(Tcp_Connection::pointer tcp_connect, boost::system::error_code err);
	void SendData(int index, char *pData);
	void SendDataBatch(char *pData);
	void SetTcpObserver(TcpObserver *);
	SocketItem *GetSocketItem(int index);
	~TcpServer();
private:
	void DoRead(boost::asio::ip::tcp::socket &sock,int index);
	void RecvData(boost::system::error_code ec, std::size_t bytes_transferred, int index,char *pData);
	int Port_;
	std::map<int, SocketItem*> SocketItemMap_;
	TcpObserver *TcpObserver_;
	TCP::acceptor *acceptor_;
};

	

#endif