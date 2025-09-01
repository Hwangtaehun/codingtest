#include <cstdio>
#include <vector>
#define SIZE 3

using namespace std;

int g_size, g_rest, g_result;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_rest);
    fclose(stdin);

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

int main()
{
    Input();
    //Print();
    g_result = mySolve(g_size);
    Output();
    return 0;
}
