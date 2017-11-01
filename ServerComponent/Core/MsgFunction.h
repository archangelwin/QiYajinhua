#pragma once
#ifndef MSGFUNCTION_H
#define MSGFUNCTION_H
 
#include <string>
#include <functional>
#include <map>
 
class MsgFunction
{
public:
  MsgFunction()=delete;
  static int CallFunc(std::string Func,std::string MsgData,int ItemID);
  static void AddFunc(std::function<void(void)> Func,std::string FuncName);
private:
  static  std::map<std::string,std::function<void(void)>> m_FuncMap;
};
 
//#define MSGREGISTER(MSG) MsgFunction::AddFunc(MSG,#MSG)
//#define MSGCALLFUNC(MSG,MSGDATA,ITEMID) MsgFunction::CallFunc(MSG,MSGDATA,ITEMID)

#endif
