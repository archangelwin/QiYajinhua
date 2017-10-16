#pragma once
#ifndef HTTPREQUEST_HPP
#define HTTPREQUEST_HPP
#include <string>
#include <vector>
#include "HttpHeader.hpp"
struct request
{
	std::string method;
	std::string uri;
	int http_version_major;
	int http_version_minor;
	std::vector<header> headers;
};
#endif