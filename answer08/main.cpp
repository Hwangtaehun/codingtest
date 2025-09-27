#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>

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
            if(m_index.empty()){
                return;
            }
            m_index.pop_back();
        }
    }

    if(m_index.empty()){
        g_result = true;
    }
}

bool Solution(){
    stack<char> stack;

    for(char c: g_data){
        if(c == '('){
            stack.push(c);
        }else if(c == ')'){
            if(stack.empty()){
                return false;
            } else {
                stack.pop();
            }
        }
    }

    return stack.empty();
}

int main()
{
    Input();
    printf("%d", Solution());
    Solve();
    Output();
    return 0;
}
