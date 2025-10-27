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

    cin >> num_vertices >> source;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);

    fclose(stdin);

    s.erase(remove(s.begin(), s.end(), '['), s.end());
    s.erase(remove(s.begin(), s.end(), ']'), s.end());

    cout << s << endl;

    stringstream ss(s);

    while(ss, s, ','){
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

int main()
{
    Input();
    for (auto &e : edges) {
        cout << get<0>(e) << ", "
             << get<1>(e) << ", "
             << get<2>(e) << endl;
    }
    return 0;
}
