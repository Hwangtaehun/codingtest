#include <iostream>
#include <cstdio>
#include <sstream>
#include <limits>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, answer;
vector<vector <int> > costs;

void Input(){
    string line;
    vector<int> temp;

    freopen("input.txt", "r", stdin);
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, line);
    fclose(stdin);

    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());

    stringstream ss(line);

    while(getline(ss, line, ',')){
        line.erase(0, line.find_first_not_of(" \t\n\r"));
        line.erase(line.find_last_not_of(" \t\n\t") + 1);

        if(!line.empty()){
            temp.push_back(stoi(line));

            if(temp.size() == 3){
                costs.push_back(temp);
                temp.clear();
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << answer;
    fclose(stdout);
}

bool Compare(const vector<int> n1, const vector<int> n2){
    return n1[2] < n2[2];
}

vector<int> parent;

int findParent(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}

void Solve(){
    sort(costs.begin(), costs.end(), Compare);
    parent.resize(n);

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < costs.size(); i++){
        int a = costs[i][0], b = costs[i][1], cost = costs[i][2];

        if(findParent(a) != findParent(b)) {
            unionParent(a, b);
            answer += cost;
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
