#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> nodes;
vector<string> answer;

void Input(){
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    while(getline(cin, line)){
        if(!line.empty()) {
            lines.push_back(line);
        }
    }

    fclose(stdin);

    for(int i = 0; i < lines.size(); i++){
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), '['), lines[i].end());
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), ']'), lines[i].end());
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), '\"'), lines[i].end());

        string s;
        stringstream ss(lines[i]);

        while(getline(ss, s, ',')) {
            s.erase(0, s.find_first_not_of(" \t\n\r"));
            s.erase(s.find_last_not_of(" \t\n\r") + 1);

            if(!s.empty()) {
                nodes.push_back(stoi(s));
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
        cout << "\"" << answer[i] << "\"";
    }
    cout << "]";
    fclose(stdout);
}

string frontOrder(vector<int> nodes, int index){
    if(index < nodes.size()){
        string res = to_string(nodes[index]) + " ";
        res += frontOrder(nodes, index * 2 + 1);
        res += frontOrder(nodes, index * 2 + 2);
        return res;
    }

    return "";
}

string middleOrder(vector<int> nodes, int index){
    if(index < nodes.size()){
        string res = middleOrder(nodes, index * 2 + 1);
        res += to_string(nodes[index]) + " ";
        res += middleOrder(nodes, index * 2 + 2);
        return res;
    }

    return "";
}

string behindOrder(vector<int> nodes, int index){
    if(index < nodes.size()){
        string res = behindOrder(nodes, index * 2 + 1);
        res += behindOrder(nodes, index * 2 + 2);
        res += to_string(nodes[index]) + " ";
        return res;
    }

    return "";
}

void Solve(){
    answer.push_back(frontOrder(nodes, 0));
    answer.push_back(middleOrder(nodes, 0));
    answer.push_back(behindOrder(nodes, 0));
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
