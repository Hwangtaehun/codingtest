#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#define PRICE 100

using namespace std;

vector<string> enroll, referral, seller;
vector<int> amount, answer;

void Input(){
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    while(getline(cin, line)) {
        if(!line.empty()) {
            lines.push_back(line);
        }
    }

    fclose(stdin);

    for(int i = 0; i < lines.size(); i++) {
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), '['), lines[i].end());
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), ']'), lines[i].end());
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), '\"'), lines[i].end());

        string s;
        stringstream ss(lines[i]);

        while(getline(ss, s, ',')) {
            s.erase(0, s.find_first_not_of(" \t\n\r"));
            s.erase(s.find_last_not_of(" \t\n\r") + 1);

            if(!s.empty()) {
                if(i == 0) {
                    enroll.push_back(s);
                } else if(i == 1) {
                    referral.push_back(s);
                } else if(i == 2) {
                    seller.push_back(s);
                } else {
                    amount.push_back(stoi(s));
                }
            }
        }
    }
}

void Output() {
    freopen("output.txt", "w", stdout);

    cout << "[";

    for(int i = 0; i < answer.size(); i++){
        if(i != 0){
            cout << ",";
        }
        cout << answer[i];
    }

    cout << "]";

    fclose(stdout);
}

template <typename T>
void Vector_print(T v){
    for(auto a : v){
        cout << a << " ";
    }
    cout << endl;
}

template <typename T>
void Map_print(const T& v) {
    for (auto a : v) {
        cout << a.first << ": " << a.second << endl;
    }
    cout << endl;
}

void Solve(){
    unordered_map<string, int> chart_amount;
    unordered_map<string, string> enroll_parent;

    for(int i = 0; i < enroll.size(); i++) {
        enroll_parent[enroll[i]] = referral[i];
    }

    for(int i = 0; i < seller.size(); i++) {
        int total = amount[i]  * PRICE;
        string child = seller[i];

        while(total > 0 && child != "-") {
            string parent = enroll_parent[child];
            int interest = total * 0.1;
            chart_amount[child] += total - interest;
            total = interest;
            child = parent;
        }
    }

    for(int i = 0; i < enroll.size(); i++){
        answer.push_back(chart_amount[enroll[i]]);
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
