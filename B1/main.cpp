#include <cstdio>
#include <algorithm>
#define ARR 4

using namespace std;

int **g_data, *g_cave, g_size, g_cnt;
int g_dx[ARR] = {1, -1, 0, 0}, g_dy[ARR] = {0, 0, 1, -1};

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);

    g_data = new int*[g_size];
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

void TestPrint(){
    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            printf("%d ", g_data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Asc(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

void Output(){
    g_cave = new int[g_cnt];

    for(int k = 0; k < g_cnt; k++){
        int m_cnt = 0;

        for(int i = 0; i < g_size; i++){
            for(int j = 0; j < g_size; j++){
                if(g_data[i][j] == k + 2){
                    m_cnt++;
                }
            }
        }

        g_cave[k] = m_cnt;
    }

    sort(g_cave, g_cave + g_cnt, Asc);

    freopen("output.txt", "w", stdout);
    printf("%d\n", g_cnt);
    for(int i = 0; i < g_cnt; i++){
        printf("%d\n", g_cave[i]);
    }
    fclose(stdout);

    for(int i = 0; i < g_size; i++){
        delete[] g_data[i];
    }
    delete[] g_data;
}

void mySolve(int col, int row){
    //TestPrint();
    if(col < 0 || col >= g_size || row < 0 || row >= g_size){
        return;
    }

    if(g_data[col][row] == 1){
        g_data[col][row] = g_cnt + 1;
        for(int i = 0; i < ARR; i++){
            mySolve(col + g_dx[i], row + g_dy[i]);
        }
    }else{
        return;
    }
}

int main()
{
    Input();
    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            if(g_data[i][j] == 1){
                g_cnt++;
                mySolve(i, j);
            }
        }
    }
    Output();
    return 0;
}
