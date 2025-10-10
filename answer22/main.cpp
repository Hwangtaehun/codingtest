#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<string> phoneBook;
bool answer;

void Input(){
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    while (getline(cin, line)) {
        if (!line.empty()){
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

        while (getline(ss, token, ',')) {
            token.erase(0, token.find_first_not_of(" \t\n\r"));
            token.erase(token.find_last_not_of(" \t\n\r") + 1);
            if (!token.empty()){
               phoneBook.push_back(token);
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    if(answer){
        printf("True");
    }else{
        printf("False");
    }
    fclose(stdout);
}

void Solve(){
    answer = true;
    sort(phoneBook.begin(), phoneBook.end());

    for(int i = 0; i < phoneBook.size() - 1; i++){
        if(phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size())){
            answer = false;
            break;
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
