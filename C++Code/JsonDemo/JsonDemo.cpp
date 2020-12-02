#include "json.hpp"
#include <string>
#include <iostream>
using json = nlohmann::json;
using namespace std;

class MyTp
{
private:
    int m_i;
};

int main()
{
    try
    {
        //cin
        json j;
        j["mt"] = 1;
        j["mtno"] = "zhang";

        json jtmp;
        jtmp["speaker"] = j;

        j["mt"] = "2";
        j["mtno"] = "li";
        jtmp["chairman"] = j;

        j["mt"] = 3;
        j["mtno"] = "su";

        char jsonbuff[200] = {0};
        string str = "{\"ip\": \"172.16.179.144\", \"type\" : \"MCU_CM_SIMCONFINFO_NTF\"}";
        strncpy(jsonbuff, str.c_str(), str.length());

        //json tmp = json::parse(str.c_str());
        cout << json::parse(str.c_str()).dump(4) << endl;

        MyTp my;
        memcpy(jsonbuff + str.length(), (char *)&my, sizeof(MyTp));

        cout << json::parse(jsonbuff).dump(4) << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    system("pause");
}