#include <stdio.h>

using namespace std;
//0:x, 1:block, -1:red
int g_edge, g_node;
int **g_data;

void Print(){
    for(int i = 0; i < g_edge; i++){
        for(int j = 0; j < g_edge; j++){
            printf("%d ", g_data[i][j]);
        }
        printf("\n");
    }
}

void Input(){
    int color = 1;
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_edge);
    scanf("%d", &g_node);

    g_data = new int*[g_edge];
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
        g_data[a][b] = g_data[b][a] = color;
        color = -color;
    }

    fclose(stdin);
}

int main()
{
    Input();
    //Print();
    return 0;
}
