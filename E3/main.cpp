#include <cstdio>

using namespace std;

int g_n, g_r, g_res;

int myFactorial(int n){
    if(n == 1){
        return 1;
    }

    return n * myFactorial(n - 1);
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_n, &g_r);
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_res);
    fclose(stdout);
}

void mySolve(){
    g_res = myFactorial(g_n) / (myFactorial(g_n - g_r) * myFactorial(g_r));
}

int main()
{
    Input();
    mySolve();
    Output();
    return 0;
}
