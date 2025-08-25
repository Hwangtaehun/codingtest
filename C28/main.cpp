#include <cstdio>
#include <vector>

using namespace std;

int g_pum_s, g_car_s, g_min;
vector<int> g_pum, g_car;
bool *g_pum_used;

//solve
int pCnt, fCnt, pump[100001], fire[100000], pv[100001], mh = 0x7fffffff;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_pum_s, &g_car_s);
    pCnt = g_pum_s;
    fCnt = g_car_s;

    g_pum_used = new bool[g_pum_s];

    for(int i = 0; i < g_pum_s; i++){
        int num;
        scanf("%d", &num);
        pump[i + 1] = num;
        g_pum.push_back(num);
        g_pum_used[i] = false;
    }

    for(int i = 0; i < g_car_s; i++){
        int num;
        scanf("%d", &num);
        fire[i + 1] = num;
        g_car.push_back(num);
    }

    fclose(stdin);
}

void Testprint(){
    for(int i = 0; i < g_pum_s; i++){
        printf("%d ", g_pum[i]);
    }
    printf("\n");
    for(int i = 0; i < g_car_s; i++){
        printf("%d ", g_car[i]);
    }
}

void testprint(){
    printf("pCnt = %d, fCnt = %d\n", pCnt, fCnt);
    for(int i = 1; i <= pCnt; i++){
        printf("%d ", pump[i]);
    }
    printf("\n");
    for(int i = 1; i <= fCnt; i++){
        printf("%d ", fire[i]);
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

int nature(int num){
    return num > 0 ? num : -num;
}

int mySolve(int car){
    int m_min = 0x0FFFFFFF, m_index = 0;

    for(int i = 0; i < g_pum_s; i++){
        if(!g_pum_used[i]){
            int m_dis = nature(g_pum[i] - car);
            if(m_dis < m_min){
                m_index = i;
                m_min = m_dis;
            }
        }
    }

    g_pum_used[m_index];

    return m_min;
}

int abs(int a){
    return a > 0 ? a : -a;
}

void Solve(int p, int f, int h)
{
    if(f == fCnt)
    {
        mh = ( mh > h ) ? h : mh;
        return;
    }

    for(int i = 1; i <= pCnt; i++){
        if(pv[i] == 0){
            pv[i] = 1;
            h += abs(pump[i] - fire[f + 1]);
            Solve(i, f + 1, h);
            h -= abs(pump[i] - fire[f + 1]);
            pv[i] = 0;
        }
    }
}

int main()
{
    Input();
    for(int i = 0; i < g_car_s; i++){
        g_min += mySolve(g_car[i]);
    }
    //testprint();
    Solve(0, 0, 0);
    printf("%d\n", mh);
    Output();
    return 0;
}
