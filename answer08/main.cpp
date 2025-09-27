#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<char> g_data;
bool g_result = false;

void Input(){
    string s;

    freopen("input.txt", "r", stdin);
    cin >> s;
    fclose(stdin);

    g_data.assign(s.begin(), s.end());
}

void Output(){
    freopen("output.txt", "w", stdout);

    if(g_result){
        printf("true");
    }else{
        printf("false");
    }

    fclose(stdout);
}

void Solve(){
    vector<int> m_index;
    for(int i = 0; i < g_data.size(); i++){
        if(g_data[i] == '('){
            m_index.push_back(i);
        }else{
            if(m_index.size() != 0){
                m_index.pop_back();
            }else{
                return;
            }
        }
    }

    if(m_index.size() == 0){
        g_result = true;
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
