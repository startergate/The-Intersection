#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

class LoadJson {
public:
	static inline rapidjson::Document LoadLibrary();
};