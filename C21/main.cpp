#include <cstdio>
#include <algorithm>
#define SIZE 3
using namespace std;

int *g_data, *g_used, g_dif = 0x0FFFFFFF, g_min = 0x0FFFFFFF, g_size;
int g_result[SIZE] = {0};

void Input()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    g_data = new int[g_size];

    for(int i = 0; i < g_size; i++){
        scanf("%d", &g_data[i]);
    }

    fclose(stdin);
}

bool Desc(int left, int right){
    return left > right;
}

void Output()
{
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < SIZE; i++){
        printf("%d ", g_result[i]);
    }
    fclose(stdout);
}

void Testprint()
{
    for(int i = 0; i < g_size; i++){
        printf("%d ", g_used[i]);
    }
    printf("\n");
}

void mySolve(int no, int a, int b, int c)
{
    if(no < g_size){
        mySolve(no + 1, a, b, c+g_data[no]);
        mySolve(no + 1, a, b+g_data[no], c);
        mySolve(no + 1, a+g_data[no], b, c);
    }
    else if(a >= b && b >= c && g_dif >= (a - c) && g_min > a){
        g_min = a;
        g_dif = a - c;
        g_result[0] = a;
        g_result[1] = b;
        g_result[2] = c;
        return;
    }
}

int main()
{
    Input();
    sort(g_data, g_data+g_size, Desc);
    mySolve(0, 0, 0, 0);
    Output();
    return 0;
}
