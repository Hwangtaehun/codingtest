#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int n, k;
vector<string> cmd;
vector<char> g_result;

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

    g_result.resize(n); for(int i = 0; i < g_result.size(); i++){ g_result[i] = 'O'; }
}

void Output(){
    //string answer;
    //answer.assign(g_result.begin(), g_result.end());

    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_result.size(); i++){
        printf("%c", g_result[i]);
    }
    fclose(stdout);
}

void Print_result(){
    for(int i = 0; i < g_result.size(); i++){
        printf("%d = %c\n", i, g_result[i]);
    }
    printf("\n");
}

int Check(string str){
    if(str.compare("C") == 0 || str.compare("Z") == 0){
        return 0;
    } else {
        int num;
        if(str[0] == 'D'){
            num = str[2] - '0';
            return num;
        }else{
            num = str[2] - '0';
            return -num;
        }
    }
}

int Move(int num, int cur){
    int cnt = 0;
    bool plu = true;

    if(num < 0){
        plu = false;
        num = abs(num);
    }

    while(true){
        if(plu){
            cur++;
        }else{
            cur--;
        }

        if(g_result[cur] == 'O'){
            cnt++;
        }

        if(cnt == num){
            break;
        }
    }

    return cur;
}

void Solve(){
    int m_cur = k;
    stack<int> restore;

    for(int i = 0; i < cmd.size(); i++){
        string str = cmd[i];
        if(Check(str) == 0){
            if(str.compare("C") == 0) {
                restore.push(m_cur);
                g_result[m_cur] = 'X';
            } else {
                g_result[restore.top()] = 'O';
                restore.pop();
            }
        } else {
            m_cur = Move(Check(str), m_cur);
        }
        //Print_result();
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
