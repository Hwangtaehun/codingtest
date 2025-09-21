#include <cstdio>
#include <vector>
#define GRADE 4
#define SIZE 3

using namespace std;

struct ROWCOL{
    int x;
    int y;
};

ROWCOL g_move[SIZE] = { {1, 0}, {0, 1}, {0, 0} };
int g_size, g_max = 0;
vector<vector<char> > g_data, g_grade;
vector<vector<int> > g_used;

//solve
#include <memory.h>
#define cu (1 << n)
#define rt (1 << (n - 1))
#define dn (1)
#define M (1 << (n + 1))

int p[4][4] = {100, 70, 40, 0, 70, 50, 30, 0, 40, 30, 20, 0, 0, 0, 0, 0};
int n, tb[12][12], m[12][12][1 << 13];

int Max(int a, int b){ return a > b ? a : b;}

void Input(){
    g_grade.resize(GRADE);

    for(int i = 0; i < GRADE; i++){
        g_grade[i].resize(GRADE);
    }

    g_grade[0][0] = 100;
    g_grade[0][1] = g_grade[1][0] = 70;
    g_grade[1][1] = 50;
    g_grade[2][0] = g_grade[0][2] = 40;
    g_grade[1][2] = g_grade[2][1] = 30;
    g_grade[2][2] = 20;

    freopen("input.txt", "r", stdin);

    scanf("%d", &g_size);
    g_data.resize(g_size);
    g_used.resize(g_size);

    for(int i = 0 ; i < g_size; i++){
        g_data[i].resize(g_size);
        g_used[i].resize(g_size);

        for(int j = 0; j < g_size; j++){
            scanf(" %c", &g_data[i][j]);
            tb[i][j] = (g_data[i][j] == 'F' ? 3 : g_data[i][j] - 'A');
            g_used[i][j] = false;
        }
    }

    fclose(stdin);

    memset(m, -1, sizeof(m));
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_max);
    fclose(stdout);
}

int Trans(char ch){
    switch(ch){
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    default:
        return 3;
    }
}

void Print(int num){
    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            printf("%d ", g_used[i][j]);
        }
        printf("\n");
    }

    if(num != 0){
         printf("----------\nnum = %d\n----------", num);
    }

    printf("\n");
}

int Solve(int a, int b){
    int ans = 0;
    //Print(ans);

    if(a == g_size){
        return 0;
    }

    if(b == g_size){
        return Solve(a + 1, 0);
    }

    if(g_used[a][b] == 0){
        g_used[a][b] = 1;

        if(b + 1 < g_size && g_used[a][b + 1] == 0){
            g_used[a][b + 1] = 1;
            ans = Max(ans, Solve(a, b + 1) + g_grade[Trans(g_data[a][b])][Trans(g_data[a][b + 1])]);
            g_used[a][b + 1] = 0;
        }

        if(a + 1 < g_size && g_used[a + 1][b] == 0){
            g_used[a + 1][b] = 1;
            ans = Max(ans, Solve(a, b + 1) + g_grade[Trans(g_data[a][b])][Trans(g_data[a + 1][b])]);
            g_used[a + 1][b] = 0;
        }

        ans = Max(ans, Solve(a, b + 1));
        g_used[a][b] = 0;
    }else{
        ans = Max(ans, Solve(a, b + 1));
    }

    //Print(ans);
    return ans;
}

int f(int x, int y, int s){
    if(x == n){
        return 0;
    }

    if(y == n){
        return f(x + 1, 0, s);
    }

    if(!m[x][y][s]){
        if(!(s&cu)){
            if(y + 1 < n && !(s & rt)){
                m[x][y][s] = Max(m[x][y][s], f(x, y + 2, (s << 2) % M) + p[tb[x][y]][tb[x][y+1]]);
            }
            if(x + 1 < n && !(s & dn)){
                m[x][y][s] = Max(m[x][y][s], f(x, y + 1, ((s|dn) << 1) % M) + p[tb[x][y]][tb[x+1][y]]);
            }
            m[x][y][s] = Max(m[x][y][s], f(x, y + 1, (s << 1) % M));
        }else{
            m[x][y][s] = Max(m[x][y][s], f(x, y + 1, (s << 1) % M));
        }
    }
    return m[x][y][s];
}

int main()
{
    Input();
    printf("%d\n", f(0, 0, 0));
    g_max = Solve(0, 0);
    Output();
    return 0;
}
