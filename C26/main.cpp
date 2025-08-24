#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define SIZE 2
using namespace std;

vector< vector<char> > g_data(SIZE);
vector<char> g_key;
int g_cnt = 0;

void Input(){
    string m_key, m_data1, m_data2;
    int m_key_s, m_data_s;

    freopen("input.txt", "r", stdin);
    cin >> m_key >> m_data1 >> m_data2;
    fclose(stdin);

    m_key_s = m_key.size();
    m_data_s = m_data1.size();

    for(int i = 0; i < SIZE; i++){
        g_data[i].resize(m_data_s);
    }

    g_key.resize(m_key_s);
    sprintf(g_key.data(), "%s", m_key.c_str());
    sprintf(g_data[0].data(), "%s", m_data1.c_str());
    sprintf(g_data[1].data(), "%s", m_data2.c_str());
}

void Testprint(){
    for(int i = 0; i < g_key.size(); i++){
        cout << g_key[i] << " ";
    }
        cout << endl;

    for(int i = 0; i < g_data.size(); i++){
        for(int j = 0; j < g_data[i].size(); j++){
            cout << g_data[i][j] << " ";
        }
        cout << endl;
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << g_cnt << endl;
    fclose(stdout);
}

int Trans(int ud){
    return ud > 0 ? 0 : 1;
}

void mySolve(int focus, int ud, int index){
    int m_col = Trans(ud);

    if(focus == g_key.size()){
        g_cnt++;
        return;
    }

    //important
    for(int i = index; i < g_data[0].size(); i++){
        if(g_key[focus] == g_data[m_col][i]){
            mySolve(focus + 1, -ud, i + 1);
        }
    }

    return;
}

int main()
{
    Input();
    //Testprint();
    mySolve(0, 1, 0);
    mySolve(0, -1, 0);
    Output();
    return 0;
}
