#include <cstdio>
#include <vector>
#include <set>

using namespace std;
set<int> g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    int x;
    while (scanf("%d", &x) != EOF) {
        g_data.insert(x);
    }
    fclose(stdin);
}

void Output(){
    vector<int> m_data;

    for(int i: g_data){
        m_data.push_back(i);
    }

    freopen("output.txt", "w", stdout);
    printf("[");
    for(int i = m_data.size() - 1; i >= 0; i--){
        if(i == 0){
            printf("%d", m_data[i]);
        }else{
            printf("%d, ", m_data[i]);
        }
    }
    printf("]");
    fclose(stdout);
}

int main()
{
    Input();
    Output();
    return 0;
}
