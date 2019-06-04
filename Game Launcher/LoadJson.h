#pragma once

#pragma comment(lib, "wldap32.lib" )
#pragma comment(lib, "crypt32.lib" )
#pragma comment(lib, "Ws2_32.lib")

#include <fstream>
#include <json/json.h>
#include <curl/curl.h>
#include <string>
#include <memory>

class LoadJson {
public:
	Json::Value LoadLibraryW();
	Json::Value LoadSteam();
	Json::Value LoadUserData();
};