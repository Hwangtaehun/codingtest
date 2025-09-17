#include <cstdio>
#include <vector>
#define SIZE 3

using namespace std;

int g_size, g_dis = 0x0FFFFFFF, g_min = 0x0FFFFFFF;
vector<bool> g_used;
vector<int> g_data, g_result;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    g_data.resize(g_size);
    g_used.resize(g_size);
    for(int i = 0; i < g_size; i++){
        scanf("%d", &g_data[i]);
        g_used[i] = false;
    }
    fclose(stdin);
    g_result.resize(SIZE);
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_result.size(); i++){
        printf("%d ", g_result[i]);
    }
    fclose(stdout);
}

void Switch(int *a, int *b, int *c){
    int temp;

    if(*a < *b){
        temp = *a;
        *a = *b;
        *b = temp;
    }

    if(*b < *c){
        temp = *b;
        *b = *c;
        *c = temp;
    }

    if(*a < *b){
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

void mySolve(int i, int a, int b, int c){
    if(i == g_size){
        Switch(&a, &b, &c);

        if((a - c) <= g_dis){
            if(a <= g_min){
                g_min = a;
                g_dis = a - c;
                g_result[0] = a;
                g_result[1] = b;
                g_result[2] = c;
            }
        }
        return;
    }

    mySolve(i + 1, a + g_data[i], b, c);
    mySolve(i + 1, a, b + g_data[i], c);
    mySolve(i + 1, a, b, c + g_data[i]);
}

int main()
{
    Input();
    mySolve(0, 0, 0, 0);
    Output();
    return 0;
}
