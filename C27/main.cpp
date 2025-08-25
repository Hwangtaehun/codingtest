#include <cstdio>
#include <vector>
#define SIZE 3
#define REST 1000

using namespace std;

vector< vector<int> > g_island;
bool *g_visited;
int g_cnt = 0, g_size;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    g_island.resize(g_size);
    g_visited = new bool[g_size];

    for(int i = 0; i < g_size; i++){
        g_island[i].resize(SIZE);
        scanf("%d %d %d", &g_island[i][0], &g_island[i][1], &g_island[i][2]);
        g_visited[i] = false;
    }
    fclose(stdin);
}

void Testprint(){
    for(int i = 0; i < g_size; i++){
        printf("%d %d %d - %d\n", g_island[i][0], g_island[i][1], g_island[i][2], g_visited[i]);
    }
}

int Possible(int num){
    for(int i = 0; i < g_size; i++){
        if(g_island[i][0] == num){
            return i;
        }
    }
    return -1;
}

void mySolve(int index, int hang){
    if(index == g_size - 1){
        hang = 1;
    }

    if(index == 0 && hang == 1){
        g_cnt++;
        return;
    }

    int m_cur = g_island[index][0];
    int m_long = g_island[index][1];
    int m_index = -1;

    if(hang){
        for(int i = m_cur - 1; i >= m_cur - m_long; i--){
            m_index = Possible(i);
            if((m_index != -1 && g_island[m_index][2]) &&!g_visited[m_index]){
                g_visited[m_index] = true;
                mySolve(m_index, hang);
                g_visited[m_index] = false;
            }
        }
    }else{
        for(int i = m_cur + 1; i <= m_cur + m_long; i++){
            m_index = Possible(i);
            if(m_index != -1 && !g_visited[m_index]){
                g_visited[Possible(i)] = true;
                mySolve(m_index, hang);
                g_visited[Possible(i)] = false;
            }
        }
    }
}

void Output(){
    int m_result = g_cnt % REST;
    freopen("output.txt", "w", stdout);
    printf("%d", m_result);
    fclose(stdout);
}

int main()
{
    Input();
    //Testprint();
    mySolve(0, 0);
    Output();
    return 0;
}
