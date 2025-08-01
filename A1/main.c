#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int *data, size;

void file_read(){
    FILE *inf = fopen("input.txt", "r");

    int temp;

    for(int i = 0; i < 100; i++){
        if(fscanf(inf, "%d", &temp) != 1){
            size = i;
            break;
        }
    }

    data = (int *)malloc(sizeof(int)*size);

    rewind(inf);

    for(int  i = 0; i < size; i++){
        fscanf(inf, "%d", &data[i]);
    }
}

void file_write(int num, int loc){
    FILE *outf = fopen("output.txt", "w");
    fprintf(outf, "%d\n%d", num, loc);
}

int main()
{
    int big = 0;
    int loc = 0;
    file_read();
    big = data[0];

    for(int i = 1; i < size; i++){
        if(big < data[i]){
            big = data[i];
            loc = i + 1;
        }
    }

    file_write(big, loc);

    free(data);
    return 0;
}
