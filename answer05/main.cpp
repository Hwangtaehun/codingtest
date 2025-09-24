#include <cstdio>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector< vector<int> > arr1, arr2, result;

vector<vector<int>> readMatrix() {
    vector<vector<int>> result;
    vector<int> row;
    int num;
    char ch;

    while (true) {
        if (scanf("%c", &ch) != 1) break; // EOF

        if (ch == '[') {
            row.clear();
        } else if (ch == ']') {
            if (!row.empty()) {
                result.push_back(row);
                row.clear();
            }
        } else if (ch == ',' || ch == ' ') {
            continue;
        } else if (ch == '\n') {
            break; // 한 줄 끝났으면 종료
        } else if (ch >= '0' && ch <= '9') {
            ungetc(ch, stdin);
            scanf("%d", &num);
            row.push_back(num);
        }
    }
    return result;
}

void Input() {
    freopen("input.txt", "r", stdin);

    arr1 = readMatrix(); // 첫 번째 줄 읽기
    arr2 = readMatrix(); // 두 번째 줄 읽기

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("[");
    for(int i = 0; i < result.size(); i++){
        printf("[");
        for(int j = 0; j < result[i].size(); j++){
            printf("%d", result[i][j]);
            if(j != result[i].size() - 1){
                printf(", ");
            }
        }
        printf("]");
        if(i != result.size() - 1){
            printf(", ");
        }
    }
    printf("]");
    fclose(stdout);
}

void Print(){
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("------------------\n");
}

void Solve(){
    result.resize(arr1.size());
    for(int i = 0; i < result.size(); i++){
        result[i].resize(arr2[0].size());
    }

    for(int i = 0; i < arr1.size(); i++){
        for(int k =0; k < arr2[0].size(); k++){
            for(int l = 0; l < arr2.size(); l++){
                result[i][k] += arr1[i][l] * arr2[l][k];
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
