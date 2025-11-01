#include <cstdio>
#include <vector>
#define SIZE 2

using namespace std;

int g_cnt, g_weight, g_max = 0;
vector<vector <int> > g_data;
bool *g_used;

//solve
int DT[102][10002];
int w[102], v[102], i, j, n, W;
int Max(int a, int b) {return a > b ? a : b;}

void Init(){
    for(i = 0; i <= 100; i++){
        for(j = 0; j <= 10000; j++){
            DT[i][j] = -1;
        }
    }
}

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_cnt, &g_weight);
    n = g_cnt;
    W = g_weight;

    g_data.resize(g_cnt);
    g_used = new bool[g_cnt];

    for(int i = 0; i < g_cnt; i++){
        g_data[i].resize(SIZE);
        g_used[i] = false;
    }

    for(int i = 0; i < g_cnt; i++){
        scanf("%d %d", &w[i], &v[i]);
        g_data[i][0] = w[i]; //무게
        g_data[i][1] = v[i]; //가격
    }

    fclose(stdin);

    Init();
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_max);
    fclose(stdout);
}

void mySolve(int w, int v){ //w:무게, v:가격
    if(w <= g_weight){
        if(v > g_max){
            g_max = v;
        }
    }else{
        return;
    }

    for(int i = 0; i < g_cnt; i++){
        if(!g_used[i]){
            g_used[i] = true;
            mySolve(w + g_data[i][0], v + g_data[i][1]);
            g_used[i] = false;
        }
    }
}

int f(int i, int r){
    if(DT[i][r] != -1)
        return DT[i][r];

    if(i == n + 1)
        return DT[i][r] = 0;
    else if(r < w[i])
        return DT[i][r] = f(i + 1, r);
    else
        return DT[i][r] = Max(f(i + 1, r), f(i + 1, r - w[i]) + v[i]);
}

void Solve(){
    Init();

    for(i = n; i >= 1; i--){
        for(j = 0; j <= W; j++){
            if(j < w[i])
                DT[i][j] = DT[i + 1][j];
            else
                DT[i][j] = Max(DT[i + 1][j], DT[i + 1][j - w[i]] + v[i]);
        }
    }
}

int main()
{
    Input();
    printf("%d\n", f(1, W));
    printf("%d\n", DT[1][W]);
    mySolve(0, 0);
    Output();
    return 0;
}
