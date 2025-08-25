#include <cstdio>
#include <ctime>

using namespace std;

int g_num, g_result;

//solve
int n;

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

bool isPrime(int k){
    for(int i = 2; i * i <= k; i++){
        if(k % i == 0)
            return false;
    }
    return true;
}

void Prime1(){
    int i, cnt = 0;
    for(int i = 2; i < 100000; i++){
        if(isPrime(i)){
            cnt++;
            if(cnt == n)
                break;
        }
    }
    printf("%d\n", i);
}

void Prime2(){
    int i, j, num, array[100001] = {0}, cnt = 0;
    for(i = 2; i < 100000; i++){
        array[i] = i;
    }
    for(i = 2; i <= 100000; i++){
        if(array[i] != 0){
            cnt++;
            if(cnt >= n)
                break;
            for(j = i + i; j <= 100000; j += i){
                array[i] = 0;
            }
        }
    }
    printf("%d\n", i);
}

int main()
{
    //Input();
    //mySolve();
    //Output();

    scanf("%d", &n);
    printf("clock()\t = %d\n", clock());

    Prime1();
    printf("clock()\t = %d\n", clock());

    Prime2();
    printf("clock()\t = %d\n", clock());
    return 0;
}
