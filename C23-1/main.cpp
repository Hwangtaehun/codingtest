#include <cstdio>
#include <cmath>

using namespace std;

int data[1002][2], n, m, ans = 0x0fffffff;
int di[1002][1002];

void Distance(){
    int a, b;
    for(a = 0; a < m + 2; a++){
        for(b = 0; b < m + 2; b++){
           di[a][b] = abs(data[a][0] - data[b][0]) + abs(data[a][1] - data[b][1]);
        }
    }
}

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    data[0][0] = data[0][1] = 1;
    data[1][0] = data[1][1] = n;
    for(int i = 2; i < m + 2; i++){
        scanf("%d%d", &data[i][0], &data[i][1]);
    }
    fclose(stdin);
}

void ArrayPrn(){
    for(int a = 0; a < m + 2; a++){
        for(int b = 0; b < 2; b++){
            printf("%3d", data[a][b]);
        }
        printf("\n");
    }

    printf("\n");

    for(int a = 0; a < m + 2; a++){
        for(int b = 0; b < m + 2; b++){
            printf("%3d", di[a][b]);
        }
        printf("\n");
    }
    printf("\n");
}

void Solve(int a, int b, int d){
    int next = (a > b ? a : b) + 1;
    printf("%d %d %d %3d %3d\n", a, b, next, d, di[a][next]);

    if(next >= m+2){
        if(d < ans)
            ans = d;
        return;
    }

    Solve(next, b, d + di[a][next]);
    Solve(a, next, d + di[b][next]);
}

int main()
{
    Input();
    Distance();
    ArrayPrn();
    Solve(0, 1, 0);
    printf("%d", ans);
    return 0;
}
