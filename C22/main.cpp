#include <cstdio>
#include <algorithm>
#define SIZE 3

using namespace std;

//[0]-start, [1]-goal, [2]-block
int g_size, **g_data, g_cnt;

void Input()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);

    g_data = new int*[g_size];

    for(int i = 0; i < g_size; i++){
        g_data[i] = new int[SIZE];
    }

    for(int i = 0; i < g_size; i++){
        scanf("%d %d", &g_data[i][0], &g_data[i][1]);
        g_data[i][2] = 0;
    }
    fclose(stdin);
}

void Output()
{
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt);
    fclose(stdout);
}

bool Asc(int* a, int* b){
    return a[0] < b[0];
}

void Testprint()
{
    for(int i = 0; i < g_size; i++){
        printf("%2d %2d %2d\n", g_data[i][0], g_data[i][1], g_data[i][2]);
    }
    printf("\n");
}

int block_count(int start, int arrive){
    int m_cnt = 0;

    if(start < arrive){
       for(int i = 0; i < g_size; i++){
            if(g_data[i][2] != -1){
                if(start < g_data[i][0]){
                    if(arrive > g_data[i][1]){
                        m_cnt++;
                    }
                }
            }
        }
    }else{
        for(int i = 0; i < g_size; i++){
            if(g_data[i][2] != -1){
                if(start > g_data[i][0]){
                    if(arrive < g_data[i][1]){
                        m_cnt++;
                    }
                }
            }
        }
    }

    return m_cnt;
}

bool Check(){
    for(int i = 0; i < g_size; i++){
        if(g_data[i][2] > 0){
            //printf("-----\n%d %d\n-----\n", g_data[i][0], g_data[i][1]);
            return false;
        }
    }

    return true;
}

void Solve(){
    while(1){
        int m_index, m_big = 0;

        for(int i = 0; i < g_size; i++){
            if(g_data[i][2] != -1){
                int m_start, m_arrive;
                m_start = g_data[i][0];
                m_arrive = g_data[i][1];
                g_data[i][2] = block_count(m_start, m_arrive);
            }
        }

        //Testprint();

        if(Check()){
            return;
        }

        for(int i = 0; i < g_size; i++){
            if(m_big < g_data[i][2]){
                //printf("i = %d\n", i);
                m_big = g_data[i][2];
                m_index = i;
            }
        }

        g_data[m_index][2] = -1;
        g_cnt++;

        //Testprint();
    }
}

int main()
{
    Input();
    sort(g_data, g_data + g_size, Asc);
    Testprint();
    Solve();
    Output();
    return 0;
}
