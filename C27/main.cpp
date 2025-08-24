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

void Output(){
    int m_result = g_cnt % REST;
    freopen("output.txt", "w", stdout);
    printf("%d", m_result);
    fclose(stdout);
}

int main()
{
    Input();
    Testprint();
    return 0;
}
