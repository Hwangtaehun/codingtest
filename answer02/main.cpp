#include <functional>
#include <cstdio>
#include <set>

using namespace std;
set<int, greater<int>> g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    int x;
    while (scanf("%d", &x) != EOF) {
        g_data.insert(x);
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("[");
    for (auto it = g_data.begin(); it != g_data.end(); ++it){
        printf("%d", *it);
        if(next(it) != g_data.end()){
            printf(", ");
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
