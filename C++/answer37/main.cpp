#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<pair <int, int> > graph;
vector<int> answer;
int start;

void Input(){
    string s;
    vector<int> temp;

    freopen("input2.txt", "r", stdin);
    getline(cin, s);
    cin >> start;
    fclose(stdin);

    s.erase(remove(s.begin(), s.end(), '['), s.end());
    s.erase(remove(s.begin(), s.end(), ']'), s.end());
    s.erase(remove(s.begin(), s.end(), '('), s.end());
    s.erase(remove(s.begin(), s.end(), ')'), s.end());

    stringstream ss(s);

    while(getline(ss, s, ',')){
        s.erase(0, s.find_first_not_of(" \t\n\r"));
        s.erase(s.find_last_not_of(" \t\n\t") + 1);

        if(!s.empty()){
            temp.push_back(stoi(s));

            if(temp.size() == 2){
                graph.push_back({temp[0], temp[1]});
                temp.clear();
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);

    for(int i = 0; i < answer.size(); i++){
        if(i != 0){
            cout << ", ";
        }
        cout << answer[i];
    }

    fclose(stdout);
}

void Solve(){
    unordered_set<int> m_visited;
    queue<int> m_q;

    m_q.push(start);
    m_visited.insert(start);

    while(!m_q.empty()){
        int m_num = m_q.front();
        m_q.pop();
        answer.push_back(m_num);

        for(auto a: graph){
            if(a.first == m_num && m_visited.find(a.second) == m_visited.end()){
                m_q.push(a.second);
                m_visited.insert(a.second);
            }
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
