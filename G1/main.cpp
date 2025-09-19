#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int g_fin, g_cnt, g_mus, g_max = 0;
vector<int> g_data;
vector<bool> g_used;

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &g_fin, &g_cnt, &g_mus);
    g_data.resize(g_cnt);
    g_used.resize(g_cnt);
    for(int i = 0; i < g_cnt; i++){
        scanf("%d", &g_data[i]);
    }

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_max);
    fclose(stdout);
}

void Print(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mySolve(int ind, int cnt){
    if(cnt == g_mus){
        vector<int> m_island;
        int m_dis = 0x0FFFFFFF;

        m_island.push_back(0);
        for(int i = 0; i < g_cnt; i++){
            if(!g_used[i]){
                m_island.push_back(g_data[i]);
            }
        }
        m_island.push_back(g_fin);

        sort(m_island.begin(), m_island.end());

        for(int i = 0; i < m_island.size() - 1; i++){
            int num = m_island[i + 1] - m_island[i];
            if(num < m_dis){
                m_dis = num;
            }
        }

        if(m_dis > g_max){
            g_max = m_dis;
        }
    }

    for(int i = ind; i < g_cnt; i++){
        if(!g_used[i]){
            g_used[i] = true;
            mySolve(ind + 1, cnt + 1);
            g_used[i] = false;
        }
    }
}

int main()
{
    Input();
    mySolve(0, 0);
    Output();
    return 0;
}
