#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int *data, size, ser;

int binary1(int low, int high){
    int mid;

    while(low <= high){
            mid = (low + high) / 2;

            if(data[mid] == ser)
                return mid + 1;
            else if(data[mid] > ser)
                high = mid - 1;
            else if(data[mid] < ser)
                low = mid + 1;
    }
    return -1;
}

int binary2(int low, int high){
    int mid = (low + high) / 2;

    if(low > high)
        return -1;

    if(data[mid] == ser)
        return mid +1;
    else if(data[mid] > ser)
        binary2(low, mid - 1);
    else if(data[mid] < ser)
        binary2(mid + 1, high);
}

int main()
{
    int find1, find2;

    FILE *inf = fopen("input.txt", "r");
    FILE *outf = fopen("output.txt", "w");

    fscanf(inf, "%d", &size);
    data = (int *)malloc(sizeof(int)*size);
    for(int i = 0; i < size; i++){
        fscanf(inf, "%d", &data[i]);
    }
    fscanf(inf, "%d", &ser);

    find1 = binary1(0, size -1);
    find2 = binary2(0, size - 1);

    fprintf(outf, "\n%d\n", find2);

    free(data);
    return 0;
}
