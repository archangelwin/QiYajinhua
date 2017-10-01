#include "Log.hpp"
#include "BaseServer.h"
#include "AsyncServer.h"
#include "DataBaseServer.h"
#include "GlobalDefine.h"
#include "ServerMgr.h"
#include "TcpConnection.h"
#include "TcpServer.h"
#include "ThreadPool.h"
#include "TimeServer.h"
void test(int i)
{
	std::cout <<i<< "test" << std::endl;
}
int main(int argc, char *argv[])
{
	boost::asio::io_service ios;
	Core::Timer time(ios,1,5,std::bind(&test,1),3);

	ios.run();
	return 0;
}
