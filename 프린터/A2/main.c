#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char* data;
int size;

int main()
{
    FILE *inf = fopen("input.txt", "r");
    FILE *outf = fopen("output.txt", "w");
    fscanf(inf, "%d", &size);

    data = (char*)malloc(sizeof(char)*size);

    for(int i = 0; i < size; i++){
        if((i+1)%3 == 0){
            data[i] = 'X';
        }
        else{
            data[i] = (char)(i+49);
        }
    }

    for(int i = 0; i < size; i++){
        fprintf(outf, "%c ", data[i]);
    }

    free(data);
    return 0;
}
