#pragma once

#ifndef BASESERVER_H
#define BASESERVER_H


class BaseServer
{
public:
	BaseServer()
	{
		isRun_ = false;
	}
	virtual void Run() = 0;
	virtual void Stop() = 0;
	virtual bool isRun() = 0;
	virtual ~BaseServer()
	{

	}
protected:
	bool isRun_;
};

#endif