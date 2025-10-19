#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<int> nums;
int answer;

void Input(){
    string line;

    freopen("input.txt", "r", stdin);
    getline(cin, line);
    fclose(stdin);

    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());

    stringstream ss(line);
    string token;

    while(getline(ss, token, ',')){
        token.erase(0, token.find_first_not_of(" \t\n\r"));
        token.erase(token.find_last_not_of(" \t\n\r") + 1);

        if(!token.empty()){
            nums.push_back(stoi(token));
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", answer);
    fclose(stdout);
}

void Solve(){
    set<int> kinds;

    for(int i = 0; i < nums.size(); i++){
        kinds.insert(nums[i]);
    }

    answer = min(kinds.size(), nums.size() / 2);
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
