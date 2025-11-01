#include<stdio.h>

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
int rowCnt, colCnt;
int data[110][110];

using namespace std;

void ArrayPrn(){
    for(int i = 0; i < rowCnt; i++){
        for(int j = 0; j < colCnt; j++){
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &rowCnt, &colCnt);
    for(int i = 0; i < rowCnt; i++)
        for(int j = 0; j < colCnt; j++)
            scanf("%d", &data[i][j]);
    fclose(stdin);
}

bool Inside(int a, int b){
    return ((0 <= a && a < rowCnt) && (0 <= b && b< colCnt));
}

int Init(){
    int cnt = 0;
    for(int i = 0;  i < rowCnt; i++) {
        for(int j = 0; j < rowCnt; j++){
            if(data[i][j] == -1 || data[i][j] > 2)
                data[i][j] = 0;
            else if(data[i][j] == 2 || data[i][j] == 1){
                data[i][j] = 1;
                cnt++;
            }
        }
    }
    printf("Ä¡Áî ¼ö = %d\n", cnt);
    return cnt;
}

int Solve(int a, int b){
    data[a][b] = -1;
    for(int i = 0; i < 4; i++) {
        if(Inside(a+dx[i], b+dy[i])){
            if(data[a + dx[i]][b + dy[i]] == 0)
                Solve(a+dx[i], b+dy[i]);
            else if(data[a + dx[i]][b + dy[i]] > 0)
                data[a + dx[i]][b + dy[i]]++;
        }
    }
}

int main()
{
    int hour;
    Input();
    ArrayPrn();

    for(hour = 0; Init(); hour++){
        ArrayPrn();
        Solve(0, 0);
        ArrayPrn();
    }

    printf("%d", hour);
    return 0;
}
