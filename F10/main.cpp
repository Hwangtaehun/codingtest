#include <cstdio>
#include <vector>

using namespace std;

int g_size, g_max = 0;
vector<int> g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    for(int i = 0; i < g_size; i++){
        int t;
        scanf("%d", &t);
        g_data.push_back(t);
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_max);
    fclose(stdout);
}

void mySolve(){
    for(int i = 0; i < g_size; i++){ //index
        for(int j = g_size - i; j > 0; j--){ //count
            int m_sum = 0;
            for(int k = i; k < j + i; k++){
                m_sum += g_data[k];
            }

            if(g_max < m_sum){
                g_max = m_sum;
            }
        }
    }
}

void Print(){
    for(int i = 0; i < g_size; i++){
        printf("%d ", g_data[i]);
    }
    printf("\n");
}

int main()
{
    Input();
    //Print();
    mySolve();
    Output();
    return 0;
}
