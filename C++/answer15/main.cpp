#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n, k, result;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &k);
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", result);
    fclose(stdout);
}

void Solve(){
    queue<int> q, temp;

    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while(q.size() > 1){
        for(int i = 1; i < k; i++){
            int num = q.front();
            temp.push(num);
            q.pop();
            printf("%d\n", num);
        }
        printf("\n");

        q.pop();

        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
    }
    result = q.front();
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
