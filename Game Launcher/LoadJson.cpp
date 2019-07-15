#include "LoadJson.h"
#include "json/reader.h"
namespace
{
	std::size_t callback(
		const char* in,
		std::size_t size,
		std::size_t num,
		std::string* out)
	{
		const std::size_t totalBytes(size * num);
		out->append(in, totalBytes);
		return totalBytes;
	}
}


Json::Value LoadJson::LoadLibrary() {
	std::ifstream jsondata("data/game.json"); // ���� ���̺귯�� ���ϰ��� ��Ʈ���� ����ϴ�.
	Json::Value data;
	Json::Reader reader;
	reader.parse(jsondata, data, false); // �޾ƿ� ������ json ��ü�� ����ϴ�.
	return data; // ��ü�� �����մϴ�.
}

Json::Value LoadJson::LoadSteam() {
	Json::Value userinfo = this->LoadUserData(); // ���� ���� ������ �����ɴϴ�.

	std::string steamid64 = userinfo["steamid64"].asCString();
	CURL *curl = NULL;
	CURLcode res;

	int httpCode(0);
	std::unique_ptr<std::string> httpData(new std::string());

	// ���� API ��ũ�� �غ��մϴ�.
	std::string targetUrl("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key=B6137C92F67299965B5E6BF287ECA4AE&format=json&include_appinfo=1&steamid=");
	targetUrl += steamid64;
	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl) {
		// curl request�� �غ��մϴ�.
		curl_easy_setopt(curl, CURLOPT_URL, targetUrl.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
		res = curl_easy_perform(curl); // request�� �����մϴ�.
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curl);
		if (httpCode == 200)
		{
			Json::Value steamgames;
			Json::Reader reader;
			reader.parse(httpData.get()->c_str(), steamgames); // �޾ƿ� �����͸� json ��ü�� ����ϴ�.

			return steamgames;
		}
	}
	Json::Value error;
	error["error"] = 1;
	return error;
}

Json::Value LoadJson::LoadUserData() {
	std::ifstream jsondata("data/user.json"); // ���� �����Ϳ��� ���� ��Ʈ���� ����ϴ�.

	Json::Value data;

	jsondata >> data; // ������ ������ json ��ü�� �ֽ��ϴ�.
	return data;
}

Json::Value LoadJson::LoadLibraryOn(std::string pid) {
	// The Intersection �������� ����� ���� url�� ����ϴ�.
	std::string url = "http://localhost:3000/api/";
	url += pid;

	CURL *curl = NULL;
	CURLcode res;

	int httpCode(0);
	std::unique_ptr<std::string> httpData(new std::string());

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl) {
		// curl request�� �غ��մϴ�.
		struct curl_slist *chunk = NULL;
		curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);

		// ����� �غ��մϴ�.
		//chunk = curl_slist_append(chunk, "Accept: application/json");
		chunk = curl_slist_append(chunk, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		//curl_easy_setopt(curl, CURLOPT_VERBOSE, true);

		// request�� �����մϴ�.
		res = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curl);
		Json::Value data;
		Json::Reader reader;
		reader.parse(httpData.get()->c_str(), data); // �޾ƿ� �����͸� json ��ü�� ����ϴ�.

		return data; // ��ü�� �����մϴ�.
	}
}

void LoadJson::UploadLibrary(std::string pid, Json::Value library) {
	Json::StyledWriter writer;

	// The Intersection �������� ����� ���� url�� ����ϴ�.
	std::string url = "http://localhost:3000/api/";
	url += pid;

	// ���� �����͸� �غ��մϴ�.
	Json::Value senddata;
	senddata["data"] = writer.write(library);
	CURL *curl = NULL;
	CURLcode res;

	int httpCode(0);
	std::unique_ptr<std::string> httpData(new std::string());

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl) {
		// curl request�� �غ��մϴ�.
		struct curl_slist *chunk = NULL;
		curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, writer.write(senddata)); // request �����͸� �ֽ��ϴ�.
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, senddata.size());
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);

		// ����� �غ��մϴ�.
		//chunk = curl_slist_append(chunk, "Accept: application/json");
		chunk = curl_slist_append(chunk, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		//curl_easy_setopt(curl, CURLOPT_VERBOSE, true);

		// request�� �����մϴ�.
		res = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
		curl_easy_cleanup(curl);
	}
}

void LoadJson::Save(std::string route, Json::Value value) { // �μ��� ���� Json::Value�� route�� �����մϴ�.
	Json::StyledWriter writer;
	std::ofstream data1;
	data1.open(route);
	data1 << writer.write(value).c_str();
}