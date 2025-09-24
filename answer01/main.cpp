#include <algorithm>
#include <cstdio>
#include <vector>

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
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_data.size(); i++){
        printf("%d ", g_data[i]);
    }
    fclose(stdout);
}

void Solve(){
    sort(g_data.begin(), g_data.end());
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
