#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> > g_data;
bool *g_used;
int g_size, g_min = 0x7fffffff;

//solve
int m[11][11], col_check[11], gre_check[11], n, min_sol = 0x7FFFFFFF, debugCnt;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    n = g_size;

    g_used = new bool[g_size];
    g_data.resize(g_size);

    for(int i = 0; i < g_size; i++){
        g_data[i].resize(g_size);
        g_used[i] = false;
    }

    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            scanf("%d", &g_data[i][j]);
            m[i][j] = g_data[i][j];
        }
    }

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

void mySolve(int n, int sum){
    if(n == g_size){
        if(sum < g_min){
            g_min = sum;
        }
        return;
    }

    for(int i = 0; i < g_size; i++){
        if(!g_used[i]){
            g_used[i] = true;
            mySolve(n+1, sum + g_data[n][i]);
            g_used[i] = false;
        }
    }
}

void ArrayPrn(int row, int col, int score){
    for(int i = 0; i < n; i++){
        printf("%d ", col_check[i]);
    }
    printf("\t%d %d %d %d\n", row, col, score, min_sol);
}

void Greedy(int row){
    min_sol = 0;

    for(int i = row; i < n; i++){
        int min = 0x7fffffff, k;
        for(int j = 0; j < n; j++){
            if(!gre_check[j] && min > m[i][j]){
                min = m[i][j];
                k = j;
            }
        }
        min_sol += min;
        gre_check[k] = 1;
    }

    printf("%d\n", min_sol);
}

void Solve(int row, int score){
    if(score > min_sol){
        return;
    }

    debugCnt++;

    if(row == n){
        if(score < min_sol){
            min_sol = score;
        }
        return;
    }

    for(int i = 0; i < n; i++){
        if(col_check[i] == 0){
            col_check[i] = 1;
            ArrayPrn(row, i, score);
            Solve(row + 1, score + m[row][i]);
            col_check[i] = 0;
        }
    }
    return;
}

int main()
{
    Input();

    printf("greedy\n");
    Greedy(0);
    printf("\nSolve\n");
    Solve(0, 0);
    printf("%d", min_sol);
    printf("\ndebugCnt = %d\n", debugCnt);

    mySolve(0, 0);
    Output();
    return 0;
}
