#include <stdio.h>
#include <math.h>
#include <time.h>
#include <queue>

using namespace std;

queue <int> g_data;
int g_gari, g_cnt = 0;
int n, cnt;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_gari);
    fclose(stdin);
    n = g_gari;
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

int isprime1(int x){
    if(x < 2)
        return 0;
    if(x == 2)
        return 1;
    if(x % 2 == 0)
        return 0;
    for(int i = 3; i * i <= x; i += 2){
        if(x % i == 0)
            return 0;
    }
    return 1;
}

int isprime2(int x){
    for(int i = 2; i * i < = x; i++)
        if( x % i == 0 )
            return 0;
    return 1;
}

void Solve1(int num, int len){
    if(len == n){
        if(num == 0)
            return;

        int flag = 1;
        int temp = num;

        whlie(temp){
            if(!isprime1(temp))
                return;
            temp /= 10;
        }
        cnt++
        printf("%d\n", num);
        return;
    }else{
        for(int i = 1; i <= 9; i++){
            Solve1(num * 10 + i, len + 1);
        }
    }
}

void Solve2(int num, int len){
    if(len == n){
        if(isprime2(num)){
            cnt++;
            printf("%d\n", num);
        }
        return;
    }else{
        if(isprime2(num)){
            Solve2(num*10 + 1, len + 1);
            Solve2(num*10 + 3, len + 1);
            Solve2(num*10 + 7, len + 1);
            Solve2(num*10 + 9, len + 1);
        }
    }
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
    int start = clock();
    int m_max = pow(10, g_gari);
    int m_min = pow(10, g_gari - 1);

    for(int i = m_min; i < m_max; i++){
        if(sosu(i)){
            mySolve(i, i, g_gari - 1);
        }
    }
    printf("first clock = %d\n", clock() - start);

    start = clock();
    Solve1(0, 0);
    printf("%d\n\n", cnt);
    printf("second clock = %d\n", clock() - start);

    start = clock();
    cnt = 0;
    Solve2(2, 1);
    Solve2(3, 1);
    Solve2(5, 1);
    Solve2(7, 1);
    printf("%d\n\n", cnt);
    printf("third clock = %d\n", clock() - start);

    Output();
    return 0;
}
