#include <cstdio>
#include <vector>
#define SIZE 7

using namespace std;

int g_choo[SIZE] = {1, 3, 9, 27, 81, 243, 729};
int g_used[SIZE] = {0};
int g_num, g_end = 0;
vector<int> g_result;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_num);
    fclose(stdin);
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

int main()
{
    Input();
    mySolve(g_num, 0);
    Output();
    return 0;
}
