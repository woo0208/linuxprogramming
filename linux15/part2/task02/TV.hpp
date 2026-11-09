#include <string>
#include <iostream>
using namespace std;

class TV
{
protected:
    int size;

public:
    TV();
    TV(int size);
    int getSize();
    void setSize(int size);
};

class WideTV : public TV
{
    bool videoIn;

public:
    WideTV(int size, bool videoIn);
    bool getVideoIn();
    void setVideoIn(bool videoIn);
};

class SmartTV : public WideTV
{
    string ipAddr;

public:
    SmartTV();
    SmartTV(string ipAddr, int size);
    string getIpAddr();
    void setSmartTV(int size, bool videoIn, string ipAddr);
};

