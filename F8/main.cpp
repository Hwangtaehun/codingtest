#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int g_size;
string g_binary;
vector<char> g_code;
vector<string> g_data;
vector<char> g_result;

//solve
#include <map>
char str, strvalue[30], data[300], tree[1500000];
int k;
map<string, char> mp;

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d", &g_size);
    k = g_size;
    for(int i = 0; i < g_size; i++){
        int idx = 1;
        string m_temp;
        cin >> str >> strvalue;
        m_temp.assign(strvalue);
        g_code.push_back(str);
        g_data.push_back(m_temp);

        mp[m_temp] = str;

        for(int j = 0; strvalue[j] != '\0'; j++){
            if(strvalue[j] == '0'){
                idx = idx * 2;
            }else{
                idx = idx * 2 + 1;
            }
        }
        tree[idx] = str;
    }

    scanf("%s", data);
    g_binary.assign(data);

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_result.size(); i++){
        cout << g_result[i];
    }
    fclose(stdout);
}

void Print(vector<char> data){
    for(int i = 0; i < data.size(); i++){
        printf("%c", data[i]);
    }
    printf("\n");
}

void Whole_Print(){
    cout << g_binary << endl;
    for(int i = 0; i < g_data.size(); i++){
        cout << g_code[i] << ' ' << g_data[i] << endl;
    }
}

void mySolve(int index, bool zero, vector<char> data){
    string m_rs;
    int m_leng;

    if(g_size == 3){
        m_leng = 2;
    }else{
        m_leng = g_size - 2;
    }

    if(g_binary.length() == index){
        return;
    }

    data.push_back(g_binary[index]);

    if(g_binary[index] == '0'){
        zero = true;
    }

    if(zero && data.size() >= 2){
        m_rs.assign(data.begin(), data.end());
    }else if(data.size() == m_leng){
        m_rs.assign(data.begin(), data.end());
    }

    if(!m_rs.empty()){
        data.clear();
        zero = false;
        for(int i = 0; i < g_size; i++){
            if(!m_rs.compare(g_data[i])){
                g_result.push_back(g_code[i]);
            }
        }
    }

    mySolve(index + 1, zero, data);
}

void Solve1(){
    int idx = 1;
    for(int i = 0; data[i] != '\0'; i++){
        if(data[i] == '0')
            idx = 2 * idx;
        else
            idx = 2 * idx + 1;

        if(tree[idx] != 0){
            printf("%c", tree[idx]);
            idx = 1;
        }
    }
    printf("\n");
}

void Solve2(){
    string a, m_str = g_binary;
    for(int i = 0; i < m_str.length(); i++){
        a += m_str[i];
        if(mp[a]){
            cout << mp[a];
            a.clear();
        }
    }
}

int main()
{
    vector<char> m_data;
    Input();
    Solve1();
    Solve2();
    mySolve(0, false, m_data);
    Output();
    return 0;
}
