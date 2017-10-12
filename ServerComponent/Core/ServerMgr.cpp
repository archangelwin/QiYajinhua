
#include "AsyncServer.h"
#include "DataBaseServer.h"
#include "TcpServer.h"
#include "TimeServer.h"
#include "ServerMgr.h"

ServerMgr *ServerMgr::instance_ = nullptr;

ServerMgr::ServerMgr()
{
	asyncserver_ = new AsyncServer;
}

ServerMgr::~ServerMgr()
{

}

ServerMgr * ServerMgr::GetInstance()
{
	if (instance_ == nullptr)
	{
		instance_ = new ServerMgr;
	}
	return instance_;
}

AsyncServer * ServerMgr::GetAsyncServer()
{
	return asyncserver_;
}

DataBaseServer * ServerMgr::GetDataBaseServer()
{
	return databaseserver_;
}

TcpServer * ServerMgr::GetTcpServer()
{
	return tcpserver_;
}

TimeServer * ServerMgr::GetTimeServer()
{
	return timeserver_;
}

