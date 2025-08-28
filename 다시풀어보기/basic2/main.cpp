#include <cstdio>
char ch[21] = "0123456789ABCDEFGHIJ";

void f1(int n, int k){
    if( n < k ){
        printf("%X", n);
        return;
    }
    f1(n/k, k);
    printf("%X", n%k);
}

void f2(int n, int k){
    if(n > 0){
        f2(n/k, k);
        printf("%X", n%k);
    }
}

void f3(int n, int k){
    if(n > 0){
        f3(n/k, k);
        printf("%c", ch[n%k]);
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    //n = 255, k = 16;

    //f1(n, k);
    //printf("\n");

    //f2(n, k);
    //printf("\n");

    f3(n, k);

    return 0;
}
