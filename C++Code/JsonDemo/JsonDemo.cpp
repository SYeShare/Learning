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

        j["sex"] = std::to_string(3).c_str();

        string strsex = j.value("sex", "0");
        cout << strsex << endl;

        //json子串后加结构体等数据会导致序列化失败
        char jsonbuff[200] = {0};
        string str = "{\"ip\": \"172.16.179.144\", \"type\" : \"MCU_CM_SIMCONFINFO_NTF\"}est";
        strncpy(jsonbuff, str.c_str(), str.length());
        //json tmp = json::parse(str.c_str());
        cout << str.length() << endl;
        cout << json::parse(str.c_str(), str.c_str() + 59).dump(4) << endl;
        MyTp my;
        memcpy(jsonbuff + str.length(), (char *)&my, sizeof(MyTp));
        //cout << json::parse(jsonbuff).dump(4) << endl;

        json a;
        json b;
        json c;
        c["name"] = 1;
        c["sex"] = 2;
        b["a"].push_back(c);

        c["name"] = 3;
        c["sex"] = 4;
        b["a"].push_back(c);
        cout << b.dump(4) << endl;

        json e;
        e["ip"] = nullptr;

        cout << e.dump(4) << endl;

        //取值
        cout << b["a"].size() << endl;

        for (json::iterator j = b["a"].begin(); j != b["a"].end(); j++)
        {
            //cout << j.dump() << endl;
        }
        //json构造数组数据
        //        json jarray;
        //        jarray["speaker"] = "{{\"mt\": 4, \"mtno\":\"ss\"}, {\"mt\": 5, \"mtno\": \"ll\"}}"_json;

        //        cout << jarray.dump(4) << endl;

        //        string mtid = jarray["speaker"]["mt"].get<string>();
        //        cout << mtid << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    system("pause");
}