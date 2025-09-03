#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int g_size;
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
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_result.size(); i++){
        printf("%d", g_result[i]);
    }
    fclose(stdout);
}

void Print(){
    for(int i = 0; i < g_data.size(); i++){
        printf("%c", g_data[i]);
    }
}

void mySolve(){
    int range = g_size;
    for(int i = 0; i <g_data.size(); i++){
        if(g_data[i] == '-'){
            range /= 2;
        }else{
            int cnt = 0;
            while(cnt < range){
                cnt++;
                g_result.push_back(g_data[i] - '0');
            }
        }
    }
}

int main()
{
    Input();
    mySolve();
    Output();
    return 0;
}
