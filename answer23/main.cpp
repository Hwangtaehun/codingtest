#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> want, discount;
vector<int> number;
int answer;

void Input(){
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    while(getline(cin, line)){
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
                if(i == 0){
                    want.push_back(token);
                } else if(i == 1){
                    int n = stoi(token);
                    number.push_back(n);
                } else {
                    discount.push_back(token);
                }
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", answer);
    fclose(stdout);
}

unordered_map<string, int> Mapping(const vector<string> m_want, const vector<int> m_num){
    unordered_map<string, int> m_map;

    for(int i = 0; i < m_want.size(); i++){
        m_map[m_want[i]] = m_num[i];
    }

    return m_map;
}

#define ITEM_SIZE 10

void Solve(){
    int max_start = discount.size() - ITEM_SIZE;

    for(int i = 0; i <= max_start; i++){
        unordered_map<string, int> items = Mapping(want, number);

        for(int j = i; j < i + ITEM_SIZE; j++){
            if(items.find(discount[j]) != items.end()){
                items[discount[j]]--;

                if(items[discount[j]] == 0){
                    items.erase(discount[j]);
                }
            }
        }

        if(items.empty()){
            answer++;
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
