#include <cstdio>
#include <vector>

using namespace std;

struct StartEnd{
    int s;
    int e;
};

int g_edge, g_size;
vector<StartEnd> g_data;
vector<int> g_color; // 0:nothing, 1: black, 2: white
bool possible = false;

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_edge, &g_size);
    g_color.resize(g_edge);
    for(int i = 0; i < g_size; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g_data.push_back((StartEnd){a, b});
    }

    fclose(stdin);
}

void Output(){
    //freopen("output.txt", "w", stdout);

    if(possible){
        printf("OK");
    }else{
        printf("IMPOSSIBLE");
    }

    //fclose(stdout);
}

void TestPrint(){
    printf("g_color size = %d\n", g_color.size());
    for(int i = 0; i < g_color.size(); i++){
        printf("%d ", g_color[i]);
    }
}

bool Check(){
    for(int i = 0; i < g_size; i++){
        if(g_color[g_data[i].s] == g_color[g_data[i].e]){
            return false;
        }
    }

    return true;
}

void mySolve(int cnt){
    if(cnt == g_size){
        if(!possible){
            possible = Check();
        }
        return;
    }

    g_color[cnt] = 1;
    mySolve(cnt+1);
    g_color[cnt] = 2;
    mySolve(cnt+1);
}

int main()
{
    Input();
    //TestPrint();
    mySolve(0);
    Output();
    return 0;
}
