#include <cstdio>
#include <vector>
#define SIZE 7

using namespace std;

int g_choo[SIZE] = {1, 3, 9, 27, 81, 243, 729};
int g_used[SIZE] = {0};
int g_num, g_end = 0;
vector<int> g_result;

//solve
int scale[SIZE] = {1, 3, 9, 27, 81, 243, 729};
int outScale[SIZE + 2];
int three[SIZE];
int n, x;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_num);
    fclose(stdin);
    n = g_num;
    outScale[x++] = n;
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_result.size(); i++){
        printf("%d ", g_result.at(i));
    }
    fclose(stdout);
}

bool Check(){
    for(int i = 0; i < SIZE; i++){
        if(!g_used[i]){
            return false;
        }
    }

    return true;
}

void mySolve(int left, int right){
    if(g_end){
        return;
    }

    if(left == right){
        g_end = 1;
        g_result.push_back(g_num);
        for(int i = 0; i < SIZE; i++){
            if(g_used[i] == -1){
                g_result.push_back(g_choo[i]);
            }
        }

        g_result.push_back(0);

        for(int i = 0; i < SIZE; i++){
            if(g_used[i] == 1){
                g_result.push_back(g_choo[i]);
            }
        }
        return;
    }

    for(int i = 0; i < SIZE; i++){
        if(!g_used[i]){
            g_used[i] = -1;
            mySolve(left + g_choo[i], right);
            g_used[i] = 1;
            mySolve(left, right + g_choo[i]);
            g_used[i] = 0;
        }
    }
}

void ArrayPrn(){
    for(int i = 6; i >= 0; i--){
        printf("%d ", three[i]);
    }
    printf("\n");
}

void toThree(int num){
    //printf(" %d \t", num);
    for(int i = 0; num != 0; i++){
        three[i] = num % 3;
        num /= 3;
    }
    //ArrayPrn();
}

bool isTwo(){
    for(int i = 0; i < SIZE; i++){
        if(three[i] == 2){
            n = n + scale[i];
            outScale[x++] = scale[i];
            return true;
        }
    }
    return false;
}

int main()
{
    Input();
    do{
        toThree(n);
    }while(isTwo());

    x++;

    for(int i = 0; i < SIZE; i++){
        if(three[i] == 1){
            outScale[x++] = scale[i];
        }
    }

    for(int i = 0; i < x; i++){
        printf("%d ", outScale[i]);
    }

    mySolve(g_num, 0);
    Output();
    return 0;
}
