#include "BaseView.h"
#include "BaseController.h"


BaseControll::BaseControll(BaseView* view):
	BaseView_(view)
{

}

void BaseControll::OnSocketAccept(int SockIndex)
{
	BaseView_->OnControllerEvent();
}

void BaseControll::OnSocketRead(int SockIndex, char *pData)
{
	BaseView_->OnControllerEvent();
}

void BaseControll::OnSocketClose(int SockIndex)
{
	BaseView_->OnControllerEvent();
}

void BaseControll::OnHttpAccept(int SockIndex, request Data, std::string json)
{
	BaseView_->OnControllerEvent();
}

BaseControll::~BaseControll()
{

}

