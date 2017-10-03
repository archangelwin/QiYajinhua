#pragma once
#include "BaseServer.h"
#include <string>
namespace Core
{
	class DataBaseObserver
	{
	public:
		virtual void OnDBConnect()=0;
		virtual void OnQueryEnd()=0;
	};

	class DataBaseConnect
	{
	public:
		DataBaseConnect();
		void GetDBAddress();
		int GetIndex();
		bool IsConnected();
	private:
		int index_;
	};

	class DataBaseServer:public BaseServer
	{
	public:
		DataBaseServer();
		void Run() override;
		void Stop() override;
		bool isRun() override;
		void Connect();
		void Command(std::string cmd);
		void SetObserver(DataBaseObserver obj);
		~DataBaseServer();
	};
}