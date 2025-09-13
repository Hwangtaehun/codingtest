#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#define MOD 1000000003

using namespace std;

int g_size, g_choose, g_result;
bool *g_used;
vector<string> g_data;

//solve
#include <memory.h>
int DT1[1001][1001], DT2[1001][1001][2], n, k;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_choose);
    n = g_size;
    k = g_choose;
    fclose(stdin);
    g_used = new bool[g_size];
    for(int i = 0; i < g_size; i++){
        g_used[i] = false;
    }
}

void Output(){
    g_result = g_data.size() % MOD;
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
    if(cnt >= g_choose){
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

            if(g_data.size() == 0){
                g_data.push_back(m_result);
                return;
            }

            for(int i = 0; i < g_data.size(); i++){
                if(g_data[i] != m_result){
                    g_data.push_back(m_result);
                }
            }
        }
        return;
    }

    for(int i = 0; i < g_size; i++){
        if(!g_used[i] && Check(i))
        g_used[i] = true;
        mySolve(cnt + 1);
        g_used[i] = false;
    }
}

int f1(int n, int k){
    if(k > n / 2){
        DT1[n][k] = 0;
    }else if(k == 1){
        DT1[n][k] = n;
    }else{
        DT1[n][k] = (f1(n - 2, k - 1) + f1(n - 1, k)) % MOD;
    }

    return DT1[n][k];
}

int f2(int a, int b, bool can){
    if(a >= n || b == k){
        return (int)((b == k) && (a <= n || can));
    }else if(DT2[a][b][can] == -1){
        DT2[a][b][can] = (f2(a + 1, b, can) + f2(a + 2, b + 1, can)) % MOD;
    }

    return DT2[a][b][can];
}

int main()
{
    Input();
    printf("%d\n", f1(n, k));
    memset(DT2, -1, sizeof(DT2));
    printf("%d\n", (f2(1, 0, true) + f2(2, 1, false)) % MOD);
    mySolve(0);
    Output();
    return 0;
}
