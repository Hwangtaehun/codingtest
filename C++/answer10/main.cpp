#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

string g_s;
int g_result = 0;

void Input(){
    freopen("input.txt", "r", stdin);
    cin >> g_s;
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_result);
    fclose(stdout);
}

void Check(vector<char> m_data){
    stack<char> m_stack;

    for(int i = 0; i < m_data.size(); i++){
        char c = m_data[i];
        if(c == '(' || c == '{' || c == '['){
            m_stack.push(c);
        }else{
            if(m_stack.empty()){
                return;
            }

            if(c == ')'){
                if(m_stack.top() == '('){
                    m_stack.pop();
                }
            }else if(c == '}'){
                if(m_stack.top() == '{'){
                    m_stack.pop();
                }
            }else if(c == ']'){
                if(m_stack.top() == '['){
                    m_stack.pop();
                }
            }

        }
    }

    if(m_stack.empty()){
        g_result++;
    }
}

void Solve(){
    for(int i = 0; i < g_s.size(); i++){
        vector<char> m_data(g_s.begin() + i, g_s.end());

        for(int j = 0; j < i; j++){
            m_data.push_back(g_s[j]);
        }

        Check(m_data);
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
