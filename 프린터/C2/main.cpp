#include <stdio.h>
#define SIZE 9

using namespace std;

int r, c, big = 0;
int mi, mj;
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

void Maximum1(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(big < data[i][j]){
                big = data[i][j];
                c = i + 1, r = j + 1;
            }
        }
    }
}

void Maximum2(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(data[mi][mj] < data[i][j]){
                mi = i;
                mj = j;
            }
        }
    }
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
    Maximum1();
    Maximum2();
    printf("%d\n%d %d\n", data[mi][mj], mi + 1, mj + 1);
    Output();
    return 0;
}
