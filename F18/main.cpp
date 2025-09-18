#include <cstdio>
#include <vector>

using namespace std;

int g_size, g_min = 0x0FFFFFFF;
vector< vector<int> > g_data;
vector<bool> g_used;

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

int main()
{
    Input();
    printf("%d\n", Solve(0));
    printf("%d\n", f(0, 0));
    mySolve(0, 0);
    Output();
    return 0;
}
