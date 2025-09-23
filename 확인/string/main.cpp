#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1;
    string str2 = "Hello, World!";
    string str3(str2);
    string str4(str2, 0, 5);
    string str5(10, '*');

    cout << str1 << "\n" << str2 << "\n" << str3 << "\n" << str4 << "\n" << str5 << endl;

    return 0;
}
