#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

vector<int> progresses, speeds, answer;

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
    for(int i = 0; i < answer.size(); i++){
        printf("%d ", answer[i]);
    }
    fclose(stdout);
}

void Solve(){
    int cnt = 0;
    int max_day;
    vector<int> days_left(speeds.size());

    for(int i = 0; i < days_left.size(); i++){
        days_left[i] = ceil((100.0 - progresses[i]) / speeds[i]);
    }

    max_day = days_left[0];

    for(int i = 0; i < days_left.size(); i++){
        if(days_left[i] <= max_day){
            cnt++;
        }else{
            answer.push_back(cnt);
            cnt = 1;
            max_day = days_left[i];
        }
    }

    answer.push_back(cnt);
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
