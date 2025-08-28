#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g_data, g_result;
int g_size, g_dis = 0x7FFFFFFF, g_fir = 0x7FFFFFFF;

//solve
int gift[20], g1, g2, g3, n, d = 0x0fffffff, gd = 0x0fffffff, sum, debugCnt;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    n = g_size;

    for(int i = 0; i < g_size; i++){
        scanf("%d", &gift[i]);
        g_data.push_back(gift[i]);
        sum += gift[i];
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

void mySolve(int a, int b, int c, int cnt){
    if(cnt == g_size){
        vector<int> m_sort;
        m_sort.push_back(a);
        m_sort.push_back(b);
        m_sort.push_back(c);
        sort(m_sort.begin(), m_sort.end());
        reverse(m_sort.begin(), m_sort.end());
        int m_dis = m_sort.front() - m_sort.back();
        int m_fir = m_sort.front();

        if(m_dis <= g_dis && m_fir <= g_fir){
            g_dis = m_dis;
            g_fir = m_fir;
            g_result = m_sort;
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
