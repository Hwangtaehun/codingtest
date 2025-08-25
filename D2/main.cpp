#include <cstdio>

using namespace std;

int g_num, g_result;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_num);
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_result);
    fclose(stdout);
}

bool sosu(int num){
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void mySolve(){
    int cnt = 0;

    for(int i = 1; i <= 100000; i++){
        if(sosu(i)){
            cnt++;
            if(cnt > g_num){
                g_result = i;
                return;
            }
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
