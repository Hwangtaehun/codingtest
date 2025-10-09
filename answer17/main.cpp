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
    queue<string> q_c1;
    queue<string> q_c2;
    queue<string> q_g;

    for(int i = 0; i < cards1.size(); i++){
        q_c1.push(cards1[i]);
    }

    for(int i = 0; i < cards2.size(); i++){
        q_c2.push(cards2[i]);
    }

    for(int i = 0; i < goal.size(); i++){
        q_g.push(goal[i]);
    }


    while(!q_g.empty()){
        if(!q_c1.empty() && q_c1.front() == q_g.front()){
            q_c1.pop();
            q_g.pop();
        }else if(!q_c2.empty() && q_c2.front() == q_g.front()){
            q_c2.pop();
            q_g.pop();
        }else{
            break;
        }
    }

    answer = q_g.empty() ? "Yes" : "No";
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
