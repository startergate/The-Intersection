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
		if (it["platform"] == "steam") toRemove.push_back(it["tiid"]);

	for (auto const& it : toRemove)
		games_doc["games"].removeMember(it.c_str());



	for (Json::ValueIterator it = s_games.begin(); it != s_games.end(); it++)
	{
		char buffer[10];
		std::string gamedataROW = "{\"";
		gamedataROW.append(itoa(it["appid"].GetInt(), buffer, 10));
		gamedataROW.append("\": { \"tiid\": \"");
		gamedataROW.append(it["name"].GetString());
		gamedataROW.append("\",\"isInstalled\": ");
		gamedataROW.append("\"false\"");
		gamedataROW.append("\"addedTime\": 1530489600, \"playedTime\": ");
		gamedataROW.append(itoa(it->value["playtime_forever"].GetInt(), buffer, 10));
		gamedataROW.append(", \"platform\": \"steam\", \"additional\": {\"steamid\": ");
		gamedataROW.append(itoa(it->value["appid"].GetInt(), buffer, 10));
		gamedataROW.append("}}");
		rapidjson::Document gamedata(&new_games.GetAllocator());
		gamedata.Parse(gamedataROW.c_str());
		games.AddMember(itoa(it->value["appid"].GetInt(), buffer, 10), gamedata, new_games.GetAllocator());
		//new_games.AddMember(itoa(it->value["appid"].GetInt(), buffer, 10), gamedata, new_games.GetAllocator());
		//rapidjson::Value& tempvalue = temp;


		//games_doc.AddMember<rapidjson::Document>(it->value["appid"].GetString(), gamedata, games_doc.GetAllocator());
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