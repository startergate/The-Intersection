#include "LoadJson.h"
#include "json/reader.h"
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


Json::Value LoadJson::LoadLibrary() {
	std::ifstream jsondata("data/game.json");
	Json::Value data;
	Json::Reader reader;
	reader.parse(jsondata, data, false);
	return data;
}

Json::Value LoadJson::LoadSteam() {
	Json::Value userinfo = this->LoadUserData();

	std::string steamid64 = userinfo["steamid64"].asCString();
	CURL *curl = NULL;
	CURLcode res;

	int httpCode(0);
	std::unique_ptr<std::string> httpData(new std::string());

	std::string targetUrl("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key=B6137C92F67299965B5E6BF287ECA4AE&format=json&include_appinfo=1&steamid=");
	targetUrl += steamid64;
	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, targetUrl.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
		res = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curl);
		if (httpCode == 200)
		{
			Json::Value steamgames;
			Json::Reader reader;
			reader.parse(httpData.get()->c_str(), steamgames);

			return steamgames;
		}
	}
	Json::Value error;
	error["error"] = 1;
	return error;
}

Json::Value LoadJson::LoadUserData() {
	std::ifstream jsondata("data/user.json");

	Json::Value data;

	jsondata >> data;
	return data;
}

Json::Value LoadJson::LoadLibraryOn(std::string pid) {
	std::string url = "http://localhost:3000/api/";
	url += pid;
	
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
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);

		//chunk = curl_slist_append(chunk, "Accept: application/json");
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
}

void LoadJson::UploadLibrary(std::string pid, Json::Value library) {
	Json::StyledWriter writer;
	std::string url = "http://localhost:3000/api/";
	Json::Value senddata;
	senddata["data"] = writer.write(library);
	url += pid;
	CURL *curl = NULL;
	CURLcode res;

	int httpCode(0);
	std::unique_ptr<std::string> httpData(new std::string());

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	OutputDebugStringA(writer.write(senddata).c_str());
	if (curl) {
		struct curl_slist *chunk = NULL;
		curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, writer.write(senddata));
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, senddata.size());
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);

		//chunk = curl_slist_append(chunk, "Accept: application/json");
		chunk = curl_slist_append(chunk, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		//curl_easy_setopt(curl, CURLOPT_VERBOSE, true);

		res = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curl);
	}
}

void LoadJson::Save(std::string route, Json::Value value) {
	Json::StyledWriter writer;
	std::ofstream data1;
	data1.open(route);
	OutputDebugStringA(route.c_str());
	OutputDebugStringA(writer.write(value).c_str());
	data1 << writer.write(value).c_str();
}