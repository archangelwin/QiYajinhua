#pragma once

#ifndef TIMESERVER_H
#define TIMESERVER_H
#include "BaseServer.h"
#include <boost/function.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <map>

class Timer
{
public:
	Timer(boost::asio::io_service &io,
		int ID,int milisecs, boost::function<void(void)>,int repeatTimes);
	int GetID();
	void Loop();
	~Timer();
private:
	boost::asio::deadline_timer timer_;
	boost::function<void(void)> func_;	//要调用的函数
	int repeatTimes_;	//要执行多少次
	long milisecs_;	//执行间隔时间
	int ID_;	//计时器ID
	int Counting_;	//已执行多少次
};

class TimeServer:public BaseServer
{
public:
	TimeServer()=delete;
	void Run() override;
	void Stop() override;
	bool isRun() override;
	void SetTime(int TimeID, int milisecs, boost::function<void(void)>, int repeatTimes);
	void KillTime(int TimeID);
	void KillAllTime();
	virtual ~TimeServer();
private:
	std::map<int,Timer*> timermap_;
};

#endif