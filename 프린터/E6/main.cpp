#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> > g_data;
int g_size, g_white = 0, g_black = 0;

//solve
int s[1<<7][1<<7], n, gray, white;

void Print(){
    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            printf("%d ", g_data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool Check(int x, int y, int r, int c){
    for(int i = x; i < x + r; i++){
        for(int j = y; j < y + r; j++){
            if(g_data[i][j] != c){
                return false;
            }
        }
    }
    return true;
}

void Draw(int x, int y, int r, int c){
    for(int i = x; i < x + r; i++){
        for(int j = y; j < y + r; j++){
            g_data[i][j] = c;
        }
    }
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    n = g_size;
    g_data.resize(g_size);
    for(int i = 0; i < g_size; i++){
        g_data[i].resize(g_size);
    }

    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            scanf("%d", &g_data[i][j]);
            s[i][j] = g_data[i][j];
        }
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d\n%d", g_white, g_black);
    fclose(stdout);
}

void mySolve(int divide){
    //printf("%d\n", divide);
    if(divide > g_size){
        return;
    }

    int m_range = g_size / divide;
    int x = 0;

    while(x < g_size){
        for(int y = 0; y < g_size; y = y + m_range){
            //printf("x = %d, y = %d\n", x, y);
            if(Check(x, y, m_range, 1)){
                Draw(x, y, m_range, 2);
                g_black++;
            }

            if(Check(x, y, m_range, 0)){
                Draw(x, y, m_range, 9);
                g_white++;
            }
        }
        x += m_range;
    }

    //Print();
    mySolve(divide * 2);
}

void Solve(int a, int b, int n){
    bool isOne = true;
    for(int i = a; i < a + n; i++){
        for(int j = b; j < b + n; j++){
            if(s[a][b] != s[i][j])
                isOne = false;
        }
    }

    if(isOne){
        if(s[a][b] == 1)
            white++;
        else
            gray++;
        return;
    }else{
        Solve(a, b, n / 2);
        Solve(a + n / 2, b, n / 2);
        Solve(a, b + n / 2, n / 2);
        Solve(a + n / 2, b + n / 2, n / 2);
    }
}

int main()
{
    Input();
    //Print();
    Solve(0, 0, n);
    printf("%d\n%d\n", gray, white);
    mySolve(1);
    Output();
    return 0;
}
