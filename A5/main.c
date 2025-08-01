#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int *data, size, focus;

int main()
{
    int find;
    FILE *inf = fopen("input.txt", "r");
    FILE *outf = fopen("output.txt", "w");

    fscanf(inf, "%d", &size);

    data = (int *)malloc(sizeof(int)*size);

    for(int i = 0;  i < size; i++){
        fscanf(inf, "%d", &data[i]);
    }

    fscanf(inf, "%d", &focus);

    for(int i = size - 1; i >= 0; i--){
        if(data[i] == focus){
            find = i + 2;
            break;
        }
    }

    fprintf(outf, "\n%d\n", find);

    free(data);

    return 0;
}
