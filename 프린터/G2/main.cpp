#include <cstdio>
#include <vector>
#define SIZE 4
#define ROWCOL 2

using namespace std;

vector< vector <int> > g_data, g_move, g_used;
int g_size, g_goal, g_min = 0x0FFFFFFF;

void Input(){
    g_move.resize(SIZE);

    for(int i = 0; i < SIZE; i++){
        g_move[i].resize(ROWCOL);
    }

    g_move[0][0] = 0;
    g_move[0][1] = 1;
    g_move[1][0] = 0;
    g_move[1][1] = -1;
    g_move[2][0] = -1;
    g_move[2][1] = 0;
    g_move[3][0] = 1;
    g_move[3][1] = 0;

    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);

    g_data.resize(g_size);
    g_used.resize(g_size);

    for(int i = 0; i < g_size; i++){
        g_data[i].resize(g_size);
        g_used[i].resize(g_size);

        for(int j = 0; j < g_size; j++){
            scanf("%d", &g_data[i][j]);
            g_used [i][j] = 0;
        }
    }
    fclose(stdin);

    g_goal = g_size * g_size / 4 * 3;
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

bool Range(int x, int y){
    if((x < g_size && x >= 0) && (y < g_size && y >= 0)){
        return true;
    }

    return false;
}

void Solve(int x, int y, int cnt, int value){
    if(g_min < value){
        return;
    }

    if(cnt >= g_goal){
        if(value < g_min){
            g_min = value;
        }
        return;
    }

    for(int i = 0; i < SIZE; i++){
        int m_x = x + g_move[i][0];
        int m_y = y + g_move[i][1];
        if(Range(m_x, m_y) && g_used[m_x][m_y] == 0){
            int m_value = 0;

            if(value < g_data[m_x][m_y]){
                m_value = g_data[m_x][m_y];
            }else{
                m_value = value;
            }

            g_used[m_x][m_y] = 1;
            Solve(m_x, m_y, cnt + 1, m_value);
            g_used[m_x][m_y] = 0;
        }
    }
}

int main()
{
    Input();
    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            g_used[i][j] = 1;
            Solve(i, j, 1, g_data[i][j]);
            g_used[i][j] = 0;
        }
    }
    Output();
    return 0;
}
