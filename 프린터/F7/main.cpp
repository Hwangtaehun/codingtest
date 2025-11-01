#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int g_n, g_m, g_a, g_b, g_x, g_y, g_min = 0x0FFFFFFF; // a: start, b: goal, x: remove, y: add
vector<int> g_line;

//solve
int n, m, a, b, x, y, p[501], DT[501][101];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_n, &g_m);
    scanf("%d %d %d %d", &g_a, &g_b, &g_x, &g_y);
    for(int i = 0; i < g_m; i++){
        scanf("%d", &p[i+1]);
        g_line.push_back(p[i+1]);
    }
    fclose(stdin);

    n = g_n;
    m = g_m;
    a = g_a;
    b = g_b;
    x = g_x;
    y = g_y;

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            DT[i][j] = 99999999;
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

int Move(int index, int cur){

    if(g_line[index] == cur){
        cur = g_line[index] + 1;
    }else if(g_line[index] + 1 == cur){
        cur = g_line[index];
    }

    return cur;
}

void mySolve(int cur, int index, int cost){
    if(g_min < cost){
        return;
    }

    if(index == g_line.size() - 1){
        if(cur > g_b){
            g_line.push_back(cur - 1);
            cost += g_y;
        }else if(cur < g_b){
            g_line.push_back(cur);
            cost += g_y;
        }
    }

    if(index == g_line.size()){
        if(cur == g_b){
            if(cost < g_min){
                g_min = cost;
            }
        }
        return;
    }

    int m_cur = Move(index, cur);

    mySolve(cur, index + 1, cost + g_x);
    mySolve(m_cur, index + 1, cost);
}

int isIn(int a, int b, int k){
    return ((a <= k && k < b) || (b <= k && k < a)) ? 1:0;
}

void Solve(){
    for(int j = 1; j <= n; j++){
        DT[0][j] = abs(j - a) * y;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(j == k && (p[i] == k || p[i] + 1 == k)){
                    DT[i][j] = (DT[i - 1][k] + x < DT[i][j]) ? DT[i - 1][k] + x : DT[i][j];
                }else if(isIn(j, k, p[i])){
                    DT[i][j] = DT[i - 1][k] + (abs(j - k) - 1) * y < DT[i][j] ? DT[i - 1][k] + (abs(j - k) - 1) * y : DT[i][j];
                }else{
                    DT[i][j] = DT[i - 1][k] + abs(j - k) * y < DT[i][j] ? DT[i - 1][k] + abs(j - k) * y : DT[i][j];
                }
            }
        }
    }

    printf("%d\n", DT[m][b]);
}

int main()
{
    Input();
    Solve();
    mySolve(g_a, 0, 0);
    Output();
    return 0;
}
