#include <cstdio>
#include <vector>
#define SIZE 3

using namespace std;
int g_dis, g_min = 0x0fffffff;
vector<int> g_able;

//solve
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int a, b, able[SIZE], ans = 2000, d[1001];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &a, &b);
    for(int i = 0; i < SIZE; i++){
        scanf("%d", &able[i]);
        g_able.push_back(able[i]);
    }
    fclose(stdin);

    g_dis = b - a;
}

void Output(){
    if(g_min == 0x0fffffff){
        g_min = -1;
    }

    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

void mySolve(int sum, int cnt){
    if(sum >= g_dis){
        if(cnt < g_min && sum == g_dis){
            g_min = cnt;
        }
        return;
    }

    for(int i = 0; i < SIZE; i++){
        mySolve(sum + g_able[i], cnt + 1);
    }
}

void Solve(){
    if(a == b)
        printf("0");
    else{
        for(int i = a; i <= b; i++){
            d[i] = 123456789;
        }

        d[a] = 0;

        for(int i = a + 1; i <= b; i++){
            int temp = 123456789;
            for(int k = 0; k < 3; k++){
                if(i - able[k] >= a){
                    temp = MIN(temp, d[i - able[k]] + 1);
                }
                d[i] = temp;
            }
        }

        if(d[b] != 123456789){
            printf("%d", d[b]);
        }else{
            printf("-1");
        }
    }
}

void Back(int next, int cnt){
    if(next > b)
        return;

    if(b == next){
        if(cnt < ans)
            ans = cnt;
    }

    for(int i = 0; i < SIZE; i++){
        Back(next + able[i], cnt + 1);
    }
}

int main()
{
    Input();
    Back(a, 0);
    if(ans != 2000){
        printf("%d\n", ans);
    }
    else{
        printf("-1\n");
    }
    Solve();
    mySolve(0, 0);
    Output();
    return 0;
}
