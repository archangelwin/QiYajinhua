#pragma once
#ifndef BASECONTROLL_H
#define BASECONTROLL_H

#include "TcpServer.h"
#include "BaseView.h"

class BaseControll:public TcpObserver
{
public:
	BaseControll(BaseView*);
	void OnSocketAccept(int SockIndex) override;
	void OnSocketRead(int SockIndex, char *pData) override;
	void OnSocketClose(int SockIndex) override;
	void OnHttpAccept(int SockIndex, request Data, std::string json) override;
	~BaseControll();
private:
	BaseView *BaseView_;
};

#endif