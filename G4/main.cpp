#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int g_size, g_remove = 0;
vector< pair<int,int> > g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    for(int i = 0; i < g_size; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        g_data.push_back({x, y});
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_remove);
    fclose(stdout);
}

int Solve(int k){
    int cnt = 1, cnt2;
    for(int i = k + 1; i < g_size; i++){
        if(g_data[k].second < g_data[i].second){
            cnt2 = Solve(i) + 1;
            if(cnt < cnt2){
                cnt = cnt2;
            }
        }
    }
    return cnt;
}

void Print(){
    for(int i = 0; i < g_size; i++){
        printf("%d %d\n", g_data[i].first, g_data[i].second);
    }
}

int main()
{
    int m_cnt;

    Input();
    sort(g_data.begin(), g_data.end());
    Print();
    for(int i = 0; i < g_size; i++){
        m_cnt = Solve(i);
        if(g_remove < m_cnt){
            g_remove = m_cnt;
        }
    }

    g_remove = g_size - g_remove;

    Output();

    return 0;
}
