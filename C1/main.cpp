#include <stdio.h>

using namespace std;

int g_num, g_hap;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_num);
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_hap);
    fclose(stdout);
}

void mySolve(){
    for(int i = 1; i <= g_num; i++){
        if((g_num % i) == 0){
            g_hap += i;
        }
    }
}

int main()
{
    Input();
    mySolve();
    Output();
    return 0;
}
