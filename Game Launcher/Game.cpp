#include <Game.h>

Game::Game(int gameid) {
	this->gameid = gameid;
}

Game::~Game() {}

void Game::execute() {
	std::string executeable = "";
	system(executeable.c_str());
}

void Game::GameListGenerate() {
	rapidjson::Document games_doc = LoadJson::LoadLibrary();
	rapidjson::Document steamgames = LoadJson::LoadSteam();

	rapidjson::Value& games = games_doc["games"];
	rapidjson::Value& s_games = steamgames["response"]["games"];

	for (rapidjson::Value::ConstMemberIterator it = games.MemberBegin(); it != games.MemberEnd(); it++)
	{
		if (it->value["platform"].GetString() == "steam")
		{
			it->value.
		}
	}

	for (rapidjson::Value::ConstMemberIterator it = s_games.MemberBegin(); it != s_games.MemberEnd(); it++)
	{

	}
}

SteamGame::SteamGame(int gameid, int steamid) : Game(gameid) {
	this->steamid = steamid;
}

SteamGame::~SteamGame() {}

void SteamGame::execute() {
	std::string executeable = "explorer steam://run/";
	executeable += std::to_string(steamid);
	executeable.append("/");
	system(executeable.c_str());
}