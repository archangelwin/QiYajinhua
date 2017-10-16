#include "BaseView.h"
#include "BaseModle.h"



BaseModle::BaseModle(BaseView*view):
	BaseView_(view)
{

}

void BaseModle::OnDBConnect()
{
	BaseView_->OnModleEvent();
}

void BaseModle::OnCommandEnd(int, CommandResult)
{
	BaseView_->OnModleEvent();
}

BaseModle::~BaseModle()
{

}

