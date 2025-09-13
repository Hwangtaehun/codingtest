#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REST 1000000003

using namespace std;

int g_size, g_choose, g_result;
bool *g_used;
vector<string> g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_choose);
    fclose(stdin);
    g_used = new bool[g_size];
    for(int i = 0; i < g_size; i++){
        g_used[i] = false;
    }
}

void Output(){
    g_result = g_data.size() % REST;
    freopen("output.txt", "w", stdout);
    printf("%d", g_result);
    fclose(stdout);
}

bool Check(int num){
    int m_left, m_right;
    m_left = num - 1;
    m_right = num + 1;

    if(m_right > g_size){
        m_right = 0;
    }

    if(m_left == -1){
        m_left = g_size - 1;
    }

    if(!g_used[m_right] && !g_used[m_left]){
        return true;
    }

    return false;
}

int Count(){
    int m_cnt = 0;
    for(int i = 0; i < g_size; i++){
        if(g_used[i]){
            m_cnt++;
        }
    }
    return m_cnt;
}

void Print(){
    for(int i = 0; i < g_size; i++){
        if(g_used[i]){
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

void mySolve(int cnt){
    if(cnt == g_choose){
        if(Count() == g_choose){
            vector<char> m_cho;
            for(int i = 0; i < g_size; i++){
                if(g_used[i]){
                    char m_ch = i + 1 + '0';
                    m_cho.push_back(m_ch);
                }
            }
            sort(m_cho.begin(), m_cho.end());
            string m_result(m_cho.begin(), m_cho.end());

            //cout << "m_result = " << m_result << endl;

            if(g_data.size() == 0){
                g_data.push_back(m_result);
                return;
            }

            for(int i = 0; i < g_data.size(); i++){
                if(g_data[i].compare(m_result)){
                    g_data.push_back(m_result);
                }
            }
        }
        return;
    }

    for(int i = 0; i < g_size; i++){
        if(!g_used[i] && Check(i))
        g_used[i] = true;
        //Print();
        mySolve(cnt + 1);
        g_used[i] = false;
    }
}

int main()
{
    Input();
    mySolve(0);
    Output();
    return 0;
}
