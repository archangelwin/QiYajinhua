#pragma once
#include "BaseServer.h"
#include "TcpConnection.h"
#include "AsyncServer.h"
#include "ServerMgr.h"
namespace Core
{
	typedef boost::asio::ip::tcp TCP;
	class SocketPool
	{

	};

	class TcpObserver
	{
	public:
		virtual void OnSocketAccept()=0;
		virtual void OnSocketClone()=0;
		virtual void OnSocketRead()=0;
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
		void SendData(int index);
		void SendDataBatch();
		void SetTcpObserver(TcpObserver *);
		~TcpServer();
	private:
		int Port_;
		std::map<int, SocketItem*> SocketItemMap_;
		TcpObserver *TcpObserver_;
		TCP::acceptor *acceptor_;
	};

	
}
