
#include <iostream>
#include <stdio.h>
#include "TV.hpp"


using namespace std;

int main()
{
    // 32 인치 크기에 "192.0.0.1"의 인터넷 주소를 가지는 스마트 TV 객체 생성
    SmartTV htv;
    htv.setSmartTV(50,false,"192.0.0.2");
    cout << "size=" << htv.getSize() << endl;
    cout << "videoIn=" << boolalpha << htv.getVideoIn() << endl;
    cout << "IP=" << htv.getIpAddr() << endl;
    
}
