#include <stdio.h>
#define SIZE 19

using namespace std;
int g_data[SIZE + 2][SIZE + 2];
int g_row, g_col, g_c;
int g_dcol[4] = {1, 1, 0, -1}, g_drow[4] = {1, 0, 1, 1};

void Input(){
    freopen("input.txt", "r", stdin);
    for(int i = 1;  i <= SIZE ; i++){
        for(int j = 1; j <= SIZE; j++){
            scanf("%d", &g_data[i][j]);
        }
    }
    fclose(stdin);
}

bool isSafe(int col, int row){
    return (col > 0 && col <= SIZE) && (row > 0  && row <= SIZE);
}

bool mySearch1(int col, int row, int clr){
    for(int i = 1; i < 5; i++){
        if(!isSafe(col + i, row + i) || g_data[col + i][row + i] != clr){
            return false;
        }
    }
    return true;
}

bool mySearch2(int col, int row, int clr){
    for(int i = 1; i < 5; i++){
        if(!isSafe(col + i, row) || g_data[col + i][row] != clr){
            return false;
        }
    }
    return true;
}

bool mySearch3(int col, int row, int clr){
    for(int i = 1; i < 5; i++){
        if(!isSafe(col, row + i) || g_data[col][row + i] != clr){
            return false;
        }
    }
    return true;
}

bool mySearch4(int col, int row, int clr){
    for(int i = 1; i < 5; i++){
        if(!isSafe(col - i, row + i) || g_data[col - i][row + i] != clr){
            return false;
        }
    }
    return true;
}

void mySolve(){
    for(int i = 1; i <= SIZE; i++){
        for(int j = 1; j <= SIZE; j++){
            if(g_data[i][j] != 0){
                if(mySearch1(i, j, g_data[i][j]) || mySearch2(i, j, g_data[i][j]) || mySearch3(i, j, g_data[i][j]) || mySearch4(i, j, g_data[i][j])){
                    g_c = g_data[i][j];
                    g_row = j;
                    g_col = i;
                }
            }
        }
    }
}

int search1(int color, int i, int j){
    int cnt = 1;

    while(color == g_data[i][j + 1]){
        cnt++;
        j++;
    }

    return cnt;
}

int search2(int color, int i, int j){
    int cnt = 1;

    while(color == g_data[i + 1][j + 1]){
        cnt++;
        i++, j++;
    }

    return cnt;
}

int search3(int color, int i, int j){
    int cnt = 1;

    while(color == g_data[i + 1][j]){
        cnt++;
        i++;
    }

    return cnt;
}

int search4(int color, int i, int j){
    int cnt = 1;

    while(color == g_data[i - 1][j + 1]){
        cnt++;
        i--, j++;
    }

    return cnt;
}

int Search(int color, int i, int j, int d){
    int cnt = 0;

    while(color == g_data[i][j]) {
        i += g_dcol[d];
        j += g_drow[d];
        cnt++;
    }

    return cnt;
}

void Solve(){
    int i, j;
    for(i = 1; i <= 19; i++){
        for(j = 1; j <= 19; j++){
            if(g_data[i][j] != 0){
                if(g_data[i][j-1] != g_data[i][j] && search1(g_data[i][j], i, j) == 5){
                    printf("%d\n%d %d", g_data[i][j], i, j);
                    return;
                }

                if(g_data[i-1][j-1] != g_data[i][j] && search2(g_data[i][j], i, j) == 5){
                    printf("%d\n%d %d", g_data[i][j], i, j);
                    return;
                }

                if(g_data[i-1][j] != g_data[i][j] && search3(g_data[i][j], i, j) == 5){
                    printf("%d\n%d %d", g_data[i][j], i, j);
                    return;
                }

                if(g_data[i+1][j-1] != g_data[i][j] && search4(g_data[i][j], i, j) == 5){
                    printf("%d\n%d %d", g_data[i][j], i, j);
                    return;
                }
            }
        }
    }
}

void Other_Solve(){
    int i, j;
    for(i = 1; i <= 19; i++){
        for(j = 1; j <= 19; j++){
            if(g_data[i][j] != 0){
                for(int d = 0; d < 4; d++){
                    if(g_data[ i - g_dcol[d] ][ j - g_drow[d] ] !=  g_data[i][j] && Search(g_data[i][j], i, j, d) == 5){
                        printf("%d\n%d %d", g_data[i][j], i, j);
                        return;
                    }
                }
            }
        }
    }
    printf("0");
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d\n%d %d", g_c, g_col, g_row);
    fclose(stdout);
}

int main()
{
    Input();
    mySolve();
    Solve();
    printf("\n");
    Other_Solve();
    Output();
    return 0;
}
