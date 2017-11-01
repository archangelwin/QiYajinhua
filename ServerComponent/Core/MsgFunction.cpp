#include "MsgFunction.h"
#include <iostream>


int MsgFunction::CallFunc(std::string Func,std::string MsgData,int ItemID)
{
  //  if(m_FuncMap.count(Func))
  //  {
		////auto func = std::bind(m_FuncMap[Func],MsgData,ItemID);
		////func();
  //      return 0;
  //  }
  //  else
  //  {
  //      std::cout<<"unsupported function str:"<<Func.c_str()<<std::endl;
  //      return -1;
  //  }
	return 0;
}

void MsgFunction::AddFunc(std::function<void(void)> Func,std::string FuncName)
{
   // m_FuncMap[FuncName]=Func;
}
