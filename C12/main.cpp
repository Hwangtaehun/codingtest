#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#include <malloc.h>

using namespace std;

int g_dx[4] = {1, -1, 0, 0};
int g_dy[4] = {0, 0, 1, -1};
int g_row, g_col, g_cnt = 0;
int **g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_col, &g_row);
    g_data = (int **)malloc(g_col * sizeof(int *));

    for(int i = 0; i < g_col; i++){
        g_data[i] = (int *)malloc(g_row * sizeof(int));
    }

    for(int i = 0; i < g_col; i++){
        for(int j = 0; j < g_row; j++){
            scanf("%d", &g_data[i][j]);
        }
    }

    fclose(stdin);
}

void Print(){
    for(int i = 0; i < g_col; i++){
        for(int j = 0; j < g_row; j++){
            printf("%d ", g_data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int col, int row){
    return (col >=0 && col < g_col) && (row >= 0 && row < g_row);
}

int Search(int col, int row){
    int m_cnt = 0;

    for(int i = 0; i < 4; i++){
        int m_col = col + g_dy[i], m_row = row + g_dx[i];
        if(isSafe(m_col, m_row) && g_data[m_col][m_row] == 0)
            m_cnt++;
    }
    return m_cnt;
}

bool Check(){
    for(int i = 0; i < g_col; i++){
        for(int j = 0; j < g_row; j++){
            if(g_data[i][j])
                return false;
        }
    }
    return true;
}

void Solve(){
    vector< pair <int,int> > dc;

    while(!Check()){
        //Print();

        for(int i = 0; i < g_col; i++){
            for(int j = 0; j < g_row; j++){
                if(g_data[i][j] == 1){
                    if(Search(i, j) >= 2){
                        dc.push_back(make_pair(i,j));
                    }
                }
            }
        }

        for(int i = 0; i < dc.size(); i++){
            g_data[dc[i].first][dc[i].second] = 0;
        }

        dc.clear();
        g_cnt++;
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt);
    fclose(stdout);
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
