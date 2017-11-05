#pragma once
#ifndef MSGFUNCTION_H
#define MSGFUNCTION_H
 
#include <string>
#include <functional>
#include <map>
 
class MsgFunction
{
public:
  typedef void(*Function)(std::string MsgData, int ItemID);
  int CallFunc(std::string Func,std::string MsgData,int ItemID);
  void AddFunc(std::string FuncName, Function Func);
  static MsgFunction* GetInstance();
private:
  std::map<std::string, Function> m_FuncMap;
  static  MsgFunction *m_instance;
};
 
//#define MSGREGISTER(MSG) MsgFunction::AddFunc(MSG,#MSG)
//#define MSGCALLFUNC(MSG,MSGDATA,ITEMID) MsgFunction::CallFunc(MSG,MSGDATA,ITEMID)

#endif
