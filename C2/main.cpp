#include <stdio.h>
#define SIZE 9

using namespace std;

int r, c, big = 0;
int data[SIZE][SIZE];

void Print(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%2d ", data[i][j]);
        }
        printf("\n");
    }
}

void Input(){
    freopen("input.txt", "r", stdin);
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            scanf("%d", &data[i][j]);
        }
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d\n", big);
    printf("%d %d", c, r);
    fclose(stdout);
}

int main()
{
    Input();
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(big < data[i][j]){
                big = data[i][j];
                c = i, r = j;
            }
        }
    }
    Output();
    return 0;
}
