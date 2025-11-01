#include <cstdio>
#include <vector>

using namespace std;

struct Tri{
    int a;
    int b;
    int c;
};

vector <Tri> g_data;
int g_num;

//solve
int n;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_num);
    n = g_num;
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_data.size());
    fclose(stdout);
}

bool mup_check(int a, int b, int c){
    for(int i = 0; i < g_data.size(); i++){
        if((g_data[i].a == a && g_data[i].b == b) && g_data[i].c == c){
            return false;
        }
    }
    return true;
}

void mySolve(){
    for(int a = 1; a <= g_num/3; a++){
        int rest = g_num - a;
        for(int b = a; b <= rest/2; b++){
            int c = rest - b;
            if(c < a + b && mup_check(a, b, c)){
                g_data.push_back((Tri){a, b, c});
            }
        }
    }
}

int Solve2(){
    int c, cnt = 0;
    for(int a = 1; a <= n; a++){
        for(int b = a; b <= n; b++){
            c = n - (a + b);
            if(c < a + b && (b <= c)){
                printf("%d %d %d\n", a, b, c);
                cnt++;
            }
        }
    }
    return cnt;
}

int Solve3(){
    int a, b, c, cnt = 0;
    for(c = n/3; c <= n/2; c++){
        for(a = 1; a <= n/3; a++){
            b = n - (a + c);

            if(c < a + b && (a <= b && b <= c)){
                printf("%d %d %d\n", a, b, c);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    Input();
    printf("%d\n", Solve2());
    printf("%d\n", Solve3());
    mySolve();
    Output();
    return 0;
}
