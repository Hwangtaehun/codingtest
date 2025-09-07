#include <cstdio>
#include <vector>

using namespace std;
int g_row, g_col, g_max = 0;
vector< vector<int> > g_data;

//solve
#define MAX(a, b) ((a) >= (b) ? (a) : (b))

int n, m, mine[220][220], table[220][220];

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
    n = g_row;
    m = g_col;

    g_data.resize(g_row + 1);
    for(int i = 0; i < g_row + 1; i++){
        g_data[i].resize(g_col + 1);
    }

    for(int i = 1; i <= g_row; i++){
        for(int j = 1; j <= g_col; j++){
            scanf("%d", &mine[i][j]);
            g_data[i][j] = mine[i][j];
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

int Back(int row, int col){
    if(table[row][col])
        return table[row][col];

    if(row == n && col == m)
        return mine[row][col];

    if(row > n || col > m)
        return 0;

    return table[row][col] = mine[row][col] + MAX(Back(row + 1, col), Back(row, col + 1));
}

void Solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            table[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int a = table[i - 1][j];
            int b = table[i][j - 1];
            table[i][j] = mine[i][j] + MAX(a, b);
        }
    }

    printf("%d", table[n][m]);
}

int main()
{
    Input();
    printf("%d\n", Back(1, 1));
    Solve();
    mySolve(1, 1, 0);
    Output();
    return 0;
}
