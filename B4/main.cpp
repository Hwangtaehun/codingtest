#include <stdio.h>
#include <queue>

using namespace std;

int g_row, g_col, g_cnt = 0x7FFFFFFF;
int g_dx[4] = {1, 0, -1, 0}, g_dy[4] = {0, 1, 0, -1};
char **g_data;
bool **g_visit;

struct VERTEX {
    int x, y;
};

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_row, &g_col);

    g_data = new char*[g_row];
    g_visit = new bool*[g_row];

    for(int i = 0; i < g_row; i++){
        g_data[i] = new char[g_col];
        g_visit[i] = new bool[g_col];
    }

    for(int i = 0; i < g_row; i++){
        for(int j = 0; j < g_col; j++){
            scanf(" %c", &g_data[i][j]);
        }
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("\n\n%d\n\n", g_cnt);
    fclose(stdout);
}

bool isSafe(int col, int row){
    return (col >= 0 && col < g_col) && (row >= 0 && row < g_row);
}

void Bfs(int r, int c) {
    queue<VERTEX> q;
    q.push({r, c});
    g_visit[r][c] = true;

    int dist = 0;
    while (!q.empty()) {
        int m_size = q.size();
        while (m_size--) {
            VERTEX node = q.front();
            q.pop();

            if (g_data[node.x][node.y] == 'G') {
                g_cnt = dist;
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nr = node.x + g_dx[i];
                int nc = node.y + g_dy[i];
                if (isSafe(nr, nc) && g_data[nr][nc] != '#' && !g_visit[nr][nc]) {
                    g_visit[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        dist++;
    }
}

void Solve() {
    for(int i = 0; i < g_row; i++){
        for(int j = 0; j < g_col; j++){
            if(g_data[i][j] == 'S'){
                Bfs(i, j);
                return;
            }
        }
    }
}

void Print(){
    for(int i = 0; i < g_row; i++){
        for(int j = 0; j < g_col; j++){
            printf("%c ", g_data[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Input();
    Solve();
    Output();

    for(int i = 0; i < g_row; i++) {
        delete[] g_data[i];
        delete[] g_visit[i];
    }

    delete[] g_data;
    delete[] g_visit;

    return 0;
}
