#pragma once

#ifndef LOG_H
#define LOG_H
#include <fstream>
#include "GlobalDefine.h"

class Log
{
public:
	Log() = delete;
	Log(const Log&) = delete;
	static void Debug(std::string str);
	static void Info(std::string str);
	static void Warning(std::string str);
	static void Error(std::string str);
private:
	static void Write(std::string typestr, std::string str);
};


#endif