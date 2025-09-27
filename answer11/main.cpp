#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

string s;
int result;

void Input(){
    freopen("input.txt", "r", stdin);
    cin >> s;
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << result;
    fclose(stdout);
}

void Solve(){
    vector<char> data(s.begin(), s.end());
    while(!data.empty()){
        bool duple = false;
        for(int i = 0; i < data.size(); i++){
            if(i != data.size() - 1){
                if(data[i] == data[i + 1]){
                    duple = true;
                    data.erase(data.begin() + i, data.begin() + i + 2);
                    break;
                }
            }
        }

        if(!duple){
            result = 0;
            return;
        }
    }

    result = 1;
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
