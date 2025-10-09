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

Print_Vector(const vector<string>& v_str){
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

    Print_Vector(cards1);
    Print_Vector(cards2);
    Print_Vector(goal);
}

int main()
{
    Input();
    return 0;
}
