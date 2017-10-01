#include "TimeServer.h"
namespace Core
{

	void TimeServer::Run()
	{
		isRun_ = true;
	}

	void TimeServer::Stop()
	{
		isRun_ = false;
	}

	bool TimeServer::isRun()
	{
		return isRun_;
	}

	void TimeServer::SetTime(int TimeID, int milisecs, boost::function<void(void)>, int repeatTimes)
	{
		auto item= timermap_.find(TimeID);
		if (item == timermap_.end())
		{

		}
		else
		{

		}
	}

	void TimeServer::KillTime(int TimeID)
	{
		auto item = timermap_.find(TimeID);
	}

	void TimeServer::KillAllTime()
	{
		for (auto Target : timermap_)
		{

		}
	}

	TimeServer::~TimeServer()
	{
		this->KillAllTime();
	}

	Timer::Timer(boost::asio::io_service &io, int ID, int milisecs, boost::function<void(void)> func, int repeatTimes):
		ID_(ID),
		milisecs_(milisecs),
		repeatTimes_(repeatTimes),
		Counting_(0),
		func_(func),
		timer_(io, boost::posix_time::seconds(milisecs))
	{
		timer_.async_wait(boost::bind(&Timer::Loop,this));
	}

	int Timer::GetID()
	{
		return ID_;
	}

	void Timer::Loop()
	{
		func_();
		Counting_ += 1;
		if (Counting_ >= repeatTimes_)
			return;
		timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(milisecs_));
		timer_.async_wait(boost::bind(&Timer::Loop, this));
	}

	Timer::~Timer()
	{

	}

}