#include <cstdio>
int n, cnt;
bool colChk[10], incChk[20], decChk[20];

using namespace std;

void TestPrn(int no, int row, int col){
    printf("no = %d, row = %d, col = %d, cnt = %d\n", no, row, col, cnt);

    for(int i = 1; i <= n; i++){
        printf("%d ", colChk[i]);
    }
    printf(" : ");
    for(int i = 1; i <= n * 2; i++){
        printf("%d ", incChk[i]);
    }
    printf(" : ");
    for(int i = 1; i <= n * 2; i++){
        printf("%d", decChk[i]);
    }
    printf("\n");
}

void Solve(int row){
    if(row > n){
        cnt++;
        return;
    }

    for(int col = 1; col <= n; col++){
        if(!colChk[col] && !incChk[row+col] && !decChk[n+(row - col)])
        {
            colChk[col] = incChk[row + col] = decChk[n + (row - col)] = true;
            TestPrn(1, row, col);

            Solve(row + 1);

            colChk[col] = incChk[row + col] = decChk[n + (row - col)] = false;
            TestPrn(2, row, col);
        }
    }
}

int main()
{
    scanf("%d", &n);
    Solve(1);
    printf("%d", cnt);
    return 0;
}
