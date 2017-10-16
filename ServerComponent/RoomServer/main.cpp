#include "RoomServer.h"
#include <iostream>
#include "../../MsgDefine/person.pb.h"
int main(int argc, char *argv[])
{

	Applications::RoomServer *server = new Applications::RoomServer;
	server->Run();
	return 0;
}