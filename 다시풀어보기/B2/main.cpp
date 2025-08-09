#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

#define N 30

int g_size, g_cnt, g_kind[N+1];
int g_data[N+1][N+1];
int g_dx[4] = {1, 0, -1, 0}, g_dy[4] = {0, 1, 0, -1};

struct VERTEX {
    int x, y;
};

void Input() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            scanf("%d", &g_data[i][j]);
        }
    }
    fclose(stdin);
}

void Output() {
    freopen("output.txt", "w", stdout);
    printf("%d\n", g_cnt);
    for(int i = 0; i < g_cnt; i++){
        printf("%d\n", g_kind[i]);
    }
    fclose(stdout);
}

bool isSafe(int col, int row){
    return (col >= 0 && col < g_size) && (row >= 0 && row < g_size);
}

void Bfs(int x, int y, int no) {
    queue <VERTEX> q;
    q.push((VERTEX){x, y});
    g_data[x][y] = no;

    while(!q.empty()){
        VERTEX node = q.front();
        q.pop();
        for(int i =0; i < 4; i++){
            if(isSafe(node.x+g_dx[i], node.y+g_dy[i]) && g_data[node.x + g_dx[i]][node.y + g_dy[i]] == 1){
                g_data[node.x + g_dx[i]][node.y + g_dy[i]] = no;
                q.push((VERTEX){node.x + g_dx[i], node.y + g_dy[i]});
            }
        }
    }
}

bool compare(int left, int right)
{
    return left > right;
}

void Solve(){
    g_cnt = 0;
    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            if(g_data[i][j] == 1){
                g_cnt++;
                Bfs(i, j, g_cnt + 1);
            }
        }
    }

    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            if(g_data[i][j]){
                g_kind[g_data[i][j] - 2]++;
            }
        }
    }

    sort(g_kind, g_kind+g_size, compare);
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
