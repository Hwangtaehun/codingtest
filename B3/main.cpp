#include <stdio.h>
#include <stdlib.h>

using namespace std;

int m_size, cnt;
bool **g_check;

void input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &m_size);
    fclose(stdin);
}

void output(){
    freopen("output.txt", "w", stdout);
    printf("%d", cnt);
    fclose(stdout);
}

void Init(int **data){
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            data[i][j] = 0;
        }
    }
}

bool Check(int **data){
    for(int i = 0; i < m_size; i++){
        for(int j = 0; j < m_size; j++){
            if(data[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

void Print(int **data){
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void Solve(int **data, int x, int y){
    for(int i = 0; i < m_size; i++){
        int m_x = x + i;
        int m_y = y + i;

        if(data[x][i] == 0){
            data[x][i] = 2;
        }

        if(data[i][y] == 0){
            data[i][y] = 2;
        }

        if(m_x < m_size && m_y < m_size){
            if(data[m_x][m_y] == 0){
                data[m_x][m_y] = 2;
            }
        }

    }

    if(!Check(data)){
        for (int i = 0; i < m_size; i++) {
            for (int j = 0; j < m_size; j++) {
                if(data[i][j] == 0 && !g_check[i][j]){
                    data[i][j] = 1;
                    Solve(data, i, j);
                }
            }
        }
    }
    else{
        int m_chat = 0;

        for(int i = 0; i < m_size; i++){
            for(int j = 0; j < m_size; j++){
                if(data[i][j] == 1)
                    m_chat++;
            }
        }

        if(m_chat == m_size){
            cnt++;
        }
        return;
    }

}

int main()
{
    input();
    int **data = new int*[m_size];
    g_check = new bool*[m_size];
    cnt = 0;

    for(int i = 0; i < m_size; i++){
        data[i] = new int[m_size]{0};
        g_check[i] = new bool[m_size]{0};
    }

    Init(data);

    for(int i = 0; i < m_size; i++){
        for(int j = 0; j < m_size; j++){
            data[i][j] = 1;
            g_check[i][j] = 1;
            Solve(data, i, j);
            Init(data);
        }
    }

    for (int i = 0; i < m_size; i++) {
        delete[] data[i];
    }

    delete[] data;

    output();

    return 0;
}
