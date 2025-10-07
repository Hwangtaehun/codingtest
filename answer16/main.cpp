#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

vector<int> progresses, speeds, g_result;

void Input(){
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    while (getline(cin, line)) {
        if (!line.empty())
            lines.push_back(line);
    }

    auto parseVector = [](const string& str) {
        vector<int> result;
        string s = str;

        s.erase(remove(s.begin(), s.end(), '['), s.end());
        s.erase(remove(s.begin(), s.end(), ']'), s.end());

        stringstream ss(s);
        string token;
        while (getline(ss, token, ',')) {
            token.erase(0, token.find_first_not_of(" \t\n\r"));
            token.erase(token.find_last_not_of(" \t\n\r") + 1);
            if (!token.empty())
                result.push_back(stoi(token));
        }
        return result;
    };

    if (lines.size() >= 1)
        progresses = parseVector(lines[0]);
    if (lines.size() >= 2)
        speeds = parseVector(lines[1]);

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_result.size(); i++){
        printf("%d ", g_result[i]);
    }
    fclose(stdout);
}

void Solve(){
    int m_fin = 0;
    queue<int> q_pro;

    for(int i = 0; i < progresses.size(); i++){
        q_pro.push(progresses[i]);
    }

    while(!q_pro.empty()){
        int m_day = ceil((100 - q_pro.front()) / speeds[m_fin]);
        printf("m_day = %d\n", m_day);

        for(int i = m_fin; i < speeds.size(); i++){
            int num = q_pro.front() + (speeds[i] * m_day);
            q_pro.pop();
            q_pro.push(num);
            printf("%d ", num);
        }
        printf("\n");

        if(q_pro.front() >= 100){
            int cnt = 0;
            for(int i = m_fin; i < speeds.size(); i++){
                if(q_pro.front() >= 100){
                    cnt++;
                    q_pro.pop();
                }else{
                    m_fin = i;
                    break;
                }
            }

            g_result.push_back(cnt);
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
