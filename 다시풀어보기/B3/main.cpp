#include <stdio.h>
#include <stdlib.h>

using namespace std;

int g_size, g_cnt;
bool **g_check;

// 정답지 풀이
int n, cnt;
bool colChk[10], incChk[20], decChk[20];

void TestPrn(int no, int row, int col){
    printf("%d,%d,%d %d : ", no, row, col, cnt);

    for(int i = 1; i <= n; i++){
        printf("%d ", colChk[i] );
    }
    printf(" : ");
    for(int i = 1; i <= n * 2; i++){
        printf("%d ", incChk[i] );
    }
    printf(" : ");
    for(int i = 1; i <= n * 2; i++){
        printf("%d ", decChk[i] );
    }
    printf("\n");
}

void Dfs(int row){
    if( row > n){
        cnt++;
        return;
    }

    for(int col = 1; col <= n; col++)
    {
        if( !colChk[col] && !incChk[row + col] && !decChk[n + (row - col)] ){
            colChk[col] = incChk[row + col] = decChk[n + (row - col)] = true;
            TestPrn(1, row, col);

            Dfs(row + 1);

            colChk[col] = incChk[row + col] = decChk[n + ( row - col )] = false;
            TestPrn(2, row, col);
        }
    }
}

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
        int m_x1 = x + i;
        int m_y1 = y + i;
        int m_x2 = x - i;
        int m_y2 = y - i;

        if(data[x][i] == 0){
            data[x][i] = 2;
        }

        if(data[i][y] == 0){
            data[i][y] = 2;
        }

        if(m_x1 < g_size && m_y1 < g_size){
            if(data[m_x1][m_y1] == 0){
                data[m_x1][m_y1] = 2;
            }
        }

        if(m_x1 < g_size && m_y2 > -1 ){
            if(data[m_x1][m_y2] == 0){
                data[m_x1][m_y2] = 2;
            }
        }

        if(m_x2 > -1 && m_y1 < g_size){
            if(data[m_x2][m_y1] == 0){
                data[m_x2][m_y1] = 2;
            }
        }

        if(m_x2 > -1 && m_y2 > -1){
            if(data[m_x2][m_y2] == 0){
                data[m_x2][m_y2] = 2;
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

    scanf("%d", &n);
    Dfs(1);
    printf("%d", cnt);

    return 0;
}
