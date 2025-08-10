#include <stdio.h>
#include <queue>

using namespace std;

struct VERTEX{
    int row, col;
};

int g_dcol[4] = {1, 0, -1, 0}, g_drow[4] = {0, 1, 0, -1};
int g_row, g_col; //ї­, За
int g_cnt;
int **g_data;
queue < VERTEX > q;

using namespace std;

bool isSafe(int row, int col){
    return (col >= 0 && col < g_col) && (row >= 0 && row < g_row);
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_row, &g_col);

    g_data = new int*[g_col];

    for(int i = 0; i < g_col; i++){
        g_data[i] = new int[g_row];
    }

    for(int i = 0; i < g_col; i++){
        for(int j = 0; j < g_row; j++){
            scanf("%d", &g_data[i][j]);
            if(g_data[i][j] == 1){
                q.push((VERTEX){j, i});
            }
        }
    }

    fclose(stdin);
}

void Print(queue <VERTEX> q1){
    while(!q1.empty()) {
        printf("%d,%d\n", q1.front().col, q1.front().row);
        q1.pop();
    }

    for(int i = 0; i < g_col; i++){
        for(int j = 0; j < g_row; j++){
            printf("%d", g_data[i][j]);
        }
        printf("\n");
    }
}

void Output(){
    for(int i = 0; i < g_col; i++){
        for(int j = 0; j < g_row; j++){
            if(g_data[i][j] == 0){
                g_cnt = -1;
            }
        }
    }

    freopen("output.txt", "w", stdout);
    printf("\n\n%d\n\n", g_cnt);
    fclose(stdout);
}

int mySolve(){
    int m_cnt;
    while(!q.empty()){
        //Print(q);
        VERTEX pos = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int row = pos.row + g_drow[i];
            int col = pos.col + g_dcol[i];
            if(isSafe(row, col) && g_data[col][row] == 0){
                q.push((VERTEX){row, col});
                g_data[col][row] = g_data[pos.col][pos.row] + 1;
                m_cnt = g_data[col][row];
            }
        }
    }

    return m_cnt - 1;
}

int main()
{
    Input();
    g_cnt = mySolve();
    Output();
    return 0;
}
