#include "LoadJson.h"

inline rapidjson::Document LoadJson::LoadLibrary() {
	std::ifstream jsondata("data/game.json");

	rapidjson::IStreamWrapper jsons(jsondata);
	rapidjson::Document data;

	data.ParseStream(jsons);
	return data;
}

inline rapidjson::Document LoadSteam() {
	rapidjson::Document userinfo = LoadJson::LoadUserData();


}

inline rapidjson::Document LoadUserData() {
	std::ifstream jsondata("data/user.json");

	rapidjson::IStreamWrapper jsons(jsondata);
	rapidjson::Document data;

	data.ParseStream(jsons);
	return data;
}
