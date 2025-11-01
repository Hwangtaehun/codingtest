#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
vector<string> words;
vector<int> answer;

void Input(){
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    scanf("%d", &n);

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
                words.push_back(token);
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < answer.size(); i++){
        printf("%d ", answer[i]);
    }
    fclose(stdout);
}

void Solve(){
    unordered_map <string, int> m_word;

    for(int i = 0; i < words.size(); i++){
        m_word[words[i]]++;

        if(i != 0){
            int person = (i % n) + 1;
            int stap = (int)(i / n) + 1;

            if(m_word[words[i]] != 1){
                answer.push_back(person);
                answer.push_back(stap);
                break;
            }

            string bef = words[i - 1];
            string cur = words[i];

            if(bef[bef.length() - 1] != cur[0]){
                answer.push_back(person);
                answer.push_back(stap);
                break;
            }
        }
    }

    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
