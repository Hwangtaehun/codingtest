#include <cstdio>
#include <vector>

using namespace std;

vector< vector <int> > g_data;
bool *g_used;
int g_edge, g_size, g_min = 0x0fffffff;

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_edge, &g_size);

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

int main()
{
    Input();
    mySolve(1, 0);
    Output();
    return 0;
}
