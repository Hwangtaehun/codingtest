#include <cstdio>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector< vector<int> > arr1, arr2, result;

void readVector(std::vector<std::vector<int>>& arr) {
    int val;
    char delimiter;

    // ù ��° [[ �� �н��ϴ�. (scanf�� ������ �ǳʶݴϴ�)
    scanf("[[");

    // ���� ���͵��� �ݺ��ϸ� �н��ϴ�.
    while (true) {
        std::vector<int> inner_vec;

        // ���� ������ ù ��° ���ڸ� �н��ϴ�.
        scanf("%d", &val);
        inner_vec.push_back(val);

        // ��ǥ�� ���е� ������ ���ڸ� ��� �н��ϴ�.
        while (scanf(",%d", &val) == 1) {
            inner_vec.push_back(val);
        }

        arr.push_back(inner_vec);

        // ���� ������ ���� ]�� �� ���� ���ڸ� �н��ϴ�.
        // ���� ���ڰ� ] �̸� ��ü �迭�� ���̰�, , �̸� ���� ���� �迭�� �ֽ��ϴ�.
        if (scanf("]%c", &delimiter) == 1) {
            if (delimiter == ']') {
                break; // ��ü �迭�� �� ]]
            }
        }
    }
}

void Input(){
    freopen("input.txt", "r", stdin);

    // arr1�� ������ �н��ϴ�.
    readVector(arr1);

    // arr2�� ������ �н��ϴ�. (freopen�� �ڵ����� �ٹٲ��� �ǳʶݴϴ�)
    readVector(arr2);

    // ����� ����Ͽ� Ȯ���մϴ�.
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

    // ǥ�� �Է� ������ �ݽ��ϴ�.
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
