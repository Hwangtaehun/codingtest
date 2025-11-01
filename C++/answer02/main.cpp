#include <functional>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

vector<int> g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    int x;
    while (scanf("%d", &x) != EOF) {
        g_data.push_back(x);
    }
    fclose(stdin);
}

void Output(){
    set<int, greater<int>> m_data;

    for(int i = 0; g_data.size(); i++){
        m_data.insert(g_data[i]);
    }

    freopen("output.txt", "w", stdout);
    printf("[");
    for (auto it = m_data.begin(); it != m_data.end(); ++it){
        printf("%d", *it);
        if(next(it) != m_data.end()){
            printf(", ");
        }
    }
    printf("]");
    fclose(stdout);
}

void Solve(){
    sort(g_data.begin(), g_data.end());
    reverse(g_data.begin(), g_data.end());

    g_data.erase(unique(g_data.begin(), g_data.end()), g_data.end());

    for(int i = 0; i < g_data.size(); i++){
        printf("%d ", g_data[i]);
    }
    printf("\n");
}

int main()
{
    Input();
    Solve();
    //Output();
    return 0;
}
