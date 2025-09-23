#include <iostream>

using namespace std;

int main()
{
    string str = "Hello, C++ World!";

    int pos1 = str.find("Hello");
    cout << pos1 << endl;

    int pos2 = str.find('C');
    cout << pos2 << endl;

    size_t start_index = 2;
    size_t pos3 = str.find("Hello", start_index);
    cout << pos3 << endl;

    size_t pos4 = str.find("Python");
    cout << pos4 << endl;

    return 0;
}
