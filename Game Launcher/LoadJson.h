#pragma once

#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <curl/curl.h>
#include <string>
#include <memory>

class LoadJson {
public:
	rapidjson::Document LoadLibrary();
	rapidjson::Document LoadSteam();
	rapidjson::Document LoadUserData();
};