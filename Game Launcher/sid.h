// sid.cpp
// require JsonCpp, libcurl

#pragma once

#include "json/json.h"
#include "json/writer.h"
#include "curl/curl.h"
#include <string>
// #include <iostream>

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
	// int passwordCheck(std::string clientid, std::string sessid, std::string pw);
	Json::Value createClientID(std::string devicedata);
};

Json::Value SIDCpp::curlPost(std::string url, std::string data, std::string method) {
	CURL *curl = NULL;
	CURLcode res;

	int httpCode(0);
	std::unique_ptr<std::string> httpData(new std::string());

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl) {
		struct curl_slist *chunk = NULL;
		curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);

		chunk = curl_slist_append(chunk, "Accept: application/json");
		chunk = curl_slist_append(chunk, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		//curl_easy_setopt(curl, CURLOPT_VERBOSE, true);

		res = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curl);
		Json::Value data;
		Json::Reader reader;
		reader.parse(httpData.get()->c_str(), data);

		return data;
	}
	Json::Value error;
	error["error"] = 1;
	return error;
}

SIDCpp::SIDCpp(std::string clientName) {
	this->clientName = clientName;
}

SIDCpp::~SIDCpp() {}

Json::Value SIDCpp::login(std::string clientid, std::string sessid) {
	try
	{
		Json::FastWriter writer;
		Json::Value senddata;
		senddata["type"] = "login";
		senddata["clientid"] = clientid;
		senddata["sessid"] = sessid;
		Json::Value userdata = this->curlPost("http://sid.donote.co:3000/api/session", writer.write(senddata));
		if (userdata["type"].asCString() == "error")
		{
			throw new std::exception;
		}
		Json::Value output;
		output["sessid"] = userdata["response_data"][0].asCString();
		output["pid"] = userdata["response_data"][1].asCString();
		output["nickname"] = userdata["response_data"][2].asCString();
		output["expire"] = userdata["response_data"][3].asCString();
		return output;
	}
	catch (const std::exception&)
	{
		Json::Value error;
		error["error"] = 1;
		return error;
	}
}

Json::Value SIDCpp::login(std::string clientid, std::string id, std::string pw) {
	Json::Value senddata;
	Json::FastWriter writer;
	senddata["type"] = "login";
	senddata["clientid"] = clientid;
	senddata["userid"] = id;
	senddata["password"] = pw;
	Json::Value userdata = this->curlPost("http://sid.donote.co:3000/api/session", writer.write(senddata));
	Json::Value output;
	output["sessid"] = userdata["response_data"][0].asCString();
	output["pid"] = userdata["response_data"][1].asCString();
	output["nickname"] = userdata["response_data"][2].asCString();
	output["expire"] = userdata["response_data"][3].asCString();
	return output;
}

int SIDCpp::logout(std::string clientid, std::string sessid) {
	Json::Value senddata;
	Json::FastWriter writer;
	senddata["type"] = "logout";
	senddata["clientid"] = clientid;
	senddata["sessid"] = sessid;

	Json::Value result = this->curlPost("http://sid.donote.co:3000/api/session", writer.write(senddata), "DELETE");
	if (result["type"].asString().compare("error")) {
		return 0;
	}
	if (!result["is_succeed"].asBool()) {
		return 0;
	}

	return 1;
}

std::string SIDCpp::getUserNickname(std::string clientid, std::string sessid) {
	std::string url = "http://sid.donote.co:3000/api/";
	url.append(clientid).append("/").append(sessid).append("/usname");
	try
	{
		Json::Value userdata = this->curlPost(url, "", "GET");
		if (userdata["type"].asCString() == "error")
			return "";
		if (!userdata["is_vaild"].asBool()) {
			return "";
		}
		return userdata["response_data"].asString();
	}
	catch (const std::exception&)
	{
		return "";
	}
}


/*int SIDCpp::passwordCheck(std::string clientid, std::string sessid, std::string pw) {
	Json::FastWriter writer;
	Json::Value senddata;
	senddata["type"] = "verify";
	senddata["data"] = "password";
	senddata["clientid"] = clientid;
	senddata["sessid"] = sessid;
	senddata["value"] = pw;

	Json::Value userdata = this->curlPost("http://sid.donote.co:3000/api/password/verify", writer.write(senddata));
	if (userdata["type"].asCString() == "error")
		return 0;
	if (!userdata["is_vaild"].asBool()) {
		return 0;
	}
}*/

Json::Value SIDCpp::createClientID(std::string devicedata) {
	Json::Value senddata;
	Json::FastWriter writer;
	senddata["type"] = "create";
	senddata["data"] = "clientid";
	senddata["devicedata"] = devicedata;

	Json::Value received = this->curlPost("http://sid.donote.co:3000/api/clientid", writer.write(senddata));

	return received;
}