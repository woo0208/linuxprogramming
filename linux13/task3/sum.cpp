#include <iostream>
#include "sum.hpp"
using namespace std;
void Adder::input()
{
    cout << "Input:";
    cin >> a;
    cout << "Input:";
    cin >> b;
}
void Adder::add() { sum = a + b; }
void Adder::print()
{
    cout << "sum:" << sum << endl;
}
