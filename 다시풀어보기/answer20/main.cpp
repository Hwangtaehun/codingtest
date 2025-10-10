#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> participant, completion;
string answer;

void Input(){
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    while (getline(cin, line)) {
        if (!line.empty()){
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

        while (getline(ss, token, ',')) {
            token.erase(0, token.find_first_not_of(" \t\n\r"));
            token.erase(token.find_last_not_of(" \t\n\r") + 1);
            if (!token.empty()){
                if(i == 0){
                    participant.push_back(token);
                } else {
                    completion.push_back(token);
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

unordered_map<string, int> map_sort(const vector<string> v_str){
    unordered_map<string, int> m_str;

    for(int i = 0; i < v_str.size(); i++){
        m_str[v_str[i]] += 1;
    }

    return m_str;
}

void Solve(){
    unordered_map<string, int> m_part = map_sort(participant);

    for(int i = 0; i < completion.size(); i++){
        if(m_part.find(completion[i]) != m_part.end()){
            m_part[completion[i]] -= 1;

            if(m_part[completion[i]] == 0){
                m_part.erase(completion[i]);
            }
        }
    }

    answer = m_part.begin()->first;
}

string Solve1(){
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i = 0; i < completion.size(); i++){
        if(participant[i] != completion[i]){
            return participant[i];
        }
    }

    return participant[participant.size() - 1];
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
