#include "origin.hpp"
#include <Winsock2.h>

int main()
{
    //2020-11-02 15:46:04
    char *p = nullptr;
    printf("%d", p);
    printf("%d," * p);

    //test
    //char *p = "ABCD";
    //char c = static_cast<char>(*p);
    //cout << c << endl;

    //2020-10-26 15:18:45大端小端
    unsigned long *a = 0;
    cout << a << endl;
    cout << &a << endl;
    //cout << *a << endl;
    a++;
    cout << a << endl;

    int b = 0x12345678;
    cout << hex << b << endl;
    int c = htonl(b);
    cout << hex << c << endl;
    system("pause");
}