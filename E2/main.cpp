#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> g_result;
int g_size;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_result.size(); i++){
        cout << g_result[i] << endl;
    }
    fclose(stdout);
}

void mySolve(){
    int m_cnt = 1;
    while(m_cnt <= g_size){
        vector<char> m_char;

        for(int i = 0; i < m_cnt; i++){
            m_char.push_back('*');
        }

        string m_str(m_char.begin(), m_char.end());
        g_result.push_back(m_str);
        m_cnt++;
    }
}

int main()
{
    Input();
    mySolve();
    Output();
    return 0;
}
