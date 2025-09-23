#include <iostream>

using namespace std;

int main()
{
    int i = 65;
    float f = 5.2f;

    double d = i + f;
    cout << d << endl;
    cout << static_cast<int>(d) << endl;
    cout << static_cast<char>(i) << endl;

    return 0;
}
