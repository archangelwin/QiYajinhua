#include "ServerMgr.h"
namespace Core
{
	ServerMgr *ServerMgr::instance_ = nullptr;

	ServerMgr::ServerMgr()
	{

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
		return nullptr;
	}

	DataBaseServer * ServerMgr::GetDataBaseServer()
	{
		return nullptr;
	}

	TcpServer * ServerMgr::GetTcpServer()
	{
		return nullptr;
	}

	TimeServer * ServerMgr::GetTimeServer()
	{
		return nullptr;
	}
}
