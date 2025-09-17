#include <cstdio>
#include <string.h>
#include <vector>
#define SIZE 2

using namespace std;

int g_cnt = 0;
vector<char> g_words;
vector<vector <char> > g_brige;

//solve
char rol[30], dol[2][120];
int DT1[2][120][30], DT2[2][30], rc;

void Input(){
    g_brige.resize(SIZE);

    freopen("input.txt", "r", stdin);

    scanf("%s %s %s", rol, dol[0], dol[1]);

    for(int i = 0; rol[i] != '\0'; i++){
        g_words.push_back(rol[i]);
    }

    for(int i = 0; dol[0][i] != '\0'; i++){
        g_brige[0].push_back(dol[0][i]);
    }

    for(int i = 0; dol[1][i] != '\0'; i++){
        g_brige[1].push_back(dol[1][i]);
    }

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt);
    fclose(stdout);
}

//-1: 0, 1: 1
int Index(int sw){
    return sw < 0 ? 0 : 1;
}

void mySolve(int b_num, int w_num, int sw){
    int m_index = Index(sw);
    if(w_num == g_words.size()){
        g_cnt++;
    }

    if(g_brige[0].size() == b_num){
        return;
    }

    if(g_brige[m_index][b_num] == g_words[w_num]){
        w_num += 1;
        sw = -sw;
    }

    mySolve(b_num + 1, w_num, sw);
}

int f1(int dolnum, int dolpos, int rolpos){
    if(DT1[dolnum][dolpos][rolpos] == 0){
        if(rol[rolpos] == '\0'){
            DT1[dolnum][dolpos][rolpos] = 1;
        }

        for(int i = dolpos; dol[1 - dolnum][i] != '\0'; i++){
            if(dol[1 - dolnum][i] == rol[rolpos]){
                DT1[dolnum][dolpos][rolpos] += f1(1 - dolnum, i + 1, rolpos + 1);
            }
        }
    }

    return DT1[dolnum][dolpos][rolpos];
}

int f2(int k){
    for(int i = 0; dol[1][i]; i++){
        for(int t = k - 1; t >= 0; t--){
            if(dol[0][i] == rol[t])
                DT2[1][t + 1] += DT2[0][t];
            if(dol[1][i] == rol[t])
                DT2[0][t + 1] += DT2[1][t];
        }
    }
    return DT2[0][k] + DT2[1][k];
}

int main()
{
    Input();

    rc = strlen(rol);
    DT2[0][0] = DT2[1][0] = 1;

    printf("%d\n", f1(0, 0, 0) + f1(1, 0, 0));
    printf("%d\n", f2(rc));

    for(int i = 0; i < g_brige[0].size(); i++){
        mySolve(i, 0, -1);
        mySolve(i, 0, 1);
    }

    Output();
    return 0;
}
