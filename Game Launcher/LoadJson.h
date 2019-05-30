#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <curl/curl.h>
#include <string>
#include <memory>

class LoadJson {
public:
	static inline rapidjson::Document LoadLibrary();
	static inline rapidjson::Document LoadSteam();
	static inline rapidjson::Document LoadUserData();
};