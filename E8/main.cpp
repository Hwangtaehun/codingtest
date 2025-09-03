#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>

using namespace std;

int g_size;
bool *g_check;
vector<char> g_data;
vector<int> g_result;

void Input(){
    char m_str[1<<19];

    freopen("input.txt", "r", stdin);
    scanf("%d %s", &g_size, m_str);
    fclose(stdin);

    for(int i = 0; m_str[i] != '\0'; i++){
        g_data.push_back(m_str[i]);
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
    for(int i = 0; i < g_data.size(); i++){
        printf("%c", g_data[i]);
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

int main()
{
    Input();
    mySolve(0, g_size);
    Output();
    return 0;
}
