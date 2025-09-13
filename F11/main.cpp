#include <cstdio>
#include <vector>

using namespace std;

int g_size, g_rest, g_com;
int *g_case;

//solve
#include <memory.h>
int coin[10], DT[100001], n, m;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_rest);
    n = g_size;
    m = g_rest;
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
        if(g_case[num] == 0){
           g_case[num] = 2 * mySolve(num - 2) + mySolve(num - 1);
        }
        return g_case[num];
    }
}

int f1(int c){
    if(c == 1)
        return DT[c] = 1 % m;
    else if(c == 2)
        return DT[c] = 3 % m;
    else{
        if(DT[c] == 0){
            DT[c] = (f1(c - 1) + 2 * f1(c - 2)) % m;
        }
        return DT[c];
    }
}

int Min(int a, int b){
    return a > b ? b : a;
}

int f2(int c){
    if(c == m)
        return DT[c] = 0;
    if(DT[c] == 0){
        DT[c] == 987654321;

        for(int i = 0; i < n; i++){
            if(c + coin[i] <= m){
                DT[c] = Min(DT[c], f2(c + coin[i]) + 1);
            }
        }
    }
    return DT[c];
}

int main()
{
    Input();
    printf("%d\n", f1(n));
    memset(DT, 0, sizeof(DT));
    printf("%d\n", f2(0));
    g_com = mySolve(g_size) % g_rest;
    Output();
    return 0;
}
