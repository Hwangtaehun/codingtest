#include <cstdio>
#include <vector>

using namespace std;

struct ROWCOL{
    int x;
    int y;
};

int g_size, g_cnt, g_dis = 0;
vector<ROWCOL> g_route; // -1:place
vector<ROWCOL> g_car;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_cnt);
    for(int i = 0; i < g_cnt; i++){
        int m_x, m_y;
        scanf("%d %d", &m_x, &m_y);
        g_route.push_back((ROWCOL){m_x, m_y});
    }
    fclose(stdin);

    g_car.push_back((ROWCOL){1, 1});
    g_car.push_back((ROWCOL){g_size, g_size});
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_dis);
    fclose(stdout);
}

int Abs(int num){
    if(num < 0){
        return -num;
    }else{
        return num;
    }
}

void mySolve(){
    for(int i = 0; i < g_route.size(); i++){
        int m_dis1 = g_car[0].x - g_route[i].x + g_car[0].y - g_route[i].y;
        int m_dis2 = g_car[1].x - g_route[i].x + g_car[1].y - g_route[i].y;
        m_dis1 = Abs(m_dis1);
        m_dis2 = Abs(m_dis2);

        if(m_dis1 < m_dis2){
            g_dis += m_dis1;
            g_car[0].x = g_route[i].x;
            g_car[0].y = g_route[i].y;
        }else{
            g_dis += m_dis2;
            g_car[1].x = g_route[i].x;
            g_car[1].y = g_route[i].y;
        }
    }
}

int main()
{
    Input();
    mySolve();
    Output();
    return 0;
}
