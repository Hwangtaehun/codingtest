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

int main()
{
    Input();
    for(int i = 0; i < g_data.size(); i++){
        g_used[i] = true;
        mySolve(1, g_num[i]);
        g_used[i] = false;
    }
    Output();
    return 0;
}
