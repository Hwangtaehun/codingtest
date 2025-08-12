#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

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

void Print(set< vector<int> > results){
    for (set< vector<int> >::iterator it = results.begin(); it != results.end(); ++it) {
        vector<int> vec = *it;
        for (vector<int>::iterator vit = vec.begin(); vit != vec.end(); ++vit) {
            printf("%d ", *vit);
        }
        printf("\n");
    }
}

void mySolve(){
    set< vector<int> > m_results;

    for(int i = 1; i < g_r; i++){
        int rest = g_r - i;
        for(int j = 1; j < rest; j++){
            vector<int> m_v;
            int other = rest - j;
            m_v.push_back(i);
            m_v.push_back(j);
            m_v.push_back(other);
            sort(m_v.begin(), m_v.end());
            //Print(m_v);
            m_results.insert(m_v);
        }
    }
    //printf("\n");
    //Print(m_results);

    for (set< vector<int> >::iterator it = m_results.begin(); it != m_results.end(); ++it) {
        const vector<int> &vec = *it;
        if(vec[2] < vec[0] + vec[1]){
            g_cnt++;
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt);
    fclose(stdout);
}

int main()
{
    Input();
    mySolve();
    Output();
    return 0;
}
