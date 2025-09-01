#include <cstdio>
#include <vector>
#define SIZE 2

using namespace std;

vector< vector<int> > g_data;
int g_size, g_rest, g_result;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_rest);
    fclose(stdin);

    g_data.resize(SIZE);
    for(int i = 0; i < SIZE; i++){
        g_data[i].resize(g_size);
    }
}

void Output(){
    //g_result = g_result % g_rest;
    //freopen("input.txt", "r", stdin);
    printf("%d", g_result);
    //fclose(stdin);
}

void Print(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < g_size; j++){
            printf("%d ", g_data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool myCheck(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < g_size; j++){
            if(!g_data[i][j]){
                return false;
            }
        }
    }
    return true;
}

void mySolve(int i){
    //Print();
    if(myCheck()){
        g_result++;
        printf("g_result = %d\n", g_result);
        return;
    }

    g_data[0][i] = 1;
    g_data[1][i] = 1;
    mySolve(i + 1);
    g_data[0][i] = 0;
    g_data[1][i] = 0;

    if(i + 1 < g_size){
        g_data[0][i] = 1;
        g_data[0][i + 1] = 1;
        g_data[1][i] = 1;
        g_data[1][i + 1] = 1;
        mySolve(i + 2);
        g_data[0][i] = 0;
        g_data[0][i + 1] = 0;
        g_data[1][i] = 0;
        g_data[1][i + 1] = 0;

        g_data[0][i] = 1;
        g_data[0][i + 1] = 1;
        g_data[1][i] = 1;
        g_data[1][i + 1] = 1;
        mySolve(i + 3);
        g_data[0][i] = 0;
        g_data[0][i + 1] = 0;
        g_data[1][i] = 0;
        g_data[1][i + 1] = 0;
    }
}

int main()
{
    Input();
    //Print();
    mySolve(0);
    Output();
    return 0;
}
