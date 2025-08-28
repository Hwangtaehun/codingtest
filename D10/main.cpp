#include <cstdio>
#include <vector>

using namespace std;

vector<int> g_data, g_result;
int g_size, g_dis = 0x7FFFFFFF, g_fir = 0x7FFFFFFF;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    for(int i = 0; i < g_size; i++){
        int n;
        scanf("%d", &n);
        g_data.push_back(n);
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);

    for(int i = 0; i < g_result.size(); i++){
        printf("%d ", g_result[i]);
    }

    fclose(stdout);
}

void Compare(int *a, int *b){
    if(*a < *b){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

void Add(int a, int b, int c){
    g_result.clear();
    g_result.push_back(a);
    g_result.push_back(b);
    g_result.push_back(c);
}

void mySolve(int a, int b, int c, int cnt){
    if(cnt == g_size){
        Compare(&b, &c);
        Compare(&a, &b);
        Compare(&b, &c);
        int m_dis = a - c;
        int m_fir = a;
        //printf("m_dis = %d, m_fir = %d\n", m_dis, m_fir);

        if(m_dis <= g_dis && m_fir <= g_fir){
            g_dis = m_dis;
            g_fir = m_fir;
            Add(a, b, c);
        }

        return;
    }

    mySolve(a + g_data[cnt], b, c, cnt + 1);
    mySolve(a, b + g_data[cnt], c, cnt + 1);
    mySolve(a, b, c + g_data[cnt], cnt + 1);
}

int main()
{
    Input();
    mySolve(0, 0, 0, 0);
    Output();
    return 0;
}
