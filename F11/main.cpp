#include <cstdio>
#include <vector>

using namespace std;

int g_size, g_rest, g_com;
vector<int> g_case;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_rest);
    fclose(stdin);
    g_case.resize(g_size);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_com);
    fclose(stdout);
}

int mySolve(int num){
    if(num == 0){
        //g_case[num] = 1;
        return 1;
    }else if(num == 1){
        //g_case[num] = 1;
        return 1;
    }else{
        //g_case[num] = 2 * mySolve(num - 2) + mySolve(num - 1);
        return 2 * mySolve(num - 2) + mySolve(num - 1);
    }
}

int main()
{
    Input();
    g_com = mySolve(g_size) % g_rest;
    Output();
    return 0;
}
