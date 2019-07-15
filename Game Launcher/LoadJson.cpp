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
    std::ifstream jsondata("data/game.json"); // 게임 라이브러리 파일과의 스트림을 만듭니다.
    Json::Value data;
    Json::Reader reader;
    reader.parse(jsondata, data, false); // 받아온 파일을 json 객체로 만듭니다.
    return data; // 객체를 리턴합니다.
}

Json::Value LoadJson::LoadSteam() {
    Json::Value userinfo = this->LoadUserData(); // 유저 정보 파일을 가져옵니다.

    std::string steamid64 = userinfo["steamid64"].asCString();
    CURL *curl = NULL;
    CURLcode res;

    int httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());

    // 스팀 API 링크를 준비합니다.
    std::string targetUrl("http://api.steampowered.com/IPlayerService/GetOwnedGames/v0001/?key=B6137C92F67299965B5E6BF287ECA4AE&format=json&include_appinfo=1&steamid=");
    targetUrl += steamid64;
    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl) {
        // curl request를 준비합니다.
        curl_easy_setopt(curl, CURLOPT_URL, targetUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
        res = curl_easy_perform(curl); // request를 실행합니다.
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
        curl_easy_cleanup(curl);
        if (httpCode == 200)
        {
            Json::Value steamgames;
            Json::Reader reader;
            reader.parse(httpData.get()->c_str(), steamgames); // 받아온 데이터를 json 객체로 만듭니다.

            return steamgames;
        }
    }
    Json::Value error;
    error["error"] = 1;
    return error;
}

Json::Value LoadJson::LoadUserData() {
    std::ifstream jsondata("data/user.json"); // 유저 데이터와의 파일 스트림을 만듭니다.

    Json::Value data;

    jsondata >> data; // 파일을 가져와 json 객체에 넣습니다.
    return data;
}

Json::Value LoadJson::LoadLibraryOn(std::string pid) {
    // The Intersection 서버와의 통신을 위한 url을 만듭니다.
    std::string url = "http://localhost:3000/api/";
    url += pid;

    CURL *curl = NULL;
    CURLcode res;

    int httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl) {
        // curl request를 준비합니다.
        struct curl_slist *chunk = NULL;
        curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);

        // 헤더를 준비합니다.
        //chunk = curl_slist_append(chunk, "Accept: application/json");
        chunk = curl_slist_append(chunk, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        //curl_easy_setopt(curl, CURLOPT_VERBOSE, true);

        // request를 실행합니다.
        res = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
        curl_easy_cleanup(curl);
        Json::Value data;
        Json::Reader reader;
        reader.parse(httpData.get()->c_str(), data); // 받아온 데이터를 json 객체로 만듭니다.

        return data; // 객체를 리턴합니다.
    }
}

void LoadJson::UploadLibrary(std::string pid, Json::Value library) {
    Json::StyledWriter writer;

    // The Intersection 서버와의 통신을 위한 url을 만듭니다.
    std::string url = "http://localhost:3000/api/";
    url += pid;

    // 보낼 데이터를 준비합니다.
    Json::Value senddata;
    senddata["data"] = writer.write(library);
    CURL *curl = NULL;
    CURLcode res;

    int httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl) {
        // curl request를 준비합니다.
        struct curl_slist *chunk = NULL;
        curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, writer.write(senddata)); // request 데이터를 넣습니다.
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE_LARGE, senddata.size());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);

        // 헤더를 준비합니다.
        //chunk = curl_slist_append(chunk, "Accept: application/json");
        chunk = curl_slist_append(chunk, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
        //curl_easy_setopt(curl, CURLOPT_VERBOSE, true);

        // request를 실행합니다.
        res = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
        curl_easy_cleanup(curl);
    }
}

void LoadJson::Save(std::string route, Json::Value value) { // 인수로 받은 Json::Value를 route에 저장합니다.
    Json::StyledWriter writer;
    std::ofstream data1;
    data1.open(route);
    data1 << writer.write(value).c_str();
}