#include <cstdio>
#define SIZE 2

using namespace std;

int **g_data, g_size, g_case, g_dis = 0;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_case);

    g_data = new int*[g_case];
    for(int i = 0; i < g_case; i++){
        g_data[i] = new int[SIZE];
    }

    for(int i = 0; i < g_case; i++){
        scanf("%d %d", &g_data[i][0], &g_data[i][1]);
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

int main()
{
    Input();
    //TestPrint();
    mySolve();
    Output();
    return 0;
}
