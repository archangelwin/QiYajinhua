#pragma once
#include "BaseServer.h"
#include "TcpServer.h"
#include "RoomController.h"
namespace Applications
{
	class RoomServer :public BaseServer,public RoomController
	{
	public:
		RoomServer();
		void Run() override;
		void Stop() override;
		bool isRun() override;
		void OnSocketAccept(int SockIndex) override;
		void OnSocketRead(int SockIndex, char *pData) override;
		void OnSocketClose(int SockIndex) override;
		void OnHttpAccept(int SockIndex, request Data,std::string json) override;
		~RoomServer();
	private:
		TcpServer *TcpServer_;
	};
}