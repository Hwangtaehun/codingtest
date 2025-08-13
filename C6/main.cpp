#include <stdio.h>
#define SIZE 19

using namespace std;
int g_data[SIZE + 2][SIZE + 2];
int g_row, g_col, g_c;

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

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d\n%d %d", g_c, g_col, g_row);
    fclose(stdout);
}

int main()
{
    Input();
    mySolve();
    Output();
    return 0;
}
