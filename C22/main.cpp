#include <cstdio>
#include <algorithm>
#define SIZE 2

using namespace std;

int g_size, **g_data, g_cnt;

void Input()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);

    g_data = new int*[g_size];

    for(int i = 0; i < g_size; i++){
        g_data[i] = new int[SIZE];
    }

    for(int i = 0; i < g_size; i++){
        scanf("%d %d", &g_data[i][0], &g_data[i][1]);
    }
    fclose(stdin);
}

void Output()
{
    //freopen("output.txt", "w", stdout);
    printf("%d", g_cnt);
    //fclose(stdout);
}

bool Asc(int* a, int* b){
    return a[0] < b[0];
}

void Testprint()
{
    for(int i = 0; i < g_size; i++){
        printf("%d %d\n", g_data[i][0], g_data[i][1]);
    }
}

void Solve(){
}

int main()
{
    Input();
    sort(g_data, g_data + g_size, Asc);
    return 0;
}
