#include <stdio.h>

int n;

void FileTest1();
void FileTest2();
void FileTest3();
void FileTest4();

int main()
{
    //FileTest1();
    //FileTest2();
    //FileTest3();
    FileTest4();
    return 0;
}

void FileTest1()
{
    printf("정수 입력: ");
    scanf("%d", &n);
    printf("표준 출력: %d\n", n);
}

void FileTest2()
{
    FILE *inf = fopen("in.txt", "r");
    FILE *outf = fopen("out2.txt", "w");
    fscanf(inf, "%d", &n);
    fprintf(outf, "fopen으로 출력: %d\n", n);
}

void FileTest3()
{
    FILE *inf = stdin;
    FILE *outf = stdout;
    //FILE *inf = fopen("in.txt", "r");
    //FILE *outf = fopen("out.txt", "w");
    printf("정수 입력 2: ");
    fscanf(inf, "%d", &n);
    fprintf(outf, "표준 출력 2: %d\n", n);
}

void FileTest4()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    //FILE *fi = freopen("in.txt", "r", stdin);
    //FILE *fo = freopen("out3.txt", "w", stdout);

    scanf("%d", &n);
    printf("freopen으로 재 설정 후 출력: %d\n", n);
    fclose(stdin);
    fclose(stdout);
    freopen("con", "r", stdin);
    freopen("con", "w", stdin);

    printf("표준입출력으로 다시 설정 후 입력: ");
    scanf("%d", &n);
    printf("표준입출력으로 다시 설정 후 출력: %d\n", n);
}
