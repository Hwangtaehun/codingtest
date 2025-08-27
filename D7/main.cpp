#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> > g_data;
bool *g_used;
int g_size, g_min = 0x7fffffff;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);

    g_used = new bool[g_size];
    g_data.resize(g_size);

    for(int i = 0; i < g_size; i++){
        g_data[i].resize(g_size);
        g_used[i] = false;
    }

    for(int i = 0; i < g_size; i++){
        scanf("%d %d %d", &g_data[i][0], &g_data[i][1], &g_data[i][2]);
    }

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

void mySolve(int n, int sum){
    //printf("n = %d, sum = %d\n", n, sum);
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

int main()
{
    Input();
    mySolve(0, 0);
    Output();
    return 0;
}
