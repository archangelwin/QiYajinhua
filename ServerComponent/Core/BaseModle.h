#pragma once
#ifndef BASEMODLE_H
#define BASEMODLE_H

#include "DataBaseServer.h"
class BaseView;

class BaseModle :public DataBaseObserver
{
public:
	BaseModle(BaseView*);
	void OnDBConnect() override;
	void OnCommandEnd(int, CommandResult) override;
	~BaseModle();
private:
	BaseView *BaseView_;
};


#endif