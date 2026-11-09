#include "TV.hpp"

using namespace std;

TV::TV()
{
    cout << "TV 생성" << endl;
    size = 20;
}

TV::TV(int size)
{
    cout << "TV 생성" << endl;
    this->size = size;
}

int TV::getSize()
{
    return size;
}

void TV::setSize(int size) 
{
    this->size = size;
}

WideTV::WideTV(int size, bool videoIn) : TV(size)
{
    cout << "WideTV 생성" << endl;
    this->TV::size = size;
    this->videoIn = videoIn;
}

bool WideTV::getVideoIn()
{
    return videoIn;
}

void WideTV::setVideoIn(bool videoIn) {
    this->videoIn = videoIn;
}

SmartTV::SmartTV() : WideTV(20, true) {
    cout << "SmartTV 생성" << endl;
    ipAddr = "0.0.0.0";
}

SmartTV::SmartTV(string ipAddr, int size) : WideTV(size, true)
{
    cout << "SmartTV 생성" << endl;
    this->TV::size = size;
    this->ipAddr = ipAddr;
}

string SmartTV::getIpAddr()
{
    return ipAddr;
}

void SmartTV::setSmartTV(int size, bool videoIn, string ipAddr) {
    setSize(size);
    setVideoIn(videoIn);
    this->ipAddr = ipAddr;
}
