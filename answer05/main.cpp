#include <cstdio>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector< vector<int> > arr1, arr2, result;

void readVector(std::vector<std::vector<int>>& arr) {
    int val;
    char delimiter;

    // 첫 번째 [[ 를 읽습니다. (scanf는 공백을 건너뜁니다)
    scanf("[[");

    // 내부 벡터들을 반복하며 읽습니다.
    while (true) {
        std::vector<int> inner_vec;

        // 내부 벡터의 첫 번째 숫자를 읽습니다.
        scanf("%d", &val);
        inner_vec.push_back(val);

        // 쉼표로 구분된 나머지 숫자를 모두 읽습니다.
        while (scanf(",%d", &val) == 1) {
            inner_vec.push_back(val);
        }

        arr.push_back(inner_vec);

        // 내부 벡터의 끝인 ]와 그 다음 문자를 읽습니다.
        // 다음 문자가 ] 이면 전체 배열의 끝이고, , 이면 다음 내부 배열이 있습니다.
        if (scanf("]%c", &delimiter) == 1) {
            if (delimiter == ']') {
                break; // 전체 배열의 끝 ]]
            }
        }
    }
}

void Input(){
    freopen("input.txt", "r", stdin);

    // arr1의 내용을 읽습니다.
    readVector(arr1);

    // arr2의 내용을 읽습니다. (freopen은 자동으로 줄바꿈을 건너뜁니다)
    readVector(arr2);

    // 결과를 출력하여 확인합니다.
    std::cout << "arr1 contents:" << std::endl;
    for (const auto& row : arr1) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\narr2 contents:" << std::endl;
    for (const auto& row : arr2) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    // 표준 입력 파일을 닫습니다.
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
    //Solve();
    //Output();
    return 0;
}
