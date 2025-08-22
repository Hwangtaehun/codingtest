#include <cstdio>
#include <algorithm>
#include <queue>
#define ARR 4

using namespace std;

struct VERTEX{
    int x;
    int y;
};

int g_dx[ARR] = {1, -1, 0, 0}, g_dy[ARR] = {0, 0, 1, -1};
int **g_data, *g_cave, g_size, g_cnt = 0;

bool isSafe(int col, int row){
    if(col < 0 || col >= g_size || row < 0 || row >= g_size){
        return false;
    }
    return true;
}

int Asc(int a, int b){
    return a > b ? a : b;
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
}

void mySolve(int col, int row){
    queue <VERTEX> q;
    q.push((VERTEX){col, row}); //¡÷¿«

    while(!q.empty()){
        int m_x, m_y;
        m_x = q.front().x;
        m_y = q.front().y;
        g_data[m_x][m_y] = g_cnt + 1;
        q.pop();

        for(int i = 0; i < ARR; i++){
            if(isSafe(m_x+g_dx[i], m_y+g_dy[i]) && g_data[m_x+g_dx[i]][m_y+g_dy[i]] == 1){
                q.push((VERTEX){m_x+g_dx[i], m_y+g_dy[i]});
            }
        }
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
                //TestPrint();
            }
        }
    }
    Output();
    return 0;
}
