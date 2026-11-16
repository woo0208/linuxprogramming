#include "Box.hpp"

int main()
{
    Box<int> intBox(100);
    std::cout << "정수상자: " << intBox.getValue() << "\n";
    Box<double> doubleBox(3.14);
    std::cout << "실수상자: " << doubleBox.getValue() << "\n";
    Box<std::string> strBox("안녕하세요");
    std::cout << "문자열상자: " << strBox.getValue() << "\n";
    strBox.setValue("템플릿기초완료!");
    std::cout << "변경된문자열상자: " << strBox.getValue() << "\n";
    return 0;
}
