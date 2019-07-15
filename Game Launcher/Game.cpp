#include <Game.h>

Game::Game(int gameid) {
    this->gameid = gameid; // ê²Œì„??ê³ ìœ  IDë¥??¸ìˆ˜ë¡?ë°›ìŠµ?ˆë‹¤.
}

Game::~Game() {}

void Game::execute() {
    std::string executeable = "";
    system(executeable.c_str());
}

Json::Value Game::GameListGenerate() {
    Json::Value games_docs;
    LoadJson* lj = new LoadJson;
    Json::Value games_doc = lj->LoadLibraryW(); // ê²Œì„ ?¼ì´ë¸ŒëŸ¬ë¦??Œì¼??ë¡œë“œ?©ë‹ˆ??
    Json::Value user = lj->LoadUserData(); // ? ì? ?•ë³´ ?Œì¼??ë¡œë“œ?©ë‹ˆ??
    Json::Value steamgames = lj->LoadSteam(); // ?¤í? ?¼ì´ë¸ŒëŸ¬ë¦¬ë? ë¡œë“œ?©ë‹ˆ??
    Json::Value new_game_doc;
    Json::Value new_games;

    Json::Value& games = games_doc["games"];
    Json::Value& s_games = steamgames["response"]["games"];
    std::list<std::string> toRemove;

    for (Json::ValueIterator it = games.begin(); it != games.end(); it++) if (!(*it)["platform"].asString().compare("steam")) toRemove.push_back((*it)["tiid"].asCString()); // ?Œë«?¼ì´ ?¤í???ê²Œì„?¤ì„ ì°¾ìŠµ?ˆë‹¤.
    for (auto const& it : toRemove) games_doc["games"].removeMember(it.c_str()); // ?Œë«?¼ì´ ?¤í???ê²Œì„?¤ì„ ?? œ?©ë‹ˆ??

    for (Json::ValueIterator it = s_games.begin(); it != s_games.end(); it++)
    {
        char buffer[10];
        Json::Value gamedata;

        // ?¤í? APIë¡œë???ë°›ì? ?°ì´?°ì—???°ì´?°ë? ì¶”ì¶œ?©ë‹ˆ??
        gamedata["tiid"] = itoa((*it)["appid"].asInt(), buffer, 10);
        gamedata["name"] = (*it)["name"].asCString();
        gamedata["isInstalled"] = "false";
        gamedata["addedTime"] = 1530489600;
        gamedata["playedTime"] = (*it)["playtime_forever"].asInt();
        gamedata["platform"] = "steam";
        gamedata["additional"]["steamid"] = (*it)["appid"].asInt();

        // ì¶”ì¶œ???°ì´?°ë? ê²Œì„ ?¼ì´ë¸ŒëŸ¬ë¦?ê°ì²´???£ìŠµ?ˆë‹¤.
        games_doc["games"][itoa((*it)["appid"].asInt(), buffer, 10)] = gamedata;
    }

    std::ofstream data;
    data.open("data/game.json");

    data << games_doc; // ê²Œì„ ?¼ì´ë¸ŒëŸ¬ë¦?ê°ì²´ë¥??Œì¼ë¡????¥í•©?ˆë‹¤.

    lj->UploadLibrary(user["sid"]["pid"].asString(), games_doc); // ê²Œì„ ?¼ì´ë¸ŒëŸ¬ë¦¬ë? ?œë²„ë¡??…ë¡œ?œí•©?ˆë‹¤. ë°±ì—…????• ???©ë‹ˆ??

    return games_doc; // ê²Œì„ ?¼ì´ë¸ŒëŸ¬ë¦¬ë? ë¦¬í„´?©ë‹ˆ??
}

SteamGame::SteamGame(int gameid, int steamid) : Game(gameid) {
    this->steamid = steamid; // ?¤í? ê²Œì„???œí•´??steamid ?¸ìˆ˜ë¥?ì¶”ê?ë¡?ë°›ìŠµ?ˆë‹¤.
}

SteamGame::~SteamGame() {}

void SteamGame::execute() {
    // ?¤í? ?¤í–‰ ëª…ë ¹?´ë? ë§Œë“­?ˆë‹¤.
    std::string executeable = "explorer steam://run/";
    executeable += std::to_string(steamid);
    executeable.append("/");

    system(executeable.c_str()); // ëª…ë ¹?´ë? ?¤í–‰?©ë‹ˆ??
}