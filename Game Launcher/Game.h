#pragma once

#pragma comment (lib, "lib_json.lib")

#include <stdlib.h>
#include <string>
#include <list>
#include <LoadJson.h>
#include "json/json.h"

class Game {
public:
	Game(int gameid);
	virtual ~Game();
	void virtual execute();
	Json::Value GameListGenerate(void);
protected:
	int gameid;
};

class SteamGame : public Game {
public:
	SteamGame(int gameid, int steamid);
	~SteamGame();
	void execute();
private:
	int steamid;
};