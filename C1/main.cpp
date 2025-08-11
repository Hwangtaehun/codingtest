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

int Divisor1(){
    int i, bound = g_num/2, tot = 1 + g_num;

    for(i = 2; i <= bound; i++){
        if( g_num%i == 0){
            tot += i;
        }
    }

    return tot;
}

int Divisor2(){
    int i, tot = 0;

    for(i = 1; i * i < g_num; i++){
        if (g_num%i == 0){
            tot += (i + g_num / i);
        }
    }

    if(i*i == g_num){
        tot += i;
    }

    return tot;
}

int main()
{
    Input();
    mySolve();
    printf("%d\n", Divisor1());
    printf("%d\n", Divisor2());

    Output();
    return 0;
}
