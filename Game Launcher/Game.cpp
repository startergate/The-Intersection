#include <Game.h>

Game::Game(int gameid) {
	this->gameid = gameid;
}

Game::~Game() {}

void Game::execute() {
	std::string executeable = "";
	system(executeable.c_str());
}

Json::Value Game::GameListGenerate() {
	Json::Value games_docs;
	LoadJson* lj = new LoadJson;
	Json::Value games_doc = lj->LoadLibraryW();
	Json::Value steamgames = lj->LoadSteam();
	Json::Value new_game_doc;
	Json::Value new_games;

	Json::Value& games = games_doc["games"];
	Json::Value& s_games = steamgames["response"]["games"];
	std::list<std::string> toRemove;

	for (Json::ValueIterator it = games.begin(); it != games.end(); it++)
		if ((*it)["platform"] == "steam") toRemove.push_back((*it)["tiid"].asCString());

	for (auto const& it : toRemove)
		games_doc["games"].removeMember(it.c_str());



	for (Json::ValueIterator it = s_games.begin(); it != s_games.end(); it++)
	{
		char buffer[10];
		Json::Value gamedata;
		gamedata["tiid"] = itoa((*it)["appid"].asInt(), buffer, 10);
		gamedata["name"] = (*it)["name"].asCString();
		gamedata["isInstalled"] = "false";
		gamedata["addedTime"] = 1530489600;
		gamedata["playedTime"] = (*it)["playtime_forever"].asInt();
		gamedata["platform"] = "steam";
		gamedata["additional"]["steamid"] = (*it)["appid"].asInt();
		games[itoa((*it)["appid"].asInt(), buffer, 10)] = gamedata;
	}

	return games_doc;
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