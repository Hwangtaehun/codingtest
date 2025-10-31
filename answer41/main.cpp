#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer;
vector< vector<int> > maps;

void Input(){
    string s;
    vector<int> temp;

    freopen("input.txt", "r", stdin);
    getline(cin, s);
    fclose(stdin);

    s.erase(remove(s.begin(), s.end(), '['), s.end());

    stringstream ss(s);
    string token;

    while (getline(ss, token, ',')) {
        token.erase(0, token.find_first_not_of(" \t\n\r"));
        token.erase(token.find_last_not_of(" \t\n\r") + 1);

        if (token.find(']') != string::npos) {
            token.erase(remove(token.begin(), token.end(), ']'), token.end());
            if (!token.empty())
                temp.push_back(stoi(token));

            maps.push_back(temp);
            temp.clear();
        } else {
            if (!token.empty())
                temp.push_back(stoi(token));
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << answer;
    fclose(stdout);
}

int main()
{
    Input();
    for (auto &row : maps) {
        for (auto v : row)
            cout << v << " ";
        cout << endl;
    }
    return 0;
}
