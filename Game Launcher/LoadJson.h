#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <curl>

class LoadJson {
public:
	static inline rapidjson::Document LoadLibrary();
	static inline rapidjson::Document LoadSteam();
	static inline rapidjson::Document LoadUserData();
};