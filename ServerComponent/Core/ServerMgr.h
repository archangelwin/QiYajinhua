#pragma once
#include "AsyncServer.h"
#include "DataBaseServer.h"
#include "TcpServer.h"
#include "TimeServer.h"
namespace Core
{
	class ServerMgr
	{
	public:
		ServerMgr();
		~ServerMgr();
		static ServerMgr *GetInstance();
		AsyncServer *GetAsyncServer();
		DataBaseServer *GetDataBaseServer();
		TcpServer *GetTcpServer();
		TimeServer *GetTimeServer();
	private:
		static ServerMgr *instance_;
		AsyncServer *asyncserver_;
		DataBaseServer *databaseserver_;
		TcpServer *tcpserver_;
		TimeServer *timeserver_;
	};
}