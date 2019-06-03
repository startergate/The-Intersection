#include <Game.h>

Game::Game(int gameid) {
	this->gameid = gameid;
}

Game::~Game() {}

void Game::execute() {
	std::string executeable = "";
	system(executeable.c_str());
}

rapidjson::Document Game::GameListGenerate() {
	Json::Value games_docs;
	LoadJson* lj = new LoadJson;
	rapidjson::Document games_doc = lj->LoadLibraryW();
	rapidjson::Document steamgames = lj->LoadSteam();
	rapidjson::Document new_game_doc;
	rapidjson::Document new_games;

	rapidjson::Value& games = games_doc["games"];
	rapidjson::Value& s_games = steamgames["response"]["games"];
	std::list<std::string> toRemove;

	for (rapidjson::Value::ConstMemberIterator it = games.MemberBegin(); it != games.MemberEnd(); it++)
		if (it->value["platform"].GetString() == "steam") toRemove.push_back(it->value["tiid"].GetString());

	for (auto const& it : toRemove)
		games_doc["games"].EraseMember(it.c_str());



	for (rapidjson::Value::ConstMemberIterator it = s_games.MemberBegin(); it != s_games.MemberEnd(); it++)
	{
		char buffer[10];
		std::string gamedataROW = "{\"";
		gamedataROW.append(itoa(it->value["appid"].GetInt(), buffer, 10));
		gamedataROW.append("\": { \"tiid\": \"");
		gamedataROW.append(it->value["name"].GetString());
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