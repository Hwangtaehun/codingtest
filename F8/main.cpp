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

void Input(){
    freopen("input.txt", "r", stdin);
    cin >> g_size;
    for(int i = 0; i < g_size; i++){
        char m_char;
        string m_temp;
        cin >> m_char >> m_temp;
        g_code.push_back(m_char);
        g_data.push_back(m_temp);
    }
    cin >> g_binary;
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

int main()
{
    vector<char> m_data;
    Input();
    mySolve(0, false, m_data);
    Output();
    return 0;
}
