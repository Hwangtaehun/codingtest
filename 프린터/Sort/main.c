#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct DATA
{
    int x;
    int y;
} ss[5] = { {33, 5}, {22, 3}, {11, 2}, {33, 1}, {55, 4} };
int n = 10, data[10] = {2, 6, 3, 7, 5, 0, 9, 8, 1, 4};

void ArrayPrn(){
    for(int i = 0; i < n; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
}

void DataPrn(){
    for(int i = 0; i < 5; i++){
        printf("%d, %d \t", ss[i].x, ss[i].y);
    }
    printf("\n");
}

int Asc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int Desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int AscData(const void* a, const void* b) {
    struct DATA* da = (struct DATA*)a;
    struct DATA* db = (struct DATA*)b;
    return da->x - db->x;
}

int AscData2(const void* a, const void* b) {
    struct DATA* da = (struct DATA*)a;
    struct DATA* db = (struct DATA*)b;
    if (da->x == db->x)
        return db->y - da->y;
    else
        return da->x - db->x;
}

int main()
{
    printf("Sort Àü \t: ");
    ArrayPrn();
    qsort(data, n, sizeof(data[0]), Desc);
    printf("Desc Sort ÈÄ \t: ");
    ArrayPrn();
    qsort(data, n, sizeof(data[0]), Asc);
    printf("Asc Sort ÈÄ \t: ");
    ArrayPrn();
    qsort(ss, 5, sizeof(ss[0]), AscData);
    DataPrn();
    qsort(ss, 5, sizeof(ss[0]), AscData2);
    DataPrn();
    return 0;
}
