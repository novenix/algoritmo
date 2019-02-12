#include <stdio.h>
#include <iostream>
using namespace std;
using std::cout;


int main()
{
    int a = 339;

    char b = a;

    char c = 'c';

    int d = (int)b;

    int e = a & 0xff;

    cout << a << " " << b << " " << c << " " << d << " " << e << std::endl;
}
