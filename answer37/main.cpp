#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<pair <int, int> > graph;
vector<int> answer;
int start;

void Input(){
    string s;
    vector<int> temp;

    freopen("input.txt", "r", stdin);
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

        while(!s.empty()){
            temp.push_back(stoi(s));

            if(temp.size() == 2){
                pair<int, int> pt;
                pt.first = temp[0];
                pt.second = temp[1];
                graph.push_back(pt);
                temp.clear();
            }
        }
    }

    for(auto a : graph){
        cout << a.first << " - " << a.second << endl;
    }
}

int main()
{
    Input();
    return 0;
}
