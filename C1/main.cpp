#include <stdio.h>

using namespace std;

int g_num, g_hap;
int *g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_num);
    fclose(stdin);

    int cnt = 0;

    for(int i = 1; i <= g_num; i++){
        if((g_num % i) == 0){
            cnt++;
        }
    }

    g_data = new int[cnt]();

}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_hap);
    fclose(stdout);
}

void mySolve(){
    int cnt = 0;

    for(int i = 1; i <= g_num; i++){
        if((g_num % i) == 0){
            g_data[cnt] = i;
            cnt++;
        }
    }

    for(int i = 0; i < cnt; i++){
        g_hap += g_data[i];
    }
}

int main()
{
    Input();
    mySolve();
    Output();
    return 0;
}
