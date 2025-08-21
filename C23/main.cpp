#include <cstdio>
#include <algorithm>

using namespace std;

//0:nothing, 1:car1, 2:car2
int **g_data, g_size, g_case, g_distance;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_case);

    g_data = new int*[g_size + 1];
    for(int i = 0; i <= g_size; i++){
        g_data[i] = new int[g_size + 1];
    }

    for(int i = 0; i < g_case; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g_data[a][b] = 1;
    }

    fclose(stdin);
}

void Output(){
    //freopen("output.txt", "w", stdout);
    printf("%d", g_distance);
    //fclose(stdout);

    for(int i = 0; i <= g_size; i++){
        delete[] g_data[i];
    }
    delete[] g_data;
}

int main()
{
    Input();
    return 0;
}
