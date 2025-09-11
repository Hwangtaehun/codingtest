#include <cstdio>
#include <vector>

using namespace std;

int g_n, g_m, g_a, g_b, g_x, g_y, g_min = 0x0FFFFFFF; // a: start, b: goal, x: remove, y: add
vector<int> g_line;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_n, &g_m);
    scanf("%d %d %d %d", &g_a, &g_b, &g_x, &g_y);
    for(int i = 0; i < g_m; i++){
        int t;
        scanf("%d", &t);
        g_line.push_back(t);
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

int Move(int index, int cur){

    if(g_line[index] == cur){
        cur = g_line[index] + 1;
    }else if(g_line[index] + 1 == cur){
        cur = g_line[index];
    }

    return cur;
}

void mySolve(int cur, int index, int cost){
    if(g_min < cost){
        return;
    }

    if(index == g_line.size() - 1){
        if(cur > g_b){
            g_line.push_back(cur - 1);
            cost += g_y;
        }else if(cur < g_b){
            g_line.push_back(cur);
            cost += g_y;
        }
    }

    if(index == g_line.size()){
        if(cur == g_b){
            if(cost < g_min){
                g_min = cost;
            }
        }
        return;
    }

    int m_cur = Move(index, cur);

    mySolve(cur, index + 1, cost + g_x);
    mySolve(m_cur, index + 1, cost);
}

int main()
{
    Input();
    mySolve(g_a, 0, 0);
    Output();
    return 0;
}
