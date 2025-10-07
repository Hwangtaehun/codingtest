#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int n, k;
vector<string> cmd;
string answer;

void Input(){
    freopen("input.txt", "r", stdin);

    string cmdLine;

    cin >> n;
    cin >> k;

    cin.ignore();
    getline(cin, cmdLine);

    cmdLine.erase(std::remove(cmdLine.begin(), cmdLine.end(), '['), cmdLine.end());
    cmdLine.erase(std::remove(cmdLine.begin(), cmdLine.end(), ']'), cmdLine.end());
    cmdLine.erase(std::remove(cmdLine.begin(), cmdLine.end(), '\"'), cmdLine.end());

    stringstream ss(cmdLine);
    string token;
    while (getline(ss, token, ',')) {

        token.erase(0, token.find_first_not_of(" \t\n\r"));
        token.erase(token.find_last_not_of(" \t\n\r") + 1);
        if (!token.empty())
            cmd.push_back(token);
    }
}

void Output(){

    freopen("output.txt", "w", stdout);
    cout << answer;
    fclose(stdout);
}

void Solve(){
    stack<int> deleted;
    vector<int> up;
    vector<int> down;

    for(int i = 0; i < n + 2; i++){
        up.push_back(i - 1);
        down.push_back(i + 1);
    }

    k++;

    for(int i = 0; i < cmd.size(); i++){
        if(cmd[i][0] == 'C') {
            deleted.push(k);
            down[up[k]] = down[k];
            up[down[k]] = up[k];

            if(down[k] == n + 1)
                k = up[k];
            else
                k = down[k];
        }
        else if(cmd[i][0] == 'Z') {
            int r = deleted.top();
            down[up[r]] = r;
            up[down[r]] = r;
            deleted.pop();
        }
        else {
            int sz = stoi(cmd[i].substr(2));

            if(cmd[i][0] == 'U') {
                for(int j = 0; j < sz; j++){
                    k =  up[k];
                }
            }else if(cmd[i][0] == 'D') {
                for(int j = 0; j < sz; j++){
                    k = down[k];
                }
            }
        }
    }

    answer.append(n, 'O');

    while(!deleted.empty()) {
        answer[ deleted.top() - 1 ] = 'X';
        deleted.pop();
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
