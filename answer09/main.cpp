#include <cstdio>
#include <stack>

using namespace std;

int g_decimal;
stack<int> g_result;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_decimal);
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    while(!g_result.empty()){
        printf("%d", g_result.top());
        g_result.pop();
    }
    fclose(stdout);
}

void Solve(){
    int m_num = g_decimal;

    while(m_num > 0){
        int n = m_num % 2;
        g_result.push(n);
        m_num /= 2;
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
