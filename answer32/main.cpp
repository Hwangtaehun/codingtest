#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> nodeinfo, answer;

template <typename T>
void Vector_print(T v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void Input(){
    string line;

    freopen("input.txt", "r", stdin);
    getline(cin, line);
    fclose(stdin);

    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());

    stringstream ss(line);
    string token;

    vector<int> temp;
    while (getline(ss, token, ',')) {
        token.erase(0, token.find_first_not_of(" \t\n\r"));
        token.erase(token.find_last_not_of(" \t\n\r") + 1);

        if (!token.empty()) {
            temp.push_back(stoi(token));
            if (temp.size() == 2) {
                nodeinfo.push_back(temp);
                temp.clear();
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);

    printf("[");
    for(int i = 0; i < answer.size(); i++){
        if(i != 0){
            printf(", ");
        }
        printf("[");
        for(int j = 0; j < answer[i].size(); j++){
            if(j != 0){
                printf(", ");
            }
            printf("%d", answer[i][j]);
        }
        printf("]");
    }
    printf("]");

    fclose(stdout);
}

int main()
{
    Input();
    return 0;
}
