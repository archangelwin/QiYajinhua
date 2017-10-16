#pragma once
#ifndef ROOMCONTROLLER_H
#define ROOMCONTROLLER_H
#include "BaseController.h"
#include "BaseView.h"
namespace Applications
{
	class RoomController:public BaseControll
	{
	public:
		RoomController(BaseView*view);
		void OnSocketAccept(int SockIndex) override;
		void OnSocketRead(int SockIndex, char *pData) override;
		void OnSocketClose(int SockIndex) override;
		~RoomController();
	private:
	};
}
#endif