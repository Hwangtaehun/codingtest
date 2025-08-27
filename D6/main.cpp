#include <cstdio>
#include <vector>

using namespace std;

vector< vector <int> > g_data;
bool *g_used;
int g_edge, g_size, g_min = 0x0fffffff;

//solve
int n, m, data[11][11], wmin = 0x7fffffff, visited[11], debugCnt;

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_edge, &g_size);
    n = g_edge;
    m = g_size;

    g_data.resize(g_edge + 1);
    g_used = new bool[g_edge];

    for(int i = 0; i < g_edge + 1; i++){
        g_data[i].resize(g_edge);
        g_used[i] = false;
    }

    for(int i = 0; i < g_size; i++){
        int a, b, n;
        scanf("%d %d %d", &a, &b, &n);
        g_data[a][b] = g_data[b][a] = n;
        data[a][b] = data[b][a] = n;
    }

    fclose(stdin);
}

void TestPrint(){
    for(int i = 0; i < g_edge; i++){
        for(int j = 0; j < g_edge; j++){
            printf("%3d ", g_data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

void mySolve(int start, int cost){
    if(start == g_edge){
        if(cost < g_min){
            g_min = cost;
        }
        return;
    }

    for(int i = 1; i <= g_edge; i++){
        if(g_data[start][i] && !g_used[i]){
            g_used[i] = true;
            mySolve(i, cost + g_data[start][i]);
            g_used[i] = false;
        }
    }
}

void ArrayPrn(int w){
    printf("\t");
    for(int i = 1; i <= n; i++){
        printf("%d ", visited[i]);
    }
    printf(" %5d\n", w);
}

void Solve(int v, int w)
{
    if(w > wmin)
        return;
    debugCnt++;


    if(v==n){
        if(w < wmin)
            wmin = w;
        ArrayPrn(w);
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i] && data[v][i]){
            visited[i] = 1;
            printf("%d,%d ", v, i);
            Solve(i, w + data[v][i]);
            visited[i] = 0;
        }
    }
}

int Greedy(int v){
    int i, t, sol = 0;

    while(v != n)
    {
        int min = 0x7fffffff;
        for(i = v; i <= n; i++){
            if(data[v][i] && data[v][i] < min){
                min = data[v][i];
                t = i;
                printf("%d,%d,%d\t", v, i, min);
            }
        }
        sol += data[v][t];
        v = t;
    }
    return sol;
}

int main()
{
    Input();

    //solve
    visited[1] = 1;

    wmin = Greedy(1);

    printf("\nwmin 1 = %d\n", wmin);

    Solve(1, 0);

    printf("\n%d\n", (wmin == 0x7fffffff) ? -1 : wmin);
    printf("debugCnt = %d\n", debugCnt);

    mySolve(1, 0);
    Output();
    return 0;
}
