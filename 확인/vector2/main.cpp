#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int> > v1;

    int rows = 3;
    int cols = 4;
    vector<vector<int> > v2(rows, vector<int>(cols));

    int val = 9;
    vector<vector<int> > v3(rows, vector<int>(cols, val));

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << v3[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int> > v4 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for(int i = 0; i < v4.size(); i++){
        for(int j = 0; j < v4[0].size(); j++){
            cout << v4[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
