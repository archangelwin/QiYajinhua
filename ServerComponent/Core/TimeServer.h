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
	boost::function<void(void)> func_;	//Ҫ���õĺ���
	int repeatTimes_;	//Ҫִ�ж��ٴ�
	long milisecs_;	//ִ�м��ʱ��
	int ID_;	//��ʱ��ID
	int Counting_;	//��ִ�ж��ٴ�
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