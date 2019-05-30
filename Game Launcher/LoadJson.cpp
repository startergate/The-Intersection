#include "LoadJson.h"

rapidjson::Document LoadJson::LoadLibrary() {
	std::ifstream jsondata("data/game.json");

	rapidjson::IStreamWrapper jsons(jsondata);
	rapidjson::Document data;

	data.ParseStream(jsons);
	return data;
}