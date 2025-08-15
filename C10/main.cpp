#include <stdio.h>

using namespace std;

int g_size, g_sum = 0x7FFFFFFF;
int **g_data;
bool *g_visited;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);

    g_data = new int*[g_size];
    g_visited = new bool[g_size];

    for(int i = 0; i < g_size; i++){
        g_data[i] = new int[g_size];
    }

    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            scanf("%d", &g_data[i][j]);
        }
    }

    fclose(stdin);
}

void mySolve(int col, int sum){
    if(col == g_size){
        if(sum < g_sum)
            g_sum = sum;
        return;
    }

    for(int i = 0; i < g_size; i++){
        if(!g_visited[i]){
            g_visited[i] = true;
            mySolve(col+1, sum+g_data[col][i]);
            g_visited[i] = false;
        }
    }
}

int main()
{
    Input();
    mySolve(0, 0);
    printf("%d\n", g_sum);

    for(int i = 0; i < g_size; i++){
        delete[] g_data[i];
    }
    delete[] g_data;
    delete[] g_visited;
    return 0;
}
