#include <cstdio>
#include <vector>

using namespace std;

int g_size;
vector<int> g_data;
vector<char> g_result;

//solve
char str[1<<19];
int n;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    n = g_size;

    for(int i = 0; i < g_size; i++){
        int temp;
        scanf("%1d", &temp);
        g_data.push_back(temp);
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_result.size(); i++){
        printf("%c", g_result[i]);
    }
    fclose(stdout);
}

void Print(){
    for(int i = 0; i < g_size; i++){
        printf("%d", g_data[i]);
    }
}

bool Check(int x, int range){
    for(int i = x + 1; i < x + range; i++){
        if(g_data[i] != g_data[x]){
            return false;
        }
    }
    return true;
}

void mySolve(int x, int range){
    if(range ==  1){
        g_result.push_back(g_data[x] + '0');
        return;
    }

    if(Check(x, range)){
        g_result.push_back(g_data[x] + '0');
        return;
    }else{
        g_result.push_back('-');
        mySolve(x, range / 2);
        mySolve(x + range / 2 , range / 2);
    }
}

void Solve(int k, int s){
    int sum = 0;

    if(s == 1){
        printf("%c", str[k]);
        return;
    }

    for(int i = k; i < k + s; i++)
        sum += (str[i] - '0');
    if(sum == 0 || sum == s)
        printf("%d", (bool)sum);
    else{
        printf("-");
        Solve(k, s/2);
        Solve(k + s/2, s/2);
    }
}

int main()
{
    scanf("%s", str);
    Input();
    //Print();
    Solve(0, n);
    mySolve(0, g_size);
    Output();
    return 0;
}
