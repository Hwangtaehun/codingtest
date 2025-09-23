#include <iostream>

using namespace std;

void modify(int& value){
    value = 10;
    cout << "林家 " << &value << endl;
    cout << "蔼: " << value << endl;
}

int main()
{
    int value = 5;
    cout << "林家 : " << &value << endl;
    cout << "蔼 : " << value << endl;
    modify(value);
    cout << "蔼 : " << value << endl;

    return 0;
}
