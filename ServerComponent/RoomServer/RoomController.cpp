#include "RoomController.h"
#include <iostream>
namespace Applications
{

	RoomController::RoomController(BaseView*view):
		BaseControll(view)
	{

	}

	void RoomController::OnSocketAccept(int SockIndex)
	{
		std::cout << "sockaccept" << SockIndex << std::endl;
	}

	void RoomController::OnSocketRead(int SockIndex, char *pData)
	{

	}

	void RoomController::OnSocketClose(int SockIndex)
	{

	}

	RoomController::~RoomController()
	{

	}

}