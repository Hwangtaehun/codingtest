#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

string s;
int result;

void Input(){
    freopen("input.txt", "r", stdin);
    cin >> s;
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << result;
    fclose(stdout);
}

void Solve(){
    stack<char> st;

    for(int i = 0; i < s.size(); i++){
        if(st.empty() || st.top() != s[i])
            st.push(s[i]);
        else
            st.pop();
    }

    result = st.empty();
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
