// sid.cpp
// require JsonCpp, libcurl

#pragma once

#ifndef __SID_H__
#define __SID_H__

#include "json/json.h"
#include "json/writer.h"
#include "curl/curl.h"
#include <string>


namespace
{
	std::size_t callback(
		const char* in,
		std::size_t size,
		std::size_t num,
		std::string* out)
	{
		const std::size_t totalBytes(size * num);
		out->append(in, totalBytes);
		return totalBytes;
	}
}

class SIDCpp {
private:
	std::string clientName;

	Json::Value curlPost(std::string url, std::string data, std::string method = "POST");

public:
	SIDCpp(std::string clientName);

	~SIDCpp();

	Json::Value login(std::string clientid, std::string sessid);
	Json::Value login(std::string clientid, std::string id, std::string pw);
	int logout(std::string clientid, std::string sessid);
	std::string getUserNickname(std::string cilentid, std::string sessid);
	std::string createClientID(std::string devicedata);
};

#endif