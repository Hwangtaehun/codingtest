#include <cstdio>
#include <vector>

using namespace std;

int g_size;
vector<int> g_data;
vector<char> g_result;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    for(int i = 0; i < g_size; i++){
        int temp;
        scanf("%d", &temp);
        g_data.push_back(temp);
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stout);
    for(int i = 0; i < g_result.size(); i++){
        printf("%c", g_result[i]);
    }
    fclose(stdout);
}

int main()
{
    return 0;
}
