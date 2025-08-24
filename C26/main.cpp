#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define SIZE 2
using namespace std;

vector< vector<char> > g_data(SIZE);
vector<char> g_key;
int g_cnt = 0;

//solve
char scroll[11];
char bridge[2][21];

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
    sprintf(scroll, "%s", m_key.c_str());
    sprintf(bridge[0], "%s", m_data1.c_str());
    sprintf(bridge[1], "%s", m_data2.c_str());
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
    int m_row = Trans(ud);

    if(focus == g_key.size()){
        g_cnt++;
        return;
    }

    //important
    for(int i = index; i < g_data[0].size(); i++){
        if(g_key[focus] == g_data[m_row][i]){
            mySolve(focus + 1, -ud, i + 1);
        }
    }

    return;
}

int Solve(int row, int n, int rp){
    int i, c = 0, next;

    if(scroll[rp] == '\0')
        return 1;

    for(i = n; bridge[row][i] != '\0'; i++){
        if(bridge[row][i] == scroll[rp]){
            printf("%d,%c  ", i, scroll[rp]);
            next = (row == 0) ? 1 : 0;
            c += Solve(next, i + 1, rp + 1);
            if(c > 0)
                printf("---\n");
        }
    }

    return c;
}

int main()
{
    Input();
    //Testprint();
    mySolve(0, 1, 0);
    mySolve(0, -1, 0);
    printf("\n%d\n", Solve(0, 0, 0) + Solve(1, 0, 0));
    Output();
    return 0;
}
