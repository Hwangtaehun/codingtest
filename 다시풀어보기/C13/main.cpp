#include <stdio.h>

using namespace std;
//0:x, 1:block, -1:red
int g_edge, g_node;
int **g_data, *g_color;

void Print(){
    for(int i = 0; i < g_edge; i++){
        for(int j = 0; j < g_edge; j++){
            printf("%d ", g_data[i][j]);
        }
        printf("\n");
    }
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_edge);
    scanf("%d", &g_node);

    g_data = new int*[g_edge];
    g_color = new int[g_node];

    for(int i = 0; i < g_edge; i++){
        g_data[i] = new int[g_edge];
    }

    for(int i = 0; i < g_edge; i++){
        for(int j = 0; j < g_edge; j++){
            g_data[i][j] = 0;
        }
    }

    for(int i = 0; i < g_node; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g_data[a][b] = g_data[b][a] = 1;
        g_color[i] = 0;
    }

    fclose(stdin);
}

void mySolve(int start, int color){
    g_color[start] = color;

    for(int i = 0; i < g_edge; i++){
        if(g_data[start][i] && g_color[i] == color){
            g_color[start] = 0;
            return;
        }
    }

    for(int i = 0; i < g_edge; i++){
        if(g_data[start][i] && g_color[i] == 0){
            mySolve(i, 1);
            mySolve(i, -1);
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_edge; i++){
        if(g_color[i] == 0){
            printf("IMPOSSIBLE");
            fclose(stdout);
            return;
        }
    }
    printf("OK");
    fclose(stdout);
}

int main()
{
    Input();
    mySolve(0, 1);
    Output();
    return 0;
}
