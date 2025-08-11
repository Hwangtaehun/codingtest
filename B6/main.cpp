#include <stdio.h>
#include <queue>

using namespace std;

struct ROWCOL{
    int box;
    int row; //열
    int col; //행
};

int g_box, g_row, g_col;
int g_dbox[6] = {0, 0, 0, 0, 1, -1}, g_drow[6] = {1, 0, -1, 0, 0, 0}, g_dcol[6] = {0, 1, 0, -1, 0, 0};
int ***g_data;
queue <ROWCOL> g_q;

bool isSafe(int box, int row, int col){
    return (box >= 0 && box < g_box) && (row >= 0 && row < g_row) && (col >= 0 && col < g_col);
}

void Print(){
    for(int i = 0; i < g_box; i++){
        for(int j = 0; j < g_col; j++){
            for(int k = 0; k < g_row; k++){
                printf("%d ", g_data[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void Input(){
    freopen("input1.txt", "r", stdin);
    scanf("%d %d %d", &g_row, &g_col, &g_box);

    g_data = new int**[g_box];

    for(int i = 0; i < g_box; i++){
        g_data[i] = new int*[g_col];
    }

    for(int i = 0; i < g_box; i++){
        for(int j = 0; j < g_col; j++){
            g_data[i][j] = new int[g_row];
        }
    }

    for(int i = 0; i < g_box; i++){
        for(int j = 0; j < g_col; j++){
            for(int k = 0; k < g_row; k++){
                scanf("%d", &g_data[i][j][k]);
                if(g_data[i][j][k] == 1){
                    g_q.push((ROWCOL){i, k, j});
                }
            }
        }
    }

    fclose(stdin);
}

void Output(int cnt){
    for(int i = 0; i < g_box; i++){
        for(int j = 0; j < g_col; j++){
            for(int k = 0; k < g_row; k++){
                if(g_data[i][j][k] == 0){
                    cnt = -1;
                    break;
                }
                break;
            }
            break;
        }
    }

    freopen("output.txt", "w", stdout);
    printf("\n%d\n", cnt);
    fclose(stdout);
}

int mySolve(){
    int m_cnt;

    while(!g_q.empty()){
        ROWCOL pos = g_q.front();
        g_q.pop();
        Print();

        for(int i = 0; i < 6; i++){
            int m_box = pos.box + g_dbox[i];
            int m_col = pos.col + g_dcol[i];
            int m_row = pos.row + g_drow[i];

            if(isSafe(m_box, m_row, m_col) && g_data[m_box][m_col][m_row] == 0){
                g_q.push((ROWCOL){m_box, m_row, m_col});
                g_data[m_box][m_col][m_row] = g_data[pos.box][pos.col][pos.row] + 1;
                m_cnt = g_data[m_box][m_col][m_row];
            }
        }
    }

    return m_cnt - 1;
}

int main()
{
    int cnt;

    Input();
    cnt = mySolve();
    Output(cnt);

    return 0;
}
