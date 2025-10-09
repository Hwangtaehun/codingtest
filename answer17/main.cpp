#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> cards1, cards2, goal;
string answer;

void Print_Vector(const vector<string>& v_str){
    for(int i = 0; i < v_str.size(); i++){
        cout << v_str[i] << " ";
    }
    cout << endl;
}

void Input(){
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    while(getline(cin, line)) {
        if(!line.empty()){
            lines.push_back(line);
        }
    }

    fclose(stdin);

    for(int i = 0; i < lines.size(); i++){
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), '['), lines[i].end());
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), ']'), lines[i].end());
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), '\"'), lines[i].end());
    }

    for(int i = 0; i < lines.size(); i++){
        stringstream ss(lines[i]);
        string token;

        while(getline(ss, token, ',')){
            token.erase(0, token.find_first_not_of(" \t\n\r"));
            token.erase(token.find_last_not_of(" \t\n\r") + 1);
            if(!token.empty()){
                if(i == 0) {
                    cards1.push_back(token);
                }else if(i == 1) {
                    cards2.push_back(token);
                }else {
                    goal.push_back(token);
                }
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << answer;
    fclose(stdout);
}

bool Same(const vector<string> &v_str){
    for(int i = 0; i < goal.size(); i++){
        if(goal[i] != v_str[i]){
            return false;
        }
    }

    return true;
}

void Solve(){
    vector<string> m_r;
    queue<string> q_c1;

    for(int i = 0; i < cards1.size(); i++){
        q_c1.push(cards1[i]);
    }

    m_r.push_back(q_c1.front());
    q_c1.pop();

    for(int i = 0; i < cards2.size(); i++){
        m_r.push_back(cards2[i]);
    }

    while(!q_c1.empty()){
        m_r.push_back(q_c1.front());
        q_c1.pop();
    }

    if(Same(m_r)){
        answer = "Yes";
    }else{
        answer = "No";
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
