#include "RoomServer.h"
#include <iostream>
#include "../../MsgDefine/person.pb.h"
#include "Log.h"
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