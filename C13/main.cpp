#include <cstdio>
#include <vector>

using namespace std;

int g_edge, g_size;
vector< vector<int> > g_data;
vector<int> g_color; // 0:nothing, 1: black, -1: white

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_edge, &g_size);
    g_data.resize(g_edge);
    g_color.resize(g_edge);
    for(int i = 0; i < g_size; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g_data[a].push_back(b);
        g_data[b].push_back(a);
    }

    fclose(stdin);
}

void Output(){
    bool possible = true;

    for(int i = 0; i < g_color.size(); i++){
        if(g_color[i] == 0){
            possible = false;
        }
    }

    freopen("output.txt", "w", stdout);

    if(possible){
        printf("OK");
    }else{
        printf("IMPOSSIBLE");
    }

    fclose(stdout);
}

void TestPrint(){
    printf("g_edge = %d, g_size = %d\n", g_edge, g_size);

    for(int i = 0; i < g_data.size(); i++){
        for(int j = 0; j < g_data[i].size(); j++){
            printf("%d ", g_data[i][j]);
        }
        printf("\n");
    }

    printf("g_color size = %d\n", g_color.size());

    for(int i = 0; i < g_color.size(); i++){
        printf("%d ", g_color[i]);
    }
}

void mySolve(int n, int c){
    g_color[n] = c;

    for(int i = 0; i < g_data[n].size(); i++){
        if(g_color[g_data[n][i]] == c){
            g_color[n] = 0;
            return;
        }
    }

    for(int i = 0; i < g_data[n].size(); i++){
        if(g_color[g_data[n][i]] == 0){
            mySolve(g_data[n][i], 1);
            mySolve(g_data[n][i], -1);
        }
    }
}

int main()
{
    Input();
    TestPrint();
    mySolve(0, 1);
    Output();
    return 0;
}
