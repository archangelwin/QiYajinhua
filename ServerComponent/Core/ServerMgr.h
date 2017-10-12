#pragma once

#ifndef SERVERMGR_H
#define SERVERMGR_H

class AsyncServer;
class DataBaseServer;
class TcpServer;
class TimeServer;


class ServerMgr
{
public:
	ServerMgr();
	static ServerMgr *GetInstance();
	AsyncServer *GetAsyncServer();
	DataBaseServer *GetDataBaseServer();
	TcpServer *GetTcpServer();
	TimeServer *GetTimeServer();
	~ServerMgr();
private:
	static ServerMgr *instance_;
	AsyncServer *asyncserver_;
	DataBaseServer *databaseserver_;
	TcpServer *tcpserver_;
	TimeServer *timeserver_;
};

#endif