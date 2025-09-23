#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "APPLE";
    str += ", World!";
    cout << str << endl;

    str[7] = 'P';
    cout << str << endl;

    str.replace(7, 4, "Col");
    cout << str << endl;

    return 0;
}
