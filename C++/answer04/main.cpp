#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> first = {1, 2, 3, 4, 5};
vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> thrid = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
vector<int> g_answer, g_result;

void Input(){
    freopen("input.txt", "r", stdin);
    int x;
    while (scanf("%d", &x) != EOF) {
        g_answer.push_back(x);
    }
    fclose(stdin);
}

void Output(){
    sort(g_result.begin(), g_result.end());
    freopen("output.txt", "w", stdout);
    printf("[");
    for(int i = 0; i < g_result.size(); i++){
        printf("%d", g_result[i]);
        if(g_result.size() - 1 != i){
            printf(", ");
        }
    }
    printf("]");
    fclose(stdout);
}

void Solve(){
    vector<int> m_cnt(3);

    for(int i = 0; i < g_answer.size(); i++){
        if(g_answer[i] == first[i % first.size()]){
            m_cnt[0]++;
        }

        if(g_answer[i] == second[i % second.size()]){
            m_cnt[1]++;
        }

        if(g_answer[i] == thrid[i % thrid.size()]){
            m_cnt[2]++;
        }
    }

    int m_max = *max_element(m_cnt.begin(), m_cnt.end());

    for(int i = 0; i < 3; i++){
        if(m_cnt[i] == m_max){
            g_result.push_back(i + 1);
        }
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
