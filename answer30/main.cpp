#include <iostream>
#include <cstdio>

using namespace std;

int N, A, B, answer;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d %d", &N, &A, &B);
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", answer);
    fclose(stdout);
}

void Solve(){
    int m_a = A, m_b = B, num = 1;

    while(m_a != m_b){
        m_a /= 2;
        m_b /= 2;
        num++;
    }

    answer = num;
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
