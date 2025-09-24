#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> first = {1, 2, 3, 4, 5};
vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> thrid = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
vector<int> g_answer, g_result;

void Input(){
    freopen("input.txt", "r", stdin);
    int x;
    while (scanf("%d", &x) != EOF) {
        g_answer.push_back(x);
    }
    fclose(stdin);
}

void Output(){
    sort(g_result.begin(), g_result.end());
    freopen("output.txt", "w", stdout);
    printf("[");
    for(int i = 0; i < g_result.size(); i++){
        printf("%d", g_result[i]);
        if(g_result.size() - 1 != i){
            printf(", ");
        }
    }
    printf("]");
    fclose(stdout);
}

void Same(int a, int b, int c){
    if((a == b) && (b == c)){
        g_result.push_back(1);
        g_result.push_back(2);
        g_result.push_back(3);
    }else{
        if(a == b){
            g_result.push_back(1);
            g_result.push_back(2);
        }

        if(a == c){
            g_result.push_back(1);
            g_result.push_back(3);
        }

        if(b == c){
            g_result.push_back(2);
            g_result.push_back(3);
        }
    }
}

void Solve(){
    int f_cnt = 0, s_cnt = 0, t_cnt = 0;

    for(int i = 0; i < g_answer.size(); i++){
        if(g_answer[i] == first[i]){
            f_cnt++;
        }

        if(g_answer[i] == second[i]){
            s_cnt++;
        }

        if(g_answer[i] == thrid[i]){
            t_cnt++;
        }
    }

    if((f_cnt > s_cnt) && (f_cnt > t_cnt)){
        g_result.push_back(1);
    }else if((s_cnt > f_cnt) && (s_cnt > t_cnt)){
        g_result.push_back(2);
    }else if((t_cnt > f_cnt) && (t_cnt > s_cnt)){
        g_result.push_back(3);
    }else{
        Same(f_cnt, s_cnt, t_cnt);
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
