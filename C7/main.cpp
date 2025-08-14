#include <stdio.h>

using namespace std;

int **g_data;
bool *g_visited;
int g_vertex, g_edge;
int g_cost = 0x7FFFFFFF;

void Input(){
    int a, b, w;

    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_vertex, &g_edge);
    g_data = new int*[g_vertex + 1];
    g_visited = new bool[g_vertex + 1];
    for(int i = 0; i <= g_vertex; i++){
        g_data[i] = new int[g_vertex + 1];
    }

    for(int i = 0; i <= g_vertex; i++){
        for(int j = 0; j <= g_vertex; j++){
            g_data[i][j] = 0;
        }
    }

    for(int i = 0; i < g_edge; i++){
        scanf("%d %d %d", &a, &b, &w);
        g_data[a][b] = g_data[b][a] = w;
    }

    fclose(stdin);
}

void Print(){
    for(int i = 0; i <= g_vertex; i++){
        for(int j = 0; j <= g_vertex; j++){
            printf("%3d ", g_data[i][j]);
        }
        printf("\n");
    }
}

void Search(int s, int co){

    if(s == g_vertex){
        if(co < g_cost){
            g_cost = co;
        }
        return;
    }

    for(int d = 0; d <= g_vertex; d++){
        if(g_data[s][d] && !g_visited[d]){
            int m_cost = co + g_data[s][d];
            g_visited[d] = true;
            Search(d, m_cost);
            g_visited[d] = false;
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_cost);
    fclose(stdout);
}

int main()
{
    Input();
    g_visited[1] = true;
    Search(1, 0);
    Output();
    return 0;
}
