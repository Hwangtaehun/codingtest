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

void Solve1(int n, int k){
    int i, p = 1, q = 1, r = 1;

    for(i = 1; i <= n; i++){
        p = p * i;
    }

    for(i = 1; i <= k; i++){
        q = q * i;
    }

    for(i = 1; i <= n - k; i++){
        r = r * i;
    }

    printf("%dC%d = %d\n", n, k, p / (q * r));

    p = 1;
    for(i = n - k + 1; i <= n; i++){
        p = p * i;
    }
    printf("%dC%d = %d\n", n, k, p / q);

    p = 1;
    for(i = 1; i <= k; i++){
        p = p * (n - i + 1) / i;
    }
    printf("%dC%d = %d\n", n, k, p);
}

int Solve2(int n, int k){
    if(k == n){
        return 1;
    }else if(k == 1){
        return n;
    }else{
        return Solve2(n - 1, k - 1) + Solve2(n - 1, k);
    }
}

int Solve3(int n, int k){
    if(k == n){
        return 1;
    }else if(k == 1){
        return n;
    }else{
        return Solve3(n, k - 1) * (n - k + 1) / k;
    }
}

int main()
{
    int n, k;
    Input();
    n = g_n;
    k = g_r;
    Solve1(n, k);
    printf("%d\n", Solve2(n, k));
    printf("%d\n", Solve3(n, k));
    mySolve();
    Output();
    return 0;
}
