#pragma once
#include "BaseServer.h"
#include <boost/asio.hpp>
namespace Core
{
	class AsyncServer :public BaseServer
	{
	public:
		AsyncServer();
		void Run() override;
		void Stop() override;
		bool isRun() override;
		boost::asio::io_service &GetIOService();
		~AsyncServer();
	private:
		boost::asio::io_service io_service_;
	};
}