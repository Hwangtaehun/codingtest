#include <stdio.h>
#include <stdlib.h>

using namespace std;

int g_size, g_cnt;
bool **g_check;

void input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    fclose(stdin);
}

void output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt);
    fclose(stdout);
}

void Init(int **data){
    for (int i = 0; i < g_size; i++) {
        for (int j = 0; j < g_size; j++) {
            data[i][j] = 0;
        }
    }
}

bool Check(int **data){
    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            if(data[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

void Print(int **data){
    for (int i = 0; i < g_size; i++) {
        for (int j = 0; j < g_size; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void Solve(int **data, int x, int y){
    for(int i = 0; i < g_size; i++){
        int m_x = x + i;
        int m_y = y + i;

        if(data[x][i] == 0){
            data[x][i] = 2;
        }

        if(data[i][y] == 0){
            data[i][y] = 2;
        }

        if(m_x < g_size && m_y < g_size){
            if(data[m_x][m_y] == 0){
                data[m_x][m_y] = 2;
            }
        }

    }

    if(!Check(data)){
        for (int i = 0; i < g_size; i++) {
            for (int j = 0; j < g_size; j++) {
                if(data[i][j] == 0 && !g_check[i][j]){
                    data[i][j] = 1;
                    Solve(data, i, j);
                }
            }
        }
    }
    else{
        int m_chat = 0;

        for(int i = 0; i < g_size; i++){
            for(int j = 0; j < g_size; j++){
                if(data[i][j] == 1)
                    m_chat++;
            }
        }

        if(m_chat == g_size){
            g_cnt++;
        }
        return;
    }

}

int main()
{
    input();
    int **data = new int*[g_size];
    g_check = new bool*[g_size];
    g_cnt = 0;

    for(int i = 0; i < g_size; i++){
        data[i] = new int[g_size]{0};
        g_check[i] = new bool[g_size]{0};
    }

    Init(data);

    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            data[i][j] = 1;
            g_check[i][j] = 1;
            Solve(data, i, j);
            Init(data);
        }
    }

    for (int i = 0; i < g_size; i++) {
        delete[] data[i];
    }

    delete[] data;

    output();

    return 0;
}
