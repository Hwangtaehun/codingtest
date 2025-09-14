#include <cstdio>
#include <vector>

using namespace std;

int g_row, g_col;
vector<vector <int> > g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_row, &g_col);
    fclose(stdin);
    g_data.resize(g_row + 1);
    for(int i = 0; i <= g_row; i++){
        g_data[i].resize(g_col + 1);
    }
    g_data[0][0] = 1;
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_data[g_row][g_col]);
    fclose(stdout);
}

void Print(){
    printf("%d %d\n", g_row, g_col);
    for(int i = 0; i <= g_row; i++){
        for(int j = 0; j <= g_col; j++){
            printf("%d ", g_data[i][j]);
        }
        printf("\n");
    }
}

bool Check(int r, int c){
    if(0 <= r && r <= g_row && 0 <= c && c <= g_col){
        return true;
    }
    return false;
}

bool Avail(int r, int c){
    if(!c || (double)g_row/g_col <= (double)r/c){
        return true;
    }
    return false;
}

void mySolve(){
    for(int i = 1; i <= g_row; i++){
        for(int j = 0; j <= g_col; j++){
            if(Avail(i, j) || j == g_col){
                int a = 0, b = 0;
                if(Check(i - 1, j)){
                    a = g_data[i - 1][j];
                }
                if(Check(i, j - 1)){
                    b = g_data[i][j - 1];
                }
                g_data[i][j] = a + b;
            }
        }
    }
}

int main()
{
    Input();
    mySolve();
    Output();
    return 0;
}
