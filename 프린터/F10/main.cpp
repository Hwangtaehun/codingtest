#include <cstdio>
#include <vector>

using namespace std;

int g_size, g_max = 0;
vector<int> g_data;

//solve
#define INF 987654321

int S[100000], DT[100000], n, ans1 = -INF, ans2 = -INF;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    for(int i = 0; i < g_size; i++){
        scanf("%d", &S[i]);
        g_data.push_back(S[i]);
    }
    fclose(stdin);

    n = g_size;
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_max);
    fclose(stdout);
}

void mySolve(){
    for(int i = 0; i < g_size; i++){ //index
        for(int j = g_size - i; j > 0; j--){ //count
            int m_sum = 0;
            for(int k = i; k < j + i; k++){
                m_sum += g_data[k];
            }

            if(g_max < m_sum){
                g_max = m_sum;
            }
        }
    }
}

void Print(){
    for(int i = 0; i < g_size; i++){
        printf("%d ", g_data[i]);
    }
    printf("\n");
}

int Max(int a, int b){
    return a > b ? a : b;
}

int f1(int k){
    if(k == 0)
        return S[0];
    else
        return Max(f1(k - 1) + S[k], S[k]);
}

int f2(int k){
    if(k == 0){
        return DT[k] = S[0];
    }
    else if(!DT[k]){
        DT[k] = Max(f2(k - 1) + S[k], S[k]);
    }

    return DT[k];
}

int main()
{
    Input();

    for(int i = 0; i < n; i++){
        ans1 = Max(ans1, f1(i));
    }

    for(int i = 0; i < n; i++){
        ans2 = Max(ans2, f2(i));
    }

    printf("%d\n%d", ans1, ans2);
    mySolve();
    Output();
    return 0;
}
