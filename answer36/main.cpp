#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

vector<pair<char, char> > graph;
vector<char> answer;
char start;

void Input(){
    string line;
    vector<char> temp;

    freopen("input.txt", "r", stdin);
    getline(cin, line);
    cin >> start;
    fclose(stdin);

    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());
    line.erase(remove(line.begin(), line.end(), '\''), line.end());

    stringstream ss(line);

    while(getline(ss, line, ',')){
        line.erase(0, line.find_first_not_of(" \t\n\r"));
        line.erase(line.find_last_not_of(" \t\n\r") + 1);

        if(!line.empty()) {
            temp.push_back(line[0]);

            if(temp.size() == 2){
                pair<char, char> ptemp;
                ptemp.first = temp[0];
                ptemp.second = temp[1];
                graph.push_back(ptemp);
                temp.clear();
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << "[";
    for(int i = 0; i < answer.size(); i++){
        if(i != 0){
            cout << ", ";
        }
        cout << answer[i];
    }
    cout << "]";
    fclose(stdout);
}

void answer_print(){
    for(int i = 0; i < answer.size(); i++){
        printf("%c ", answer[i]);
    }
    printf("\n");
}

bool Check(const unordered_set<char> us, char c){
    if(us.find(c) != us.end()){
        return false;
    }

    return true;
}

void Solve(){
    unordered_set<char> visited;
    stack<char> m_st;
    m_st.push(start);

    while(!m_st.empty()){
        vector<char> temp;
        char m_start = m_st.top();
        m_st.pop();

        if(Check(visited, m_start)){
            answer.push_back(m_start);
            visited.insert(m_start);

            for(auto a : graph){
                if(a.first == m_start){
                    temp.push_back(a.second);
                }
            }

            for(int i = temp.size() - 1; i >= 0; i--){
                m_st.push(temp[i]);
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
