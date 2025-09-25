#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> g_data;
vector<pair <int, double> >g_result;
int g_stage;

void Input(){
    char m_char[500];

    freopen("input.txt", "r", stdin);
    scanf("%d", &g_stage);
    int c = getchar();            // 개행(\n) 먹기
    fgets(m_char, sizeof(m_char), stdin); // 두 번째 줄 읽기

    char *p = m_char;
    int val;
    while (sscanf(p, "%d", &val) == 1) {
        g_data.push_back(val);
        while (*p && *p != ' ' && *p != '\n' && *p != '\t') ++p;
        while (*p == ' ' || *p == '\t') ++p;
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("[");
    for(int i = 0; i < g_result.size(); i++){
        printf("%d", g_result[i].first);

        if(i != g_result.size() - 1){
            printf(", ");
        }
    }
    printf("]");
    fclose(stdout);
}

bool Compare(const pair<int, double> &i, const pair<int, double> &j){ // 이부분 주의
    if(i.second == j.second)
        return i.first < j.first;
    return i.second > j.second;
}

void Solve(){
    int m_total = g_data.size();

    for(int i = 1; i <= g_stage; i++){
        int cnt = 0;
        for(int j = 0; j < g_data.size(); j++){
            if(i == g_data[j]){
                cnt++;
            }
        }

        double value = (double)cnt / (double)m_total;
        g_result.push_back({i, value});
        m_total -= cnt;
    }

    sort(g_result.begin(), g_result.end(), Compare);

    for(int i = 0; i < g_result.size(); i++){
        printf("%d - %f\n", g_result[i].first, g_result[i].second);
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
