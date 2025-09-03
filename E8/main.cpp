#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

int g_size;
bool *g_check;
vector<char> g_data;
vector<int> g_result;

//solve
char sa[1<<19], sb[1<<19], sc[1<<19];
queue <char> q;
int n, p;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %s", &g_size, sa);
    fclose(stdin);
    n = g_size;

    for(int i = 0; sa[i] != '\0'; i++){
        g_data.push_back(sa[i]);
    }

    g_check = new bool[g_data.size()];

    for(int i = 0; i < g_data.size(); i++){
        g_check[i] = false;
    }

}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_result.size(); i++){
        printf("%d", g_result[i]);
    }
    fclose(stdout);
}

bool Check(){
    for(int i = 0; i < g_data.size(); i++){
        if(!g_check[i])
            return false;
    }
    return true;
}

void Print(){
    for(int i = 0; sa[i]; i++){
        printf("%c", sa[i]);
    }
}

void mySolve(int s, int r){
    if(Check()){
        return;
    }

    if(g_check[s]){
        s++;
    }

    if(g_data[s] == '-'){
        g_check[s] = true;
        mySolve(s, r/2);
        mySolve(s + r/2, r/2);
    }else{
        for(int i = 0; i < r; i++){
            g_check[s] = true;
            g_result.push_back(g_data[s] - '0');
        }
    }
}

void Solve1(int k, int s){
    char val = sa[p++];

    if(val == NULL)
        return;
    if(val == '-'){
        Solve1(k, s/2);
        Solve1(k + s/2, s/2);
    }
    else{
        for(int i = k; i < k + s; i++){
            sb[i] = val;
        }
    }
}

void Solve2(int k, int s, char v){
    if(q.empty())
        return;
    if(v == '-'){
        q.pop();
        Solve2(k, s/2, q.front());
        q.pop();
        Solve2(k + s/2, s/2, q.front());
    }else{
        for(int i = k; i < k + s; i++){
            sc[i] = v;
        }
    }
}

int main()
{
    Input();
    Solve1(0, n);
    printf("%s\n", sb);
    for(int i = 0; sa[i]; i++)
        q.push(sa[i]);

    Solve2(0, n, q.front());
    printf("%s\n", sc);

    mySolve(0, g_size);
    Output();
    return 0;
}
