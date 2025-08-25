#include <cstdio>
#include <vector>

using namespace std;

int g_pum_s, g_car_s, g_min;
vector<int> g_pum;
vector<int> g_car;
bool *g_pum_used;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_pum_s, &g_car_s);

    g_pum_used = new bool[g_pum_s];

    for(int i = 0; i < g_pum_s; i++){
        int num;
        scanf("%d", &num);
        g_pum.push_back(num);
        g_pum_used[i] = false;
    }

    for(int i = 0; i < g_car_s; i++){
        int num;
        scanf("%d", &num);
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

int main()
{
    Input();
    for(int i = 0; i < g_car_s; i++){
        g_min += mySolve(g_car[i]);
    }
    Output();
    return 0;
}
