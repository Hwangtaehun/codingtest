#include <cstdio>
#include <vector>

using namespace std;

int g_size, g_min = 0x0FFFFFFF;
vector< vector<int> > g_data;
vector<bool> g_used;

//solve
#define INF 987654321
int m[21][21], DT[1 << 20], col_check[21], n, bit;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);

    g_data.resize(g_size);
    g_used.resize(g_size);

    for(int i = 0; i < g_size; i++){
        g_data[i].resize(g_size);
        g_used[i] = false;
        for(int j = 0; j < g_size; j++){
            scanf("%d", &g_data[i][j]);
            m[i][j] = g_data[i][j];
        }
    }
    fclose(stdin);

    n = g_size;
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

void Print(){
    printf("%d\n", g_size);
    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            printf("%d ", g_data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mySolve(int index, int sum){
    if(index == g_size){
        if(sum < g_min){
            g_min = sum;
        }
        return;
    }

    for(int i = 0; i < g_size; i++){
        if(!g_used[i]){
            g_used[i] = true;
            mySolve(index + 1, sum + g_data[index][i]);
            g_used[i] = false;
        }
    }
}

int Min(int a, int b){
    return a > b ? b : a;
}

int Solve(int row){
    int ans = INF;

    if(row == n){
        return 0;
    }

    for(int i = 0; i < n; i++){
        if(col_check[i] == 0){
            col_check[i] = 1;
            ans = Min(ans, Solve(row + 1) + m[row][i]);
            col_check[i] = 0;
        }
    }

    return ans;
}

int f(int row, int bit){
    if(row == n){
        return 0;
    }

    if(DT[bit] == 0){
        DT[bit] = INF;
        for(int i = 0; i < n; i++){
            if((bit & (1 << i)) == 0){
                DT[bit] = Min(DT[bit], f(row + 1, bit + (1 << i)) + + m[row][i]);
            }
        }
    }

    return DT[bit];
}

int main()
{
    Input();
    printf("%d\n", Solve(0));
    printf("%d\n", f(0, 0));
    mySolve(0, 0);
    Output();
    return 0;
}
