#include "sid.h"

Json::Value SIDCpp::curlPost(std::string url, std::string data, std::string method) {
	CURL *curl = NULL;
	CURLcode res;

	int httpCode(0); // http 상태 코드를 받을 변수를 준비합니다.
	std::unique_ptr<std::string> httpData(new std::string()); // 수신된 데이터를 받을 변수를 준비합니다.

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl) {
		// curl request를 준비합니다.
		struct curl_slist *chunk = NULL;
		curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);

		// 헤더를 작성합니다.
		chunk = curl_slist_append(chunk, "Accept: application/json");
		chunk = curl_slist_append(chunk, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		//curl_easy_setopt(curl, CURLOPT_VERBOSE, true);

		// 통신을 실행합니다.
		res = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curl);
		Json::Value data;
		Json::Reader reader;
		// 수신한 문자열을 JSON document 형태로 리턴합니다.
		reader.parse(httpData.get()->c_str(), data);

		return data;
	}
	Json::Value error;
	error["error"] = 1;
	return error;
}

SIDCpp::SIDCpp(std::string clientName) {
	this->clientName = clientName; // 클라이언트 이름을 인수로 받습니다.
}

SIDCpp::~SIDCpp() {}

Json::Value SIDCpp::login(std::string clientid, std::string sessid) { // 로그인 1: 자동 로그인
	try
	{
		Json::FastWriter writer;
		Json::Value senddata;

		// request로 전송할 데이터를 준비합니다.
		senddata["type"] = "login";
		senddata["clientid"] = clientid;
		senddata["sessid"] = sessid;

		Json::Value userdata = this->curlPost("http://sid.donote.co:3000/api/session", writer.write(senddata)); // SID 서버와 통신합니다.
		if (userdata["type"].asCString() == "error")
		{
			throw new std::exception; // 서버와 통신한 결과 값을 검사합니다.
		}

		//수신한 데이터를 일정한 형식에 맞춰 리턴합니다.
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

Json::Value SIDCpp::login(std::string clientid, std::string id, std::string pw) { // 로그인 2: 직접 로그인
	Json::Value senddata;
	Json::FastWriter writer;

	// request로 전송할 데이터를 준비합니다.
	senddata["type"] = "login";
	senddata["clientid"] = clientid;
	senddata["userid"] = id;
	senddata["password"] = pw;

	Json::Value userdata = this->curlPost("http://sid.donote.co:3000/api/session", writer.write(senddata)); // SID 서버와 통신합니다.
	if (userdata["type"].asCString() == "error")
	{
		throw new std::exception; // 서버와 통신한 결과 값을 검사합니다.
	}

	// 수신한 데이터를 일정한 형식에 맞춰 리턴합니다.
	Json::Value output;
	output["sessid"] = userdata["response_data"][0].asCString();
	output["pid"] = userdata["response_data"][1].asCString();
	output["nickname"] = userdata["response_data"][2].asCString();
	output["expire"] = userdata["response_data"][3].asCString();
	return output;
}

int SIDCpp::logout(std::string clientid, std::string sessid) { // 로그아웃
	Json::Value senddata;
	Json::FastWriter writer;

	// request로 전송할 데이터를 준비합니다.
	senddata["type"] = "logout";
	senddata["clientid"] = clientid;
	senddata["sessid"] = sessid;

	Json::Value result = this->curlPost("http://sid.donote.co:3000/api/session", writer.write(senddata), "DELETE"); // SID 서버와 통신합니다.
	
	// 결과 값을 검사합니다.
	if (result["type"].asString().compare("error")) {
		return 0;
	}
	if (!result["is_succeed"].asBool()) {
		return 0;
	}

	return 1;
}

std::string SIDCpp::getUserNickname(std::string clientid, std::string sessid) { // 유저의 닉네임을 가져옵니다.
	// 통신할 URL을 준비합니다.
	std::string url = "http://sid.donote.co:3000/api/";
	url.append(clientid).append("/").append(sessid).append("/usname");
	try
	{
		Json::Value userdata = this->curlPost(url, "", "GET"); // SID 서버와 통신합니다/
		
		// 결과 값을 검사합니다.
		if (userdata["type"].asCString() == "error")
			return "";
		if (!userdata["is_vaild"].asBool()) {
			return "";
		}

		return userdata["response_data"].asString(); // 받아온 닉네임을 리턴합니다.
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

std::string SIDCpp::createClientID(std::string devicedata) { // 기기 고유 ID를 생성합니다.
	Json::Value senddata;
	Json::FastWriter writer;
	
	// request로 보낼 데이터를 준비합니다.
	senddata["type"] = "create";
	senddata["data"] = "clientid";
	senddata["devicedata"] = devicedata;

	Json::Value received = this->curlPost("http://sid.donote.co:3000/api/clientid", writer.write(senddata)); // SID 서버와 통신합니다.

	return received["response_data"].asCString(); // 기기 ID를 리턴합니다.
}