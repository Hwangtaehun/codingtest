#include <cstdio>
#include <vector>

using namespace std;

int g_size;
vector<int> g_data, g_result;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);

    g_data.resize(g_size + 1);
    g_result.resize(g_size + 1);

    for(int i = 1; i <= g_size; i++){
        scanf("%d", &g_data[i]);
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 1; i <= g_size; i++){
        printf("%d\n", g_result[i]);
    }
    fclose(stdout);
}

void Solve(){
    for(int i = 1; i <= g_size; i++){
        int cnt = 0;

        for(int j = 1; j < i; j++){
            if(g_data[j] < g_data[i]){
                cnt++;
            }
        }

        g_result[i] = i - cnt;
    }
}

void Print(){
    for(int i = 1; i <= g_size; i++){
        printf("%d: %d\n", i, g_data[i]);
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
