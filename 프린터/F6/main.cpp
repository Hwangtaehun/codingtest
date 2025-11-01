#include <cstdio>
#include <vector>
#define SIZE 2

using namespace std;

int g_size, g_mem, g_min = 0x0FFFFFFF;
bool *g_used;
vector< vector <int> > g_data;

//solve
#define MAXV 999999
int M, n, i, m[101], c[101], DT[101][10001];
int Min(int a, int b){return a < b ? a : b;}
int Max(int a, int b){return a > b ? a : b;}

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_size, &g_mem);
    n = g_size;
    M = g_mem;

    g_data.resize(SIZE);
    for(int i = 0; i < SIZE; i++){
        g_data[i].resize(g_size);
    }

    g_used = new bool[g_size];

    for(int i = 0; i < g_size; i++){
        scanf("%d", &m[i+1]);
        g_data[0][i] = m[i+1];
        g_used[i] = false;
    }

    for(int i = 0; i < g_size; i++){
        scanf("%d", &c[i+1]);
        g_data[1][i] = c[i+1];
    }

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

void mySolve(int mem, int cost){
    if(mem >= g_mem){
        if(cost < g_min){
            g_min = cost;
        }
        return;
    }

    for(int i = 0; i < g_size; i++){
        if(!g_used[i]){
            g_used[i] = true;
            mySolve(mem + g_data[0][i], cost + g_data[1][i]);
            g_used[i] = false;
        }
    }
}

int f(int i, int r){
    if(i == 0){
        if(r <= 0){
            return 0;
        }else{
            return MAXV;
        }
    }else if(r < 0){
        return f(i - 1, r);
    }else{
        return Min(f(i - 1, r), f(i - 1, r - m[i]) + c[i]);
    }
}

void Solve(){
    int i, j, res = 100000;

    for(i = 1; i <= n; i++){
        for(j = 0; j <= 100*n; j++){
            if(j >= c[i]){
                DT[i][j] = Max(DT[i - 1][j], DT[i - 1][j - c[i]] + m[i]);
            }else{
                DT[i][j] = DT[i - 1][j];
            }
        }
    }

    for(j = 0; j <= 100 * n; j++){
        if(DT[n][j] >= M && res > j){
            res = j;
        }
    }

    printf("%d", res);
}

int main()
{
    Input();
    printf("%d\n", f(n, M));
    Solve();
    mySolve(0, 0);
    Output();
    return 0;
}
