#include <cstdio>

using namespace std;

int *g_data, g_size, g_endSw = 0;
int g_num[3] = {1, 2, 3};

void Input()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    fclose(stdin);

    g_data = new int[g_size];

    for(int i = 0; i < g_size; i++){
        g_data[i] = 0;
    }
}

bool isSame(int a, int b){
    for(int i = a; i < a + b; i++){
        //printf("g_data[%d], g_data[%d]\n", i, i + b);
        if(g_data[i] != g_data[i+b]){
            return false;
        }
    }
    return true;
}

bool isGood1(int pos){
    for(int i = 1; i <= pos/2; i++){
        for(int j = 1; j <= pos - i; j++){
            //printf("j = %d, i = %d\n", j, i);
            if(isSame(j, i))
                return false;
        }
    }
    return true;
}

int isGood2(int pos){
    for(int j = pos - 1, i = 1; j > 0; j -= 2, i++){
        printf("j = %d, i = %d\n", j, i);
        if(isSame(j, i)){
            return 0;
        }
    }
    return 1;
}

void Solve(int pos){
    if(pos > g_size){
        g_endSw = 1;
        return;
    }

    for(int i = 1; i <= 3; i++){
        g_data[pos] = i;
        if(isGood2(pos))
            Solve(pos + 1);
        if(g_endSw == 1)
            return;
        g_data[pos] = 0;
    }
}

void Output()
{
    freopen("output.txt", "w", stdout);
    for(int i = 1; i <= g_size; i++){
        printf("%d", g_data[i]);
    }
    fclose(stdout);
}

int main()
{
    Input();
    Solve(1);
    Output();
    return 0;
}
