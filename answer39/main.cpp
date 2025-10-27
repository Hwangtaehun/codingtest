#include <limits>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> edges;
int num_vertices, source;
vector<int> answer;

void Input(){
    string s;
    vector<int> vt;

    freopen("input.txt", "r", stdin);

    cin >> source >> num_vertices;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);

    fclose(stdin);

    s.erase(remove(s.begin(), s.end(), '['), s.end());
    s.erase(remove(s.begin(), s.end(), ']'), s.end());

    stringstream ss(s);

    while(getline(ss, s, ',')){
        s.erase(0, s.find_first_not_of(" \t\n\r"));
        s.erase(s.find_last_not_of(" \t\n\r") + 1);

        if(!s.empty()){
            vt.push_back(stoi(s));

            if(vt.size() == 3){
                tuple<int, int, int> tt = make_tuple(vt[0], vt[1], vt[2]);
                edges.push_back(tt);
                vt.clear();
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
        if(!v[i]){
            return true;
        }
    }

    return false;
}

template <typename T>
void vector_Print(T v){
    for(auto a: v){
        cout << a << " ";
    }
    cout << endl;
}

void Solve(){
    int s = source;
    vector<bool> visited(num_vertices);

    answer.assign(num_vertices, 0xFFFFFFF);
    answer[s] = 0;
    visited[s] = true;

    while(Check(visited)){
        vector<int> transfer;

        for(int i = 0; i < edges.size(); i++){
            if(get<0>(edges[i]) == s){
                int goal = get<1>(edges[i]);
                int value = get<2>(edges[i]);
                answer[goal] = value;
                transfer.push_back(goal);
            }
        }

        for(int h = 0; h < transfer.size(); h++){
            for(int i = 0; i < edges.size(); i++){
                if(transfer[h] == get<0>(edges[i])){
                    int goal = get<1>(edges[i]);
                    int value = get<2>(edges[i]) + answer[transfer[h]];
                    if(value < answer[goal]){
                        answer[goal] = value;
                    }
                    cout << "start = " << transfer[h] << ", goal = " << goal << endl;
                }
            }
        }
    }

    vector_Print(answer);
}

int main()
{
    Input();
    Solve();
    //Output();
    return 0;
}
