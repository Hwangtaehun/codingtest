#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> want, discount;
vector<int> number;
int answer;

void Input(){
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    while(getline(cin, line)){
        if(!line.empty()){
            lines.push_back(line);
        }
    }

    fclose(stdin);

    for(int i = 0; i < lines.size(); i++){
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), '['), lines[i].end());
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), ']'), lines[i].end());
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), '\"'), lines[i].end());

        stringstream ss(lines[i]);
        string token;

        while(getline(ss, token, ',')) {
            token.erase(0, token.find_first_not_of(" \t\n\r"));
            token.erase(token.find_last_not_of(" \t\n\r") + 1);

            if(!token.empty()){
                if(i == 0){
                    want.push_back(token);
                } else if(i == 1){
                    int n;
                    stringstream(token) >> n;

                }
            }
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
