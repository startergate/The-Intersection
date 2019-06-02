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
	LoadJson* lj = new LoadJson;
	rapidjson::Document games_doc = lj->LoadLibraryW();
	//rapidjson::Document steamgames = lj->LoadSteam();
	//rapidjson::Document new_game_doc;

	rapidjson::Value& games = games_doc["games"];
	/*rapidjson::Value& s_games = steamgames["response"]["games"];
	std::list<std::string> toRemove;

	for (rapidjson::Value::ConstMemberIterator it = games.MemberBegin(); it != games.MemberEnd(); it++)
		if (it->value["platform"].GetString() == "steam") toRemove.push_back(it->value["tiid"].GetString());

	for (auto const& it : toRemove)
		games_doc["games"].EraseMember(it.c_str());



	for (rapidjson::Value::ConstMemberIterator it = s_games.MemberBegin(); it != s_games.MemberEnd(); it++)
	{
		rapidjson::Document gamedata;
		//gamedata.append(it->value["appid"].GetString());
		//gamedata.append("\": { \"tiid\": \"");
		//gamedata.append(it->value["name"].GetString());

		//rapidjson::Value& tempvalue = temp;


		//games_doc.AddMember<rapidjson::Document>(it->value["appid"].GetString(), gamedata, games_doc.GetAllocator());
	}*/

	for (rapidjson::Value::ConstMemberIterator it = games.MemberBegin(); it != games.MemberEnd(); it++)
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