#include "LoadJson.h"

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


rapidjson::Document LoadJson::LoadLibrary() {
	std::ifstream jsondata("data/game.json");

	rapidjson::IStreamWrapper jsons(jsondata);
	rapidjson::Document data;

	data.ParseStream(jsons);
	return data;
}

/*rapidjson::Document LoadJson::LoadSteam() {
	rapidjson::Document userinfo = this->LoadUserData();

	std::string steamid64 = userinfo["steamid64"].GetString();
	CURL *curl;
	CURLcode res;

	int httpCode(0);
	std::unique_ptr<std::string> httpData(new std::string());

	std::string targetUrl = "http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key=B6137C92F67299965B5E6BF287ECA4AE&format=json&include_appinfo=1&steamid=";
	targetUrl += steamid64;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, targetUrl);
		
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

		curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
		
		curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curl);

		if (httpCode == 200)
		{
			rapidjson::Document steamgames;
			steamgames.Parse(httpData.get()->c_str());

			return steamgames;
		}
	}
	rapidjson::Document error;
	error.Parse("{\"error\": 1}");
	return error;
}*/

rapidjson::Document LoadJson::LoadUserData() {
	std::ifstream jsondata("data/user.json");

	rapidjson::IStreamWrapper jsons(jsondata);
	rapidjson::Document data;

	data.ParseStream(jsons);
	return data;
}
