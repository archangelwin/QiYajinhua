#pragma once
#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp> 
#include <fstream>
#include "GlobalDefine.h"
namespace Core
{

	class Log
	{
	public:
		Log() = delete;
		Log(const Log&) = delete;
		static void Debug(std::string str)
		{
			Write("Debug", str);
		}
		static void Info(std::string str)
		{
			Write("Info", str);
		}
		static void Warning(std::string str)
		{
			Write("Warning", str);
		}
		static void Error(std::string str)
		{
			Write("Error", str);
		}
	private:
		static void Write(std::string typestr, std::string str)
		{
			if (!boost::filesystem::exists(CoreGlobalDefine::LOG_PATH))
			{
				boost::filesystem::create_directory(CoreGlobalDefine::LOG_PATH);
			}
			std::string TimeStr = boost::posix_time::to_iso_string(boost::posix_time::second_clock::local_time());
			size_t pos = TimeStr.find('T');
			std::string LogFileName = (TimeStr.substr(0, pos + 3));


			std::string LogFilePath = CoreGlobalDefine::LOG_PATH + "/" + LogFileName;
			std::fstream LogStream;
			LogStream.open(LogFilePath, std::ios::app);

			std::string LogStr = TimeStr + " : " + typestr + " : " + str + "\n";

			LogStream.write(LogStr.c_str(), LogStr.size());
			LogStream.close();

		}
	};

}