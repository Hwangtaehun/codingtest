#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

vector<int> g_data;

void Input(){
    string m_str;

    ifstream in("input.txt");
    in >> m_str;

    for(int i = 0; i < m_str.size(); i++){
        char c = m_str[i];
        int x = c - '0';
        g_data.push_back(x);
    }
}

void Output(){
    ofstream out("output.txt");

    for(int i = g_data.size() - 1; i >= 0; i--){
        if(g_data[i] != 0){
            out << g_data[i];
        }
    }
}

int main()
{
    Input();
    Output();
    return 0;
}
