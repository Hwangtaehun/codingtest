#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

vector<string> orders, answer;
vector<int> course;

void Input(){
    string<vector> lines;
    string line;

    freopen("input.txt", "r", stdin);

    while(getline(cin, line)){
        if(!line.empty()) {
            lines.push_back(line);
        }
    }

    fclose(stdin);

    stringstream ss(lines[i]);
    string token;

    while(getline(ss, token, ',')) {
        token.erase(0, token.find_first_not_of(" \t\n\r"));
        token.erase(token.find_last_not_of(" \t\n\r") + 1);

        if(!token.empty()) {
            if(i == 0){
                orders.push_back(token);
            }else{
                course.push_back(stoi(token));
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);

    cout << "[";
    for(int i = 0; i < answer.size(); i++){
        if(i > 0){
            cout << ",";
        }
        cout << answer[i];
    }
    cout << "]";

    fclose(stdout);
}

int main()
{
    return 0;
}
