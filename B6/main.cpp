#include <stdio.h>
#include <queue>

using namespace std;

struct ROWCOL{
    int box;
    int row; //ї­
    int col; //За
};

int g_box, g_row, g_col;
int g_dbox[6] = {0, 0, 0, 0, 1, -1}, g_drow[6] = {1, 0, -1, 0, 0, 0}, g_dcol[6] = {0, 1, 0, -1, 0, 0};
int ***data;

bool isSafe(box, row, col){
    return (box >= 0 && box < g_box) && (row >= 0 && row < g_row) && (col >= 0 && col < g_col);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
