#include <cstdio>
#include <vector>

using namespace std;
int g_row, g_col, g_max = 0;
vector< vector<int> > g_data;

void Print(){
    for(int i = 1; i < g_row + 1; i++){
        for(int j = 1; j < g_col + 1; j++){
            printf("%d", g_data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_row, &g_col);

    g_data.resize(g_row + 1);
    for(int i = 0; i < g_row + 1; i++){
        g_data[i].resize(g_col + 1);
    }

    for(int i = 0; i < g_row; i++){
        for(int j = 0; j < g_col; j++){
            int t;
            scanf("%d", &t);
            g_data[i + 1][j + 1] = t;
        }
    }

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_max);
    fclose(stdout);
}

void mySolve(int i, int j, int cnt){
    if(i > g_row || j > g_col){
        return;
    }else if(i == g_row && j == g_col){
        if(g_max < cnt){
            g_max = cnt;
        }
        return;
    }

    if(g_data[i][j]){
        cnt += 1;
    }

    mySolve(i + 1, j, cnt);
    mySolve(i, j + 1, cnt);
}

int main()
{
    Input();
    mySolve(1, 1, 0);
    Output();
    return 0;
}
