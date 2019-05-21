#pragma once

#include <stdlib.h>
#include <string>

class Game {
public:
	Game() = default;
	Game(int gameid) {
		this->gameid = gameid;
	}
	virtual ~Game() {};
	void virtual execute() {};
protected:
	int gameid;
};

class SteamGame : public Game {
public:
	SteamGame(int gameid, int steamid) : Game(gameid) {
		this->steamid = steamid;
	}
	~SteamGame() {};
	void execute() {
		std::string executeable = "explorer steam://run/";
		executeable += std::to_string(steamid);
		executeable.append("/");
		const char * c = executeable.c_str();
		system(c);
	}
private:
	int steamid;
};