#include <cstdio>
#include <cmath>

#define SIZE 2

using namespace std;

int **g_data, g_size, g_case, g_dis = 0;

//solve
int data[1010][2], n, m, ans = 0x0fffffff;

int dis(int a, int b){
    int d = abs(data[a][0] - data[b][0]) + abs(data[a][1] - data[b][1]);
    return d;
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_case);
    n = g_size, m = g_case;

    g_data = new int*[g_case];
    for(int i = 0; i < g_case; i++){
        g_data[i] = new int[SIZE];
    }

    data[0][0] = data[0][1] = 1;
    data[1][0] = data[1][1] = n;

    for(int i = 0; i < g_case; i++){
        scanf("%d %d", &g_data[i][0], &g_data[i][1]);
        data[i+2][0] = g_data[i][0];
        data[i+2][1] = g_data[i][1];
    }

    fclose(stdin);
}

void TestPrint(){
    for(int i = 0; i < g_case; i++){
        printf("%d %d\n", g_data[i][0], g_data[i][1]);
    }
    printf("\n%d\n", g_dis);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_dis);
    fclose(stdout);

    for(int i = 0; i < SIZE; i++){
        delete[] g_data[i];
    }
    delete[] g_data;
}

int nature_num(int num){
    if(num < 0){
        num = -num;
    }

    return num;
}

void mySolve(){
    int m_cnt = 0;
    int m_car[SIZE][SIZE] = {{1, 1}, {g_size, g_size}};

     for(int i = 0; i < g_case; i++){
        int m_dis1, m_dis2;
        m_dis1 = nature_num((m_car[0][0] - g_data[i][0]) + (m_car[0][1] - g_data[i][1]));
        m_dis2 = nature_num((m_car[1][0] - g_data[i][0]) + (m_car[1][1] - g_data[i][1]));

        if(m_dis1 < m_dis2){
            g_dis += m_dis1;
            m_car[0][0] = g_data[i][0];
            m_car[0][1] = g_data[i][1];
        }else{
            g_dis += m_dis2;
            m_car[1][0] = g_data[i][0];
            m_car[1][1] = g_data[i][1];
        }

        /*
        for(int i = 0; i < SIZE; i++){
            printf("%d %d\n", m_car[i][0], m_car[i][1]);
        }
        printf("\n");
        */
    }
}

void solve(int a, int b, int d){
    int next = (a > b ? a : b) + 1;
    printf("%d,%d,%d,%d: %d,%d\n", a, b, next, d, dis(a, next), dis(b, next));

    if(next >= m + 2){
        if(d < ans)
            ans = d;
        return;
    }

    solve(next, b, d + dis(a, next));
    solve(a, next, d + dis(b, next));
}

int main()
{
    Input();
    //TestPrint();
    solve(0, 1, 0);
    printf("%d", ans);
    mySolve();
    Output();
    return 0;
}
