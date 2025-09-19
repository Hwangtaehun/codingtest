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

void mySolve(int cnt){
    if(cnt == 2){
        vector<int> m_island;
        vector<int> m_dis;

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
            m_dis.push_back(num);
        }

        sort(m_dis.begin(), m_dis.end());

        if(m_dis[0] > g_max){
            g_max = m_dis[0];
        }
    }

    for(int i = 0; i < g_cnt; i++){
        if(!g_used[i]){
            g_used[i] = true;
            mySolve(cnt + 1);
            g_used[i] = false;
        }
    }
}

int main()
{
    Input();
    mySolve(0);
    Output();
    return 0;
}
