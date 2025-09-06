#include <cstdio>
#include <vector>
#define SIZE 3

using namespace std;
int g_dis, g_min = 0x0fffffff;
vector<int> g_abl;

void Input(){
    int m_s, m_g;
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &m_s, &m_g);
    for(int i = 0; i < SIZE; i++){
        int m_n;
        scanf("%d", &m_n);
        g_abl.push_back(m_n);
    }
    fclose(stdin);

    g_dis = m_g - m_s;
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

void mySolve(int sum, int cnt){
    if(sum >= g_dis){
        if(cnt < g_min){
            g_min = cnt;
        }
        return;
    }

    for(int i = 0; i < SIZE; i++){
        mySolve(sum + g_abl[i], cnt + 1);
    }
}

int main()
{
    Input();
    mySolve(0, 0);
    Output();
    return 0;
}
