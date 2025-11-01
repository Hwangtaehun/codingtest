#include <cstdio>
#include <vector>
#define COL 3
#define END 15
#define MOD 1000

using namespace std;

int g_size, g_cnt;
vector< vector<int> > g_data;
vector<bool> g_visited;

//solve
#include <memory.h>

int n, D[501], S[501], DT[501][501];
bool A[501];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    g_data.resize(g_size);
    g_visited.resize(g_size);
    for(int i = 0; i < g_size; i++){
        g_data[i].resize(COL);
        g_visited[i] = false;
        scanf("%d %d %d", &g_data[i][0], &g_data[i][1], &g_data[i][2]);
    }
    fclose(stdin);

    memset(DT, -1, sizeof(DT));
    n = g_size;

    for(int i = 0; i < n; i++){
        D[i] = g_data[i][0];
        S[i] = g_data[i][1];
        A[i] = g_data[i][2];
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt % MOD);
    fclose(stdout);
}

bool Check(int num){
    if(num >= 0 && num <= END){
        return true;
    }
    return false;
}

int Index(int num){
    for(int i = 0; i < g_size; i++){
        if(g_data[i][0] == num){
            return i;
        }
    }

    return -1;
}

void mySolve(int i, bool a){
    int m_dis = 0;
    int m_index;

    if(i == 0 && a){
        g_cnt++;
        return;
    }

    if(i == g_size - 1 && !a){
        a = true;
        g_visited[0] = false;
    }

    if(a){
        m_dis = g_data[i][0] - g_data[i][1];
        if(!Check(m_dis)){
            m_dis = 0;
        }

        for(int j = g_data[i][0] - 1; j >= m_dis; j--){
            m_index = Index(j);
            if((m_index != -1 && g_data[m_index][2]) && !g_visited[m_index]){
                g_visited[m_index] = true;
                mySolve(m_index, a);
                g_visited[m_index] = false;
            }
        }
    }else {
        m_dis = g_data[i][0] + g_data[i][1];
        if(!Check(m_dis)){
            m_dis = END;
        }

        for(int j = g_data[i][0] + 1; j <= m_dis; j++){
            m_index = Index(j);
            if(m_index != -1 && !g_visited[m_index]){
                g_visited[m_index] = true;
                mySolve(m_index, a);
                g_visited[m_index] = false;
            }
        }
    }
}

int f(int a, int b, int k){
    if(DT[a][b] == -1){
        if(k == n - 1){
            return ((D[a] + S[a] >= D[k]) && (D[b] + S[k] >= D[k]));
        }

        DT[a][b] = f(a, b, k + 1);

        if(D[a] + S[a] >= D[k]){
            DT[a][b] += f(k, b, k + 1);
        }

        if(D[b] + S[k] >= D[k] && A[k]){
            DT[a][b] += f(a, k, k + 1);
        }

        DT[a][b] %= MOD;
    }

    return DT[a][b];
}

void Solve1(){
    memset(DT, 0, sizeof(DT));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                DT[i][j] = 1;
            }else if((i != j || i == n - 1)&& j == n - 1){
                if(i > j){
                    for(int k = 0; k < i; k++){
                        if(D[k] + S[k] >= D[i]){
                            DT[i][j] += DT[k][j];
                        }
                    }
                }else if(A[j]){
                    for(int k = 0; k < j; k++){
                        if(D[k] + S[j] >= D[j]){
                            DT[i][j] += DT[i][k];
                        }
                    }
                }
            }
            DT[i][j] %= MOD;
        }
    }
    printf("%d\n", DT[n-1][n-1]);
}

void Solve2(){
    int ans = 0;

    memset(DT, 0, sizeof(DT));
    DT[0][0] = 1;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if((i == 0 && j == 0) || (i != j && A[j])){
                int k = i;

                if(k < j){
                    k = j;
                }

                for(k++; k < n; k++){
                    if(S[i] >= D[k] - D[i]){
                        DT[k][j] = (DT[k][j] + DT[i][j]) % MOD;
                    }

                    if(S[k] >= D[k] - D[j]){
                        DT[i][k] = (DT[i][k] + DT[i][j]) % MOD;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n - 1; i++){
        if(S[i] >= D[n - 1] - D[i]){
            ans = (ans + DT[i][n - 1]) % MOD;
        }
    }

    printf("%d\n", ans);
}

int main()
{
    Input();
    printf("%d\n", f(0, 0, 1));
    Solve1();
    Solve2();
    g_visited[0] = true;
    mySolve(0, false);
    Output();
    return 0;
}
