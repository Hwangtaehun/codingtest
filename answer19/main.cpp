#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> string_list, query_list, result;

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
                    string_list.push_back(token);
                } else {
                    query_list.push_back(token);
                }
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);

    cout << "[";

    for(int i = 0; i < result.size(); i++){
        cout << result[i];

        if(i != result.size() - 1){
            cout << ", ";
        }
    }

    cout << "]";

    fclose(stdout);
}

vector<int> Hash_map(vector<string> v_str){
    long long p = 31;
    long long m = 1000000007;

    vector<int> v_list(v_str.size(), 0);

    for(int i = 0; i < v_str.size(); i++){
        string str = v_str[i];
        long long cur_hash = 0;
        long long pow = 1;

        for(int j = 0; j < str.size(); j++){
            long long char_num = str[j];
            long long term = (char_num * pow) % m;
            cur_hash = (cur_hash + term) % m;
            pow = (pow * p) % m;
        }

        v_list[i] = (int)cur_hash;
    }

    return v_list;
}

void Solve(){
    vector<int> v_string = Hash_map(string_list);
    vector<int> v_query = Hash_map(query_list);
    result.resize(v_query.size());

    for(int i = 0; i < v_query.size(); i++){
        result[i] = "false";

        for(int j = 0; j < v_string.size(); j++){
            if(v_query[i] == v_string[j]){
                result[i] = "true";
                break;
            }
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
