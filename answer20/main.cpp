#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> participant, completion;
string result;

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
                if(i == 0){
                    participant.push_back(token);
                } else {
                    completion.push_back(token);
                }
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << result;
    fclose(stdout);
}

int myPow(int n){
    int num = 0;
    double p = 31;

    num = (int)pow(p, n);

    return num;
}

vector<int> vector_hashing(const vector<string> v_str){
    vector<int> v_int(v_str.size(), 0);
    const int m = 1000000007;

    for(int i = 0; i < v_str.size(); i++){
        int num = 0;
        string str = v_str[i];
        for(int j = 0; j < str.size(); j++){
            num =+ (myPow(j) * str[j]) % m;
        }

        v_int[i] = num % m;
    }

    return v_int;
}

void Solve(){
    vector<int> v_part, v_com;

    v_part = vector_hashing(participant);
    v_com = vector_hashing(completion);

    for(int i = 0; i < v_part.size(); i++){
        if(find(v_com.begin(), v_com.end(), v_part[i]) == v_com.end()){
            result = participant[i];
            return;
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
