#include <cstdio>
#include <vector>
#define SIZE 2

using namespace std;

int g_cnt, g_weight, g_max = 0;
vector<vector <int> > g_data;
bool *g_used;

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_cnt, &g_weight);
    g_data.resize(g_cnt);
    g_used = new bool[g_cnt];

    for(int i = 0; i < g_cnt; i++){
        g_data[i].resize(SIZE);
        g_used[i] = false;
    }

    for(int i = 0; i < g_cnt; i++){
        int t_wi, t_vi;
        scanf("%d %d", &t_wi, &t_vi);
        g_data[i][0] = t_wi; //무게
        g_data[i][1] = t_vi; //가격
    }

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_max);
    fclose(stdout);
}

void mySolve(int w, int v){ //w:무게, v:가격
    if(w <= g_weight){
        if(v > g_max){
            g_max = v;
        }
    }else{
        return;
    }

    for(int i = 0; i < g_cnt; i++){
        if(!g_used[i]){
            g_used[i] = true;
            mySolve(w + g_data[i][0], v + g_data[i][1]);
            g_used[i] = false;
        }
    }
}

int main()
{
    Input();
    mySolve(0, 0);
    Output();
    return 0;
}
