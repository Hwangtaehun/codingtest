#include <iostream>
#include <fstream>
#include <vector>
#define SIZE 2

using namespace std;

int g_cnt = 0;
vector<char> g_words;
vector<vector <char> > g_brige;

void Input(){
    g_brige.resize(SIZE);

    ifstream inFile("input.txt");

    if (!inFile.is_open()) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return;
    }

    string m_data;

    getline(inFile, m_data);

    for(int i = 0; i < m_data.size(); i++){
        g_words.push_back(m_data[i]);
    }

    int index = 0;

    while(getline(inFile, m_data)){

        for(int i = 0; i < m_data.size(); i++){
            g_brige[index].push_back(m_data[i]);
        }

        index++;
    }

    inFile.close();
}

void Output(){
    ofstream outFile("output.txt");

    if (!outFile.is_open()) {
        cerr << "파일을 열 수 없습니다." << endl;
        return;
    }

    outFile << g_cnt;

    outFile.close();
}

void Print(){
    for(int i = 0; i < g_words.size(); i++){
        cout << g_words[i];
    }
    cout << endl;

    for(int i = 0; i < g_brige.size(); i++){
        for(int j = 0; j < g_brige[i].size(); j++){
            cout << g_brige[i][j];
        }
        cout << endl;
    }
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

int main()
{
    Input();
    for(int i = 0; i < g_brige[0].size(); i++){
        mySolve(i, 0, -1);
        mySolve(i, 0, 1);
    }
    Output();
    return 0;
}
