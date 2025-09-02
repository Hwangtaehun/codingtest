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
    g_data.resize(g_size);
    for(int i = 0; i < g_size; i++){
        g_data[i].resize(g_size);
    }

    for(int i = 0; i < g_size; i++){
        for(int j = 0; j < g_size; j++){
            scanf("%d", &g_data[i][j]);
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
                Draw(x, y, m_range, 2);
                g_white++;
            }
        }
        x += m_range;
    }

    mySolve(divide * 2);
}

int main()
{
    Input();
    //Print();
    mySolve(1);
    Output();
    return 0;
}
