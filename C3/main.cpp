#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int g_cnt, g_r;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_r);
    fclose(stdin);
}

void Print(vector<int> v){
    printf("v.size = %d\n", v.size());

    for(int i = 0; i < v.size(); i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void mySolve(){
    int rest;
    vector<int> m_v;

    for(int i = 1; i < g_r; i++){
        rest = g_r - i;
        //printf("rest = %d\n", rest);
        //printf("i=%d\n", i);
        //Print(m_v);

        for(int j = 1; j < rest; j++){
            int other = rest - j;
            m_v.push_back(j);
            //Print(m_v);
            m_v.push_back(other);
            //Print(m_v);
            sort(m_v.begin(), m_v.end());
            Print(m_v);

            m_v.push_back(i);
            Print(m_v);
            m_v.clear();
        }
    }
}

int main()
{
    Input();
    mySolve();
    return 0;
}
