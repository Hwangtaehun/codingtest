#include <cstdio>

using namespace std;

int mySolve(int i){
    if(i == 0){
        return 0;
    }
    return i + mySolve(i - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", mySolve(n));
    return 0;
}
