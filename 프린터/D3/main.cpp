#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int *g_num;
bool *g_used;
string g_data;
vector<int> g_result;

//solve
int data[1000], dCnt;
int num[6];

void Input(){
    freopen("input.txt", "r", stdin);
    cin >> g_data;
    fclose(stdin);

    g_num = new int[g_data.size()];
    g_used = new bool[g_data.size()];

    for(int i = 0; i < g_data.size(); i++){
        g_num[i] = g_data[i] - '0';
        g_used[i] = false;
    }
    fclose(stdin);
}

void Output(){
    if(g_result.size() == 0){
        g_result.push_back(0);
    }
    sort(g_result.begin(), g_result.end());

    freopen("output.txt", "w", stdout);

    for(int i = 0; i < g_result.size(); i++){
        cout << g_result.at(i) << " ";
    }

    fclose(stdout);
}

bool isSosu(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void mySolve(int cnt, int result){
    if(cnt == g_data.size()){
        if(isSosu(result)){
            if(g_result.size() > 0){
                for(int i = 0; i < g_result.size(); i++){
                    if(g_result[i] == result){
                        return;
                    }
                }
            }
            g_result.push_back(result);
        }
        return;
    }

    for(int i = 0; i < g_data.size(); i++){
        if(!g_used[i]){
            g_used[i] = true;
            mySolve(cnt+1, result*10 + g_num[i]);
            g_used[i] = false;
        }
    }
}

void ArrayPrn(){
    for(int i = 0; i < 6; i++){
        printf("%d ", num[i]);
    }
    printf("\n");
}

void ArrayPrn2(){
    for(int i = 0; i < dCnt; i++){
        printf("%d", data[i]);
    }
    printf("\n");
}

bool isPrime(int k){
    for(int i = 2; i * i <= k; i++){
        if(k % i == 0){
            return false;
        }
    }
    return true;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int SplitNumber(int n){
    int i = 0;
    while(n != 0){
        num[i] = n % 10;
        n /= 10;
        i++;
    }
    return i;
}

void Permutation(int n, int len){
    int i, k = 0, weight = 1;

    if(n == 0){
        for(i = 0; i <= len; i++){
            k += num[i] * weight;
            weight *= 10;
        }
        ArrayPrn();
        data[dCnt++] = k;
        return;
    }
    for(i = n-1; i >= 0; i--){
        swap(&num[i], &num[n-1]);
        Permutation(n-1, len);
        swap(&num[i], &num[n-1]);
    }
}

int main()
{
    int n, len, prev = -1;

    scanf("%d", &n);
    len = SplitNumber(n);
    Permutation(len, len);

    ArrayPrn2();
    sort(data, data+dCnt);
    ArrayPrn2();

    for(int i = 0; i < dCnt; i++){
        if(isPrime(data[i]) && prev != data[i]){
            printf("%d ", data[i]);
            prev = data[i];
        }
    }
    if(prev == -1)
        printf("0");

    Input();
    for(int i = 0; i < g_data.size(); i++){
        g_used[i] = true;
        mySolve(1, g_num[i]);
        g_used[i] = false;
    }
    Output();
    return 0;
}
