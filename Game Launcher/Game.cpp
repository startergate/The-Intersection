#include <Game.h>

Game::Game(int gameid) {
	this->gameid = gameid; // 게임의 고유 ID를 인수로 받습니다.
}

Game::~Game() {}

void Game::execute() {
	std::string executeable = "";
	system(executeable.c_str());
}

Json::Value Game::GameListGenerate() {
	Json::Value games_docs;
	LoadJson* lj = new LoadJson;
	Json::Value games_doc = lj->LoadLibraryW(); // 게임 라이브러리 파일을 로드합니다.
	Json::Value user = lj->LoadUserData(); // 유저 정보 파일을 로드합니다.
	Json::Value steamgames = lj->LoadSteam(); // 스팀 라이브러리를 로드합니다.
	Json::Value new_game_doc;
	Json::Value new_games;

	Json::Value& games = games_doc["games"];
	Json::Value& s_games = steamgames["response"]["games"];
	std::list<std::string> toRemove;

	for (Json::ValueIterator it = games.begin(); it != games.end(); it++) if (!(*it)["platform"].asString().compare("steam")) toRemove.push_back((*it)["tiid"].asCString()); // 플랫폼이 스팀인 게임들을 찾습니다.
	for (auto const& it : toRemove) games_doc["games"].removeMember(it.c_str()); // 플랫폼이 스팀인 게임들을 삭제합니다.

	for (Json::ValueIterator it = s_games.begin(); it != s_games.end(); it++)
	{
		char buffer[10];
		Json::Value gamedata;

		// 스팀 API로부터 받은 데이터에서 데이터를 추출합니다.
		gamedata["tiid"] = itoa((*it)["appid"].asInt(), buffer, 10);
		gamedata["name"] = (*it)["name"].asCString();
		gamedata["isInstalled"] = "false";
		gamedata["addedTime"] = 1530489600;
		gamedata["playedTime"] = (*it)["playtime_forever"].asInt();
		gamedata["platform"] = "steam";
		gamedata["additional"]["steamid"] = (*it)["appid"].asInt();

		// 추출한 데이터를 게임 라이브러리 객체에 넣습니다.
		games_doc["games"][itoa((*it)["appid"].asInt(), buffer, 10)] = gamedata;
	}

	std::ofstream data;
	data.open("data/game.json");

	data << games_doc; // 게임 라이브러리 객체를 파일로 저장합니다.

	lj->UploadLibrary(user["sid"]["pid"].asString(), games_doc); // 게임 라이브러리를 서버로 업로드합니다. 백업의 역할을 합니다.

	return games_doc; // 게임 라이브러리를 리턴합니다.
}

SteamGame::SteamGame(int gameid, int steamid) : Game(gameid) {
	this->steamid = steamid; // 스팀 게임에 한해서 steamid 인수를 추가로 받습니다.
}

SteamGame::~SteamGame() {}

void SteamGame::execute() {
	// 스팀 실행 명령어를 만듭니다.
	std::string executeable = "explorer steam://run/";
	executeable += std::to_string(steamid);
	executeable.append("/");

	system(executeable.c_str()); // 명령어를 실행합니다.
}