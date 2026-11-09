#include <string>

using namespace std;

class TV
{
    int size;

public:
    TV();
    TV(int size);
    int getSize();
};

class WideTV : public TV
{
    bool videoIn;

public:
    WideTV(int size, bool videoIn);
    bool getVideoIn();
};

class SmartTV : public WideTV
{
    string ipAddr;

public:
    SmartTV(string ipAddr, int size);
    string getIpAddr();
};
