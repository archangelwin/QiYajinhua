#include "MsgFunction.h"
#include <iostream>

MsgFunction* MsgFunction::m_instance = nullptr;

int MsgFunction::CallFunc(std::string Func,std::string MsgData,int ItemID)
{
	auto it = m_FuncMap.find(Func);
	if(it!=m_FuncMap.end())
	{
		m_FuncMap[Func](MsgData, ItemID);
		return 0;
	}
	return -1;
}
 
void MsgFunction::AddFunc(std::string FuncName, Function Func)
{
    m_FuncMap[FuncName]=Func;
}
MsgFunction* MsgFunction::GetInstance()
{
	if(m_instance==nullptr)
	{
		m_instance = new MsgFunction;
	}
	return m_instance;
}

