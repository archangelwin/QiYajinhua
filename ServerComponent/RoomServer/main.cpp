#include "RoomServer.h"
#include <iostream>
#include "../../MsgDefine/person.pb.h"
#include "Log.h"
#include "../Core/MsgFunction.h"
void CreateID(std::string data, int itemID)
{
	Json::Value value;
	Json::Reader reader;
	reader.Parse(data.c_str(),value,false);
	std::cout << "CreateID:" << data << std::endl
			  << "ItemID:" << itemID << std::endl;
}
int main(int argc, char *argv[])
{
	MsgFunction::GetInstance()->AddFunc("CreateID", CreateID);
	try
	{
		Applications::RoomServer *server = new Applications::RoomServer;
		server->Run();
	}
	catch (boost::system::error_code ec)
	{
		Log::Debug(ec.message());
	}
	return 0;
}