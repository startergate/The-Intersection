#pragma once

#include <stdlib.h>
#include <string>

class Game {
public:
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
	SteamGame(int gameid) {
		Game(gameid);

	}
	~SteamGame() = 0;
	void execute() {
		system("explorer steam://run/" << std::to_string(gameid) << "/");
	}
private:
	int steamid;
};