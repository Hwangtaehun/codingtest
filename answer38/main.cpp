#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

vector<int> answer;
vector< tuple <int, int, int> > edges;
int start, numNodes;

void Input(){
    string s;
    vector<int> temp;

    freopen("input.txt", "r", stdin);

    cin >> start >> numNodes;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);

    fclose(stdin);

    s.erase(remove(s.begin(), s.end(), '['), s.end());
    s.erase(remove(s.begin(), s.end(), ']'), s.end());

    stringstream ss(s);

    while(getline(ss, s, ',')){
        s.erase(0, s.find_first_not_of(" \t\n\r"));
        s.erase(s.find_last_not_of(" \t\n\t") + 1);

        if(!s.empty()){
            temp.push_back(stoi(s));

            if(temp.size() == 3){
                tuple<int, int, int> t = make_tuple(temp[0], temp[1], temp[2]);
                edges.push_back(t);
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

bool Check(vector<bool> v){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == false){
            return true;
        }
    }

    return false;
}

template <typename T>
void vector_Print(T v){
    for(auto a : v){
        cout << a << " ";
    }
    cout << endl;
}

void Solve(){
    int s = start;
    vector<bool> visited(numNodes);

    answer.resize(numNodes);

    for(int i = 0; i < answer.size(); i++){
        answer[i] = 0xFFFFFFF;
    }

    answer[s] = 0;
    visited[s] = true;

    while(Check(visited)){
        int m_min = 0xFFFFFFF;

        for(int i = 0; i < edges.size(); i++){
            if(get<0>(edges[i]) == s){
                int goal = get<1>(edges[i]);
                int price = get<2>(edges[i]) + answer[s];

                answer[goal] = price;
            }
        }

        for(int i = 0; i < answer.size(); i++){
            if(!visited[i] && answer[i] < m_min){
                m_min = answer[i];
                s = i;
            }
        }

        visited[s] = true;
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
