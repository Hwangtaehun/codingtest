#include <iostream>
#include <cstdio>
#include <sstream>
#include <limits>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, answer = 0xFFFFFFF;
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

bool Check(const vector<bool> vb){
    for(int i = 0; i < vb.size(); i++){
        if(!vb[i]){
            return false;
        }
    }
    return true;
}

void Find_route(vector<bool> visisted, vector<bool> used, vector<vector <int> > costs, int cnt, int cost, int n){
    if(cnt == n - 1){
        if(Check(visisted) && cost < answer){
            answer = cost;
        }
        return;
    }

    for(int i = 0; i < costs.size(); i++){
        if(!used[i]){
            used[i] = true;
            visisted[costs[i][0]] = true;
            visisted[costs[i][1]] = true;
            Find_route(visisted, used, costs, cnt + 1, cost + costs[i][2], n);
            visisted[costs[i][0]] = false;
            visisted[costs[i][1]] = false;
            used[i] = false;
        }
    }
}

void Solve(){
    int cnt = 0;
    vector<bool> used(costs.size(), false);
    vector<bool> visited(n, false);
    sort(costs.begin(), costs.end(), Compare);

    Find_route(visited, used, costs, 0, 0, n);

    printf("%d\n", answer);
}

int main()
{
    Input();
    Solve();
    return 0;
}
