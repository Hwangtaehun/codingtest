#include <stdio.h>
#include <queue>

using namespace std;

int g_row, g_col, g_cnt = 0x7FFFFFFF;
int g_dx[4] = {1, 0, -1, 0}, g_dy[4] = {0, 1, 0, -1};
char **g_data;
bool **g_visit;
int visited[101][101];

//explanation
int sRow, sCol, gRow, gCol;

struct VERTEX {
    int x, y; // row, col
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
            if(g_data[i][j] == 'S')
                sRow=i, sCol=j;
            else if(g_data[i][j] == 'G')
                gRow=i, gCol=j, g_data[i][j]='.';
        }
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("\n\n%d\n\n", g_cnt);
    fclose(stdout);
}

bool isSafe(int row, int col){
    return (col >= 0 && col < g_col) && (row >= 0 && row < g_row);
}

void TestPrn(queue <VERTEX> q1, VERTEX cur)
{
    printf("%2d,%d Ã³¸® ÈÄ queue : ", cur, cur.x, cur.y);
    while(!q1.empty()) {
        printf("%d,%d ", q1.front().x, q1.front().y);
        q1.pop();
    }
    printf("\n");
    for(int i = 0; i < g_row; i++){
        for(int j = 0; j < g_col; j++){
            printf("%2d", visited[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int Solve()
{
    queue <VERTEX> q;
    q.push((VERTEX){sRow, sCol});
    visited[sRow][sCol] = 0;

    while(!q.empty()){

        VERTEX cur = q.front();
        q.pop();

        if(cur.x == gRow && cur.y == gCol)
            break;

        for(int i = 0; i < 4; i++){
            int row = cur.x + g_dx[i], col = cur.y + g_dy[i];

            if(isSafe(row, col) && !visited[row][col] && g_data[row][col] == '.') {
                visited[row][col] = visited[cur.x][cur.y] + 1;
                q.push((VERTEX){row, col});
            }
        }
        TestPrn(q, cur);
    }
    return visited[gRow][gCol];
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

void MySolve() {
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
    //MySolve();
    //Output();

    printf("%d\n", Solve());

    for(int i = 0; i < g_row; i++) {
        delete[] g_data[i];
        delete[] g_visit[i];
    }

    delete[] g_data;
    delete[] g_visit;

    return 0;
}
