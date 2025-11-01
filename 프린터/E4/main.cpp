#include <cstdio>
#include <vector>
#define SIZE 3

using namespace std;

int g_size, g_rest, g_result;
//solve
int n, m;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_rest);
    fclose(stdin);
    n = g_size;
    m = g_rest;

}

void Output(){
    g_result = g_result % g_rest;
    freopen("output.txt", "w", stdout);
    printf("%d", g_result);
    fclose(stdout);
}

int mySolve(int i){
    if(i == 1)
        return 1;
    else if(i == 2)
        return 3;
    else
        return mySolve(i - 1) + 2 * mySolve(i - 2);
}

int Solve1(int k){
    if(k <= 1)
        return 1;
    else
        return (Solve1(k - 1) + 2 * Solve1(k - 2));
}

int Solve2(int k){
    if(k <= 1)
        return 1;
    else
        return (Solve2(k - 1) + 2 * Solve2(k - 2)) % m;
}

int Solve3(int k){
    if(k <= 1)
        return 1;
    else if(k % 2)
        return (Solve3(k - 1) + 2 * Solve3(k - 2)) % m;
    else
        return (Solve3(k / 2) * Solve3(k / 2) + 2 * Solve3(k / 2 - 1) * Solve3(k / 2 - 1)) % m;
}

long long int Solve4(int k){
    if(k <= 1)
        return 1 % m;
    else if(k % 2)
        return (Solve4(k / 2) * Solve4(k / 2 + 1) + 2 * Solve4(k / 2) * Solve4(k / 2 - 1)) % m;
    else
        return (Solve4(k / 2) * Solve4(k / 2) + 2 * Solve4(k / 2 - 1) * Solve4(k / 2 - 1)) % m;
}

int main()
{
    Input();
    //Print();
    g_result = mySolve(g_size);
    printf("%d\n", Solve1(n));
    printf("%d\n", Solve2(n));
    printf("%d\n", Solve3(n));
    printf("%d\n", Solve4(n));
    Output();
    return 0;
}
