#include "TV.hpp"

using namespace std;

TV::TV()
{
    size = 20;
}

TV::TV(int size)
{
    this->size = size;
}

int TV::getSize()
{
    return size;
}

WideTV::WideTV(int size, bool videoIn) : TV(size)
{
    this->videoIn = videoIn;
}

bool WideTV::getVideoIn()
{
    return videoIn;
}

SmartTV::SmartTV(string ipAddr, int size) : WideTV(size, true)
{
    this->ipAddr = ipAddr;
}

string SmartTV::getIpAddr()
{
    return ipAddr;
}
