#pragma once

#ifndef DATABASESERVER_H
#define DATABASESERVER_H
#include "BaseServer.h"
#include <string>
#include <map>
#include <mysql.h>
#include "ThreadPool.h"
class DataBaseCommand;

struct SQLTYPE
{
	std::string user;
	std::string password;
	std::string host;
	std::string db;
	unsigned long port;
};

class CommandResult
{
public:
	CommandResult(MYSQL_RES* res);
	CommandResult(const CommandResult&);
	int GetColumnCount();
	void GetColumnType();
	void GetColumnValue();
	int GetCount();
	void Move2First();
	void Next();
	~CommandResult();
private:
	MYSQL_RES *mysql_res_;
};

class DataBaseObserver
{
public:
	virtual void OnDBConnect()=0;
	virtual void OnCommandEnd(int,CommandResult)=0;
};

	

class DataBaseServer:public BaseServer
{
public:
	DataBaseServer(SQLTYPE sqltype);
	void Run() override;
	void Stop() override;
	bool isRun() override;
	void Command(int index_, std::string cmd);
	void CommandComplete(int index_, CommandResult result);
	void SetObserver(DataBaseObserver *obj);
	~DataBaseServer();
private:
	bool Connect();
	void DisConnect();
	void OnDBConnect(int index);
	DataBaseObserver *DataBaseObserver_;
	SQLTYPE sqltype_;
	MYSQL mysql_;
	ThreadPool *ThreadPool_;
	std::map<int, DataBaseCommand*> DataBaseConnectMap_;
};

class DataBaseCommand
{
public:
	DataBaseCommand(MYSQL *mysql, DataBaseServer* pDataBaseServer, int index, std::string cmd);
	bool IsComplete();
	void Run();
	void Stop();
	int GetIndex();
	~DataBaseCommand();
private:
	void Commit();
	bool iscomplete;
	int index_;
	MYSQL *mysql_;
	DataBaseServer *DataBaseServer_;
	std::string cmd_;
};

#endif