#include <iostream>
#include <map>

using namespace std;

template <typename T>

void Print(T Map){
    for(const auto& pair : Map) {
        cout << pair.first << " = " << pair.second << " ";
    }
    cout << endl;
}

int main()
{
    map<string, double> employeeSalaries;

    map<string, double> studentGrades = {
        {"john", 3.7},
        {"Emma", 3.9},
        {"Sophia", 4.0}
    };

    Print(studentGrades);

    return 0;
}
