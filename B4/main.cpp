#include <stdio.h>
#include <queue>

using namespace std;

int g_row, g_col;
char **g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_row, g_col);

    g_data = new char*[g_row];

    for(int i = 0; i < g_row; i++){
        g_data[i] = new char[g_col];
    }

    for(int i = 0; i < g_row; i++){
        for(int j = 0; j < g_col; j++){
            scanf(" %c", &g_data[i][j]);
        }
    }
    fclose(stdin);
}

int main()
{
    Input();
    for(int i = 0; i < g_row; i++){
        for(int j = 0; j < g_col; j++){
            printf("%c ", g_data[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < g_row; i++) {
        delete[] g_data[i];
    }

    delete[] g_data;

    return 0;
}
