#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g_data, g_result;
int g_size, g_dis = 0x7FFFFFFF, g_fir = 0x7FFFFFFF;

//solve
int gift[20], g1, g2, g3, n, d = 0x0fffffff, gd = 0x0fffffff, sum, debugCnt;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    n = g_size;

    for(int i = 0; i < g_size; i++){
        scanf("%d", &gift[i]);
        g_data.push_back(gift[i]);
        sum += gift[i];
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);

    for(int i = 0; i < g_result.size(); i++){
        printf("%d ", g_result[i]);
    }

    fclose(stdout);
}

void Compare(int *a, int *b){
    if(*a < *b){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

void Add(int a, int b, int c){
    g_result.clear();
    g_result.push_back(a);
    g_result.push_back(b);
    g_result.push_back(c);
}

void mySolve(int a, int b, int c, int cnt){
    if(cnt == g_size){
        Compare(&b, &c);
        Compare(&a, &b);
        Compare(&b, &c);
        int m_dis = a - c;
        int m_fir = a;
        //printf("m_dis = %d, m_fir = %d\n", m_dis, m_fir);

        if(m_dis <= g_dis && m_fir <= g_fir){
            g_dis = m_dis;
            g_fir = m_fir;
            Add(a, b, c);
        }

        return;
    }

    mySolve(a + g_data[cnt], b, c, cnt + 1);
    mySolve(a, b + g_data[cnt], c, cnt + 1);
    mySolve(a, b, c + g_data[cnt], cnt + 1);
}

void ArrayPrn(){
    for(int i = 0; i < n; i++){
        printf("%d ", gift[i]);
    }

    printf("sum = %d\n", sum);
}

bool Desc(int left, int right){
    return left > right;
}

void Solve(int no, int a, int b, int c){
    if(c > sum / 3 || b > sum / 2)
        return;

    int restSum = sum - (a + b + c);
    if((restSum + a) < b || (restSum + b) < c)
        return;

    if(a - (c + restSum) > d)
        return;
    debugCnt++;

    if(no < n){
        Solve(no + 1, a, b, c + gift[no]);
        Solve(no + 1, a, b + gift[no], c);
        Solve(no + 1, a + gift[no], b, c);
    }
    else if(a >= b && b >= c && d >= (a-c) && gd > a){
        g1 = a, g2 = b, g3 = c;
        d = a - c;
        gd = a;
        printf("%d %d %d %d\n", g1, g2, g3, d);
    }
}

int main()
{
    Input();

    sort(gift, gift + n, Desc);
    ArrayPrn();
    Solve(0, 0, 0, 0);
    printf("%d %d %d\n", g1, g2, g3);
    printf("debugCnt = %d\n", debugCnt);

    mySolve(0, 0, 0, 0);
    Output();
    return 0;
}
