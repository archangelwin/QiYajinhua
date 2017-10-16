#include "AsyncServer.h"


AsyncServer::AsyncServer()
{

}

void AsyncServer::Run()
{
	
}

void AsyncServer::Stop()
{

}

bool AsyncServer::isRun()
{
	return false;
}

boost::asio::io_service & AsyncServer::GetIOService()
{
	return io_service_;
}

AsyncServer::~AsyncServer()
{

}

