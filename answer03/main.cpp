#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> g_data, g_result;
vector<bool> g_used;

void Input(){
    freopen("input.txt", "r", stdin);
    int x;
    while (scanf("%d", &x) != EOF) {
        g_data.push_back(x);
    }
    fclose(stdin);
    g_used.resize(g_data.size());
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("[");
    for(int i = 0; i < g_result.size(); i++){
        printf("%d", g_result[i]);
        if(i != g_result.size() - 1){
            printf(", ");
        }
    }
    printf("]");
    fclose(stdout);
}

void Solve(int cnt, int sum){
    if(cnt == 2){
        g_result.push_back(sum);
        return;
    }

    for(int i = 0; i < g_data.size(); i++){
        if(!g_used[i]){
            g_used[i] = true;
            Solve(cnt + 1, sum + g_data[i]);
            g_used[i] = false;
        }
    }
}

int main()
{
    Input();
    Solve(0, 0);

    sort(g_result.begin(), g_result.end());
    g_result.erase(unique(g_result.begin(), g_result.end()), g_result.end());

    Output();
    return 0;
}
