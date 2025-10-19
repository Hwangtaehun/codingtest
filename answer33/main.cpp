#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int k;
vector< vector<char> > operations;
vector<bool> answer;

void Input(){
    string line;
    vector<char> temp;

    freopen("input.txt", "r", stdin);
    cin >> k;
    getline(cin, line);
    getline(cin, line);
    fclose(stdin);

    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());
    line.erase(remove(line.begin(), line.end(), '\''), line.end());

    stringstream ss(line);
    line.clear();

    while(getline(ss, line, ',')) {

        line.erase(0, line.find_first_not_of(" \t\n\r"));
        line.erase(line.find_last_not_of(" \t\n\r") + 1);

        if(!line.empty()) {
            char c = line[0];
            temp.push_back(c);

            if(temp.size() == 3) {
                operations.push_back(temp);
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

        if(answer[i]){
            cout << "true";
        }else{
            cout << "false";
        }
    }

    cout << "]";
    fclose(stdout);
}

void bool_Print(vector<bool> res){
    for(int i = 0; i < res.size(); i++){
        if(i != 0){
            cout << ", ";
        }

        if(answer[i]){
            cout << "true";
        }else{
            cout << "false";
        }
    }
    cout << endl;
}

int Find_element(const vector< set<int> > vs, int num1, int num2) {
    for(int i = 0; i < vs.size(); i++) {
        auto it1 = vs[i].find(num1);
        auto it2 = vs[i].find(num2);

        if (it1 != vs[i].end() || it2 != vs[i].end()) {
            return i;
        }
    }

    return -1;
}

bool Find_union(set<int> us, int n1, int n2) {
    auto it1 = us.find(n1);
    auto it2 = us.find(n2);

    if(it1 != us.end() && it2 != us.end()){
        return true;
    }else{
        return false;
    }
}

void Solve(){
    vector< set<int> > m_union;

    for(int i = 0; i < operations.size(); i++){
        if(operations[i][0] == 'u') {
            int index = Find_element(m_union, operations[i][1]  - '0', operations[i][2]  - '0');

            if (!m_union.empty() && index != -1) {
                m_union[index].insert(operations[i][1]  - '0');
                m_union[index].insert(operations[i][2]  - '0');
            } else {
                set<int> m_set = {operations[i][1]  - '0', operations[i][2]  - '0'};
                m_union.push_back(m_set);
            }
        } else {
            bool check;
            int num1 = operations[i][1] - '0';
            int num2 = operations[i][2] - '0';

            for(int j = 0; j < m_union.size(); j++){
                check = Find_union(m_union[j], num1, num2);

                if(check){
                    break;
                }
            }

            answer.push_back(check);
        }
    }
}

//solve
vector<int> parents;
vector<int> rankData;

int charToInt(char c) {
    return c - '0';
}

int Find1(int x) {
    if (parents[x] == x) {
        return x;
    }

    parents[x] = Find1(parents[x]);

    return parents[x];
}

int Find2(int x) {
    if (parents[x] == x) {
        return x;
    }

    return Find2(parents[x]);
}

void unionSet1(int x, int y) {
    int root1 = Find1(x);
    int root2 = Find1(y);

    if(root1 != root2) {
        if (rankData[root1] < rankData[root2]) {
            parents[root1] = root2;
        } else if (rankData[root1] > rankData[root2]) {
            parents[root2] = root1;
        } else {
            parents[root2] = root1;
            rankData[root1]++;
        }
    }
}

void unionSet2(int x, int y) {
    int root1 = Find2(x);
    int root2 = Find2(y);

    if(root1 != root2) {
        parents[root1] =  root2;
    }
}

vector<bool> solution1(){
    vector<bool> results;

    parents.resize(k);
    rankData.resize(k, 0);

    for(int i = 0; i < k; ++i){
        parents[i] = i;
    }

    for(const auto& op : operations) {
        if(op[0] == 'u') {
            int x = charToInt(op[1]);
            int y = charToInt(op[2]);
            results.push_back(Find1(x) == Find1(y));
        }
    }

    return results;
}

vector<bool> solution2() {
    vector<bool> results;

    for(int i = 0; i < k; ++i){
        parents[i] = i;
    }

    for(const auto& op : operations) {
        if (op[0] == 'u') {
            int x = charToInt(op[1]);
            int y = charToInt(op[2]);
            unionSet2(x, y);
        } else if (op[0] == 'f') {
            int x = charToInt(op[1]);
            int y = charToInt(op[2]);
            results.push_back(Find2(x) == Find2(y));
        }
    }

    return results;
}

int main()
{
    Input();
    Solve();
    bool_Print(solution1());
    bool_Print(solution2());
    Output();
    return 0;
}
