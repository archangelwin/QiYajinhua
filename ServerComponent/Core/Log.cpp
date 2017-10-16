#include "Log.h"
#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp> 

void Log::Debug(std::string str)
{
	Write("Debug", str);
}

void Log::Info(std::string str)
{
	Write("Info", str);
}

void Log::Warning(std::string str)
{
	Write("Warning", str);
}

void Log::Error(std::string str)
{
	Write("Error", str);
}

void Log::Write(std::string typestr, std::string str)
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
