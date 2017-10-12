#include "AsyncServer.h"
#include "ServerMgr.h"

#include "DataBaseServer.h"
#include "GlobalDefine.h"

#include <mysql.h>

DataBaseServer::DataBaseServer(SQLTYPE sqltype):
	sqltype_(sqltype)
{

}

void DataBaseServer::Run()
{
	isRun_ = Connect();
	ThreadPool_ = new ThreadPool(CoreGlobalDefine::DB_THREADPOOL);

}

void DataBaseServer::Stop()
{
	DisConnect();
	isRun_ = false;
}

bool DataBaseServer::isRun()
{
	return isRun_;
}

bool DataBaseServer::Connect()
{
	mysql_init(&mysql_);
	if (mysql_real_connect(
		&mysql_,
		sqltype_.host.c_str(),
		sqltype_.user.c_str(),
		sqltype_.password.c_str(),
		sqltype_.db.c_str(),
		sqltype_.port,
		NULL, 0))
	{
		return true;
	}
	throw mysql_error(&mysql_);
	return false;
}

void DataBaseServer::DisConnect()
{
	mysql_close(&mysql_);
}

void DataBaseServer::OnDBConnect(int index)
{
	DataBaseConnectMap_.find(index);
}

void DataBaseServer::Command(int index_, std::string cmd)
{	
	if (mysql_query(&mysql_, cmd.c_str()))
	{
		MYSQL_RES *result = mysql_store_result(&mysql_);
		MYSQL_ROW sql_row = nullptr;
		while (sql_row = mysql_fetch_row(result))
		{

		}
	}
	else
	{
		throw mysql_error(&mysql_);
	}
}

void DataBaseServer::CommandComplete(int index_, CommandResult result)
{

}

void DataBaseServer::SetObserver(DataBaseObserver* obj)
{
	DataBaseObserver_ = obj;
}

DataBaseServer::~DataBaseServer()
{

}

DataBaseCommand::DataBaseCommand(MYSQL *mysql, DataBaseServer* pDataBaseServer,int index, std::string cmd):
	mysql_(mysql),
	index_(index),
	cmd_(cmd),
	iscomplete(false)
{

}


bool DataBaseCommand::IsComplete()
{
	return iscomplete;
}

void DataBaseCommand::Run()
{
	ServerMgr::GetInstance()->GetAsyncServer()->GetIOService().post(boost::bind(&DataBaseCommand::Commit, this));

}

void DataBaseCommand::Stop()
{

}

int DataBaseCommand::GetIndex()
{
	return index_;
}

DataBaseCommand::~DataBaseCommand()
{

}

void DataBaseCommand::Commit()
{
		
	if (mysql_query(mysql_, cmd_.c_str()))
	{
		MYSQL_RES *result = mysql_store_result(mysql_);
		MYSQL_ROW sql_row = nullptr;
		while (sql_row = mysql_fetch_row(result))
		{

		}
	}
	else
	{
		throw mysql_error(mysql_);
	}
	//DataBaseServer_->CommandComplete(index_);
}

CommandResult::CommandResult(MYSQL_RES* res):
	mysql_res_(res)
{

}

CommandResult::CommandResult(const CommandResult&res)
{
	mysql_res_ = res.mysql_res_;
}

int CommandResult::GetColumnCount()
{
	return 0;
}

void CommandResult::GetColumnType()
{

}

void CommandResult::GetColumnValue()
{

}

int CommandResult::GetCount()
{
	return 0;
}

void CommandResult::Move2First()
{

}

void CommandResult::Next()
{

}

CommandResult::~CommandResult()
{

}

