#include <stdio.h>
#include <malloc.h>

using namespace std;

int g_edge, g_node, **g_data, g_min = 0x7FFFFFFF;
bool *g_visited;

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_edge, &g_node);
    g_data = (int **)malloc((g_edge + 1) * sizeof(int *));
    g_visited = (bool *)malloc((g_edge +1) * sizeof(bool *));

    for(int i = 0; i < g_edge + 1; i++){
        g_data[i] = (int *)malloc((g_edge + 1)* sizeof(int));
    }

    for(int i = 1; i <= g_edge; i++){
        for(int j = 1; j <= g_edge; j++){
            g_data[i][j] = 0;
        }
    }

    for(int i = 0; i < g_node; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        g_data[a][b] = g_data[b][a] = w;
    }

    for(int i = 0; i <= g_edge; i++){
        g_visited[i] = false;
    }

    fclose(stdin);
}

void Print(){
    for(int i = 1; i <= g_edge; i++){
        for(int j = 1; j <= g_edge; j++){
            printf("%3d ", g_data[i][j]);
        }
        printf("\n");
    }

    for(int i = 1; i <= g_edge; i++){
        printf("%d ", g_visited[i]);
    }
    printf("\n");
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);

    for (int i = 0; i < g_edge; i++) {
        free(g_data[i]);
    }
    free(g_data);
}

bool Check(){
    for(int i = 1; i <= g_edge; i++){
        if(g_visited[i])
            return false;
    }
    return true;
}

void mySolve(int s, int c){
    //printf("---------\n%d -> %d\n---------\n", s, c);
    if(s == g_edge){
        if(c < g_min){
            g_min = c;
        }
        return;
    }

    if(Check()){
        g_min = -1;
        return;
    }

    for(int i = 1; i <= g_edge; i++){
        //printf("%d -> %d = %d\n", s, i, c+g_data[s][i]);
        if(g_data[s][i] && !g_visited[i]){
            g_visited[i] = true;
            mySolve(i, c+g_data[s][i]);
            g_visited[i] = false;
        }
    }
}

int main()
{
    Input();
    //Print();
    g_visited[1] = true;
    mySolve(1, 0);
    Output();
    return 0;
}
