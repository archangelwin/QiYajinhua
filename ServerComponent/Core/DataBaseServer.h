#pragma once
#include "BaseServer.h"
namespace Core
{
	class DataBaseServer:public BaseServer
	{
	public:
		DataBaseServer();
		void Run() override;
		void Stop() override;
		bool isRun() override;
		~DataBaseServer();
	};
}