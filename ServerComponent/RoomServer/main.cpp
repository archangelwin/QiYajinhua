#include "RoomServer.h"
#include <iostream>
#include "../../MsgDefine/person.pb.h"
#include "Log.h"
#include "../Core/MsgFunction.h"
void test(std::string data,int itemID)
{
	
}
int main(int argc, char *argv[])
{
	try
	{
		Applications::RoomServer *server = new Applications::RoomServer;
		server->Run();
	}catch(boost::system::error_code ec)
	{
		Log::Debug(ec.message());
	}
	return 0;
}