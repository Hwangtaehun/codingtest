#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int g_dx[4] = {1, -1, 0, 0};
int g_dy[4] = {0, 0, 1, -1};
int g_row, g_col, g_cnt = 0;
int **g_data;

struct ROWCOL {
    int row;
    int col;
};

int a1[101][101], a2[101][101];
int rowCnt, colCnt;
queue <ROWCOL> q;

void ArrayPrn(){
    for(int i = 1;  i <= rowCnt; i++){
        for(int j = 1; j <= colCnt; j++){
            printf("%d ", a1[i][j]);
        }
        printf("\t");
        for(int j = 1; j <= colCnt; j++){
            printf("%d ", a2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_col, &g_row);
    rowCnt = g_col;
    colCnt = g_row;

    g_data = (int **)malloc(g_col * sizeof(int *));

    for(int i = 0; i < g_col; i++){
        g_data[i] = (int *)malloc(g_row * sizeof(int));
    }

    for(int i = 0; i < g_col; i++){
        for(int j = 0; j < g_row; j++){
            scanf("%d", &g_data[i][j]);
            a2[i+1][j+1] = a1[i+1][j+1] = g_data[i][j];
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

void init_array(){
    for(int i = 1; i < rowCnt; i++){
        for(int j = 1; j < colCnt; j++){
            a2[i][j] = a1[i][j] = 0;
        }
    }

    for(int i = 0; i < g_col; i++){
        for(int j = 0; j < g_row; j++){
            a2[i+1][j+1] = a1[i+1][j+1] = g_data[i][j];
        }
    }
}

void QueuePrn(queue <ROWCOL> q1){
    while(!q1.empty()){
        printf("(%d,%d) ", q1.front().row, q1.front().col);
        q1.pop();
    }
    printf("\n");
}

void Fill1(int x, int y){
    if( x < 1 || x > rowCnt || y < 1 || y > colCnt || a1[x][y] != 0)
        return;
    a1[x][y] = 2;
    Fill1(x + 1, y);
    Fill1(x - 1, y);
    Fill1(x, y + 1);
    Fill1(x, y - 1);
}

void Fill2(int x, int y){
    if( x < 1 || x > rowCnt || y < 1 || y > colCnt || a2[x][y] != 0)
        return;
    a2[x][y] = 2;
    Fill2(x + 1, y);
    Fill2(x - 1, y);
    Fill2(x, y + 1);
    Fill2(x, y - 1);
}

void Fill3(int x, int y){
    if(x < 1 || x > rowCnt || y < 1 || y > colCnt)
        return;

    if(a2[x][y] == 3 || a2[x][y] == 0){
        a2[x][y] = 2;

        Fill3(x + 1, y);
        Fill3(x - 1, y);
        Fill3(x, y + 1);
        Fill3(x, y - 1);
    }
}

int SideCount(int x, int y){
    int cnt = 0;

    if(a1[x + 1][y] == 2)
        cnt++;
    if(a1[x - 1][y] == 2)
        cnt++;
    if(a1[x][y + 1] == 2)
        cnt++;
    if(a1[x][y - 1] == 2)
        cnt++;

    return cnt;
}

int SideCount2(int x, int y){
    int cnt = 0;

    if(a2[x + 1][y] == 2)
        cnt++;
    if(a2[x - 1][y] == 2)
        cnt++;
    if(a2[x][y + 1] == 2)
        cnt++;
    if(a2[x][y - 1] == 2)
        cnt++;

    return cnt;
}

void Solve1(){
    int i, j, hour = 0, flag;
    printf("Solve1 process\n");
    while(1) {
        Fill1(1,1);
        flag = 0;
        for(i = 1; i <= rowCnt; i++){
            for(j = 1; j <= colCnt; j++){
                if(a1[i][j] == 1 && SideCount(i, j) >= 2){
                    a2[i][j] = 0;
                    flag = 1;
                }
            }
        }

        if(flag == 0){
            printf("hour = %d\n", hour);
            break;
        }
        hour++;
        ArrayPrn();
        memcpy((void *)a1, (void *)a2, sizeof(a2));
    }
}

void Solve2(){
    int i, j, hour = 0, flag;
    printf("Solve2 process\n");
    Fill1(1,1);
    Fill2(1,1);
    ArrayPrn();
    printf("aaaa\n");
    while(1){
        flag = 0;
        for(i = 1; i <= rowCnt; i++){
            for(j = 1; j <= colCnt; j++){
                if(a1[i][j] == 1 && SideCount(i, j) >= 2){
                    a2[i][j] = 0;
                    flag = 1;
                }
            }
        }
        ArrayPrn();
        if(flag == 0){
            printf("hour = %d\n", hour);
            break;
        }

        for(int i = 1; i <= rowCnt; i++){
            for(int j = 1; j <= colCnt; j++){
                if(a1[i][j] == 1 && a2[i][j] == 0){
                    Fill2(i, j);
                }
            }
        }
        hour++;
        memcpy((void *)a1, (void *)a2, sizeof(a2));
    }
}

void Solve3(){
    int i, j, hour = 0, flag;
    printf("Solve3 process\n");
    Fill3(1,1);
    ArrayPrn();
    printf("aaaa\n");
    while(1) {
        flag = 0;
        for(i = 1; i <= rowCnt; i++){
            for(j = 1; j <= colCnt; j++){
                if(a1[i][j] == 1 && SideCount2(i, j) >= 2){
                    a2[i][j] = 3;
                    q.push((ROWCOL){i, j});
                    flag = 1;
                }
            }
        }
        ArrayPrn();
        if(flag == 0) {
            printf("hour = %d\n", hour);
            break;
        }

        ROWCOL cur;
        QueuePrn(q);

        while(!q.empty()){
            cur = q.front();
            q.pop();
            Fill3(cur.row, cur.col);
        }
        hour++;
        memcpy((void *)a1, (void *)a2, sizeof(a2));
    }
}

int main()
{
    Input();
    Solve1();
    init_array();
    Solve2();
    init_array();
    Solve3();
    Solve();
    Output();
    free(g_data);
    return 0;
}
