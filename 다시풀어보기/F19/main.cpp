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
            g_used[i][j] = false;
        }
    }

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_max);
    fclose(stdout);
}

int Max(int a, int b){ return a > b ? a : b;}

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

int f(int a, int b){
    int ans = 0;
    //Print(ans);

    if(a == g_size){
        return 0;
    }

    if(b == g_size){
        return f(a + 1, 0);
    }

    if(g_used[a][b] == 0){
        g_used[a][b] = 1;

        if(b + 1 < g_size && g_used[a][b + 1] == 0){
            g_used[a][b + 1] = 1;
            ans = Max(ans, f(a, b + 1) + g_grade[Trans(g_data[a][b])][Trans(g_data[a][b + 1])]);
            g_used[a][b + 1] = 0;
        }

        if(a + 1 < g_size && g_used[a + 1][b] == 0){
            g_used[a + 1][b] = 1;
            ans = Max(ans, f(a, b + 1) + g_grade[Trans(g_data[a][b])][Trans(g_data[a + 1][b])]);
            g_used[a + 1][b] = 0;
        }

        ans = Max(ans, f(a, b + 1));
        g_used[a][b] = 0;
    }else{
        ans = Max(ans, f(a, b + 1));
    }

    //Print(ans);
    return ans;
}

int main()
{
    Input();
    g_max = f(0, 0);
    Output();
    return 0;
}
