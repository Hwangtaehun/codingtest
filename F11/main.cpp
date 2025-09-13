#include <cstdio>
#include <vector>

using namespace std;

int g_size, g_rest, g_com;
int *g_case;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_rest);
    fclose(stdin);
    g_case = new int[g_size + 1];
    for(int i = 0; i <= g_size; i++){
        g_case[i] = 0;
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_com);
    fclose(stdout);
}

int mySolve(int num){
    if(num == 0){
        g_case[num] = 1;
        return g_case[num];
    }else if(num == 1){
        g_case[num] = 1;
        return g_case[num];
    }else{
        g_case[num] = 2 * mySolve(num - 2) + mySolve(num - 1);
        return g_case[num];
    }
}

int main()
{
    Input();
    g_com = mySolve(g_size) % g_rest;
    Output();
    return 0;
}
