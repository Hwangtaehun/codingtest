#include <stdio.h>
#include <math.h>
#include <queue>

using namespace std;

queue <int> g_data;
int g_gari, g_cnt = 0;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_gari);
    fclose(stdin);
}

bool sosu(int num){
    if(num == 1){
        return false;
    }

    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void mySolve(int origin, int num, int gari){
    if(sosu(num / 10)){
        if(gari == 1){
            g_data.push((int)origin);
            g_cnt++;
            return;
        }
       mySolve(origin, num / 10, gari - 1);
    }else{
        return;
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    while(!g_data.empty()){
        printf("%d\n", g_data.front());
        g_data.pop();
    }
    printf("%d", g_cnt);
    fclose(stdout);
}

int main()
{
    Input();
    int m_max = pow(10, g_gari);
    int m_min = pow(10, g_gari - 1);

    for(int i = m_min; i < m_max; i++){
        if(sosu(i)){
            mySolve(i, i, g_gari - 1);
        }
    }
    Output();
    return 0;
}
