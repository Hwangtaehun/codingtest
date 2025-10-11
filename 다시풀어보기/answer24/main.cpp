#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> record, answer;

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

        stringstream ss(lines[i]);
        string token;

        while(getline(ss, token, ',')) {
            token.erase(0, token.find_first_not_of(" \t\n\r"));
            token.erase(token.find_last_not_of(" \t\n\r") + 1);

            if(!token.empty()){
                record.push_back(token);
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << "[";
    for(int i = 0; i < answer.size(); i++){
            cout << "\"" << answer[i] << "\"";
        if(i != answer.size() - 1){
            cout << ",";
        }
    }
    cout << "]";
    fclose(stdout);
}

void Solve(){
    unordered_map<string, string> member;

    for(int i = 0; i < record.size(); i++){
        string cmd, id, nickname;
        stringstream ss(record[i]);
        ss >> cmd >> id;

        if(cmd != "Leave"){
            ss >> nickname;
            member[id] = nickname;
        }
    }

    for(int i = 0; i < record.size(); i++){
        stringstream ss(record[i]);
        string cmd, id;
        ss >> cmd >> id;

        if(cmd == "Enter") {
            answer.push_back(member[id] + "님이 들어왔습니다.");
        } else if(cmd == "Leave") {
            answer.push_back(member[id] + "님이 나갔습니다.");
        }
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
