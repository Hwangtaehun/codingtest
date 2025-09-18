#include <cstdio>
#include <vector>
#define COL 3
#define END 15
#define MOD 1000

using namespace std;

int g_size, g_cnt;
vector< vector<int> > g_data;
vector<bool> g_visited;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    g_data.resize(g_size);
    g_visited.resize(g_size);
    for(int i = 0; i < g_size; i++){
        g_data[i].resize(COL);
        g_visited[i] = false;
        scanf("%d %d %d", &g_data[i][0], &g_data[i][1], &g_data[i][2]);
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt % MOD);
    fclose(stdout);
}

void Print(){
    printf("%d\n", g_size);
    for(int i = 0; i < g_size; i++){
        printf("%d %d %d\n", g_data[i][0], g_data[i][1], g_data[i][2]);
    }
}

bool Check(int num){
    if(num >= 0 && num <= END){
        return true;
    }
    return false;
}

int Index(int num){
    for(int i = 0; i < g_size; i++){
        if(g_data[i][0] == num){
            return i;
        }
    }

    return -1;
}

void mySolve(int i, bool a){
    int m_dis = 0;
    int m_index;

    if(i == 0 && a){
        g_cnt++;
        return;
    }

    if(i == g_size - 1 && !a){
        a = true;
        g_visited[0] = false;
    }

    if(a){
        m_dis = g_data[i][0] - g_data[i][1];
        if(!Check(m_dis)){
            m_dis = 0;
        }

        for(int j = g_data[i][0] - 1; j >= m_dis; j--){
            m_index = Index(j);
            if((m_index != -1 && g_data[m_index][2]) && !g_visited[m_index]){
                g_visited[m_index] = true;
                mySolve(m_index, a);
                g_visited[m_index] = false;
            }
        }
    }else {
        m_dis = g_data[i][0] + g_data[i][1];
        if(!Check(m_dis)){
            m_dis = END;
        }

        for(int j = g_data[i][0] + 1; j <= m_dis; j++){
            m_index = Index(j);
            if(m_index != -1 && !g_visited[m_index]){
                g_visited[m_index] = true;
                mySolve(m_index, a);
                g_visited[m_index] = false;
            }
        }
    }
}

int main()
{
    Input();
    //Print();
    g_visited[0] = true;
    mySolve(0, false);
    Output();
    return 0;
}
