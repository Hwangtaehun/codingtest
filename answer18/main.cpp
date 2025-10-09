#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<int> arr;
string result;
int target;

void Input(){
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    scanf("%d", &target);

    while (getline(cin, line)) {
        if (!line.empty())
            lines.push_back(line);
    }

    fclose(stdin);

    for(int i = 0; i < lines.size(); i++){
        string s = lines[i];
        s.erase(remove(s.begin(), s.end(), '['), s.end());
        s.erase(remove(s.begin(), s.end(), ']'), s.end());

        stringstream ss(s);
        string token;
        while (getline(ss, token, ',')) {
            token.erase(0, token.find_first_not_of(" \t\n\r"));
            token.erase(token.find_last_not_of(" \t\n\r") + 1);
            if (!token.empty())
                arr.push_back(stoi(token));
        }
    }
}

void Solve(){
    result = "false";

    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size(); j++){
            if((i + j) == target){
                result = "true";
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << result;
    fclose(stdout);
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
