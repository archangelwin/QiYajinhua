#pragma once
#include "BaseServer.h"
namespace Core
{
	class SocketPool
	{

	};

	class TcpObserver
	{
	public:

		void OnSocketAccept();
		void OnSocketClone();
		void OnSocketRead();
	};

	class TcpServer:public BaseServer
	{
	public:
		TcpServer();
		void Run() override;
		void Stop() override;
		bool isRun() override;
		void CloseSocket(int index);
		void SendData(int index);
		void SendDataBatch();
		~TcpServer();
	};

	
}
