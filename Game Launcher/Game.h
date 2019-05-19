#pragma once

#include <stdlib.h>
#include <string>

class Game {
public:
	Game() = default;
	Game(int gameid) {
		this->gameid = gameid;
	}
	virtual ~Game();
	virtual void execute();
protected:
	int gameid;
};

class SteamGame : public Game {
public:
	SteamGame(int gameid, int steamid) {
		Game(gameid);

	}
	~SteamGame() = 0;
	virtual void execute() {
		std::string executeable = "explorer steam://run/";
		executeable += std::to_string(steamid);
		executeable.append("/");
		const char * c = executeable.c_str();
		system(c);
	}
private:
	int steamid;
};