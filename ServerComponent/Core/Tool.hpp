#pragma once
#ifndef TOOL_HPP
#define TOOL_HPP
#include <string>
std::string HttpFilterJson(std::string src)
{
	size_t pos = src.rfind("\r\n\r\n");
	 
	std::string str = src.substr(pos+strlen("\r\n\r\n"), src.size());
	return str;
}
#endif