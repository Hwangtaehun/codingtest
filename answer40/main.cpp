#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

struct ROWCOL{
    int x;
    int y;
};

vector<string> maps;
vector< vector<bool> > visited;
ROWCOL dir[4]= {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char token[2] = {'L', 'E'};
int answer = 0xFFFFFFF, ti = 0;

void Input(){
    string s;

    freopen("input.txt", "r", stdin);
    getline(cin, s);
    fclose(stdin);

    s.erase(remove(s.begin(), s.end(), '['), s.end());
    s.erase(remove(s.begin(), s.end(), ']'), s.end());
    s.erase(remove(s.begin(), s.end(), '\"'), s.end());

    stringstream ss(s);

    while(getline(ss, s, ',')){
        s.erase(0, s.find_first_not_of(" \t\n\r"));
        s.erase(s.find_last_not_of(" \t\n\r") + 1);

        if(!s.empty()){
            maps.push_back(s);
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << answer;
    fclose(stdout);
}

template <typename T>
void vector_Print(T v){
    for(auto a : v){
        cout << a << endl;
    }
}

bool Check(int x, int y){
    int w = maps[0].length(), h = maps.size();
    //printf("w = %d, h = %d\n", w, h);
    return (0 <= x && x < w) && (0 <= y && y < h);
}

int Solve(int x, int y, int cnt){
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int res;
        int m_x = x + dir[i].x, m_y = y + dir[i].y;

        if(Check(m_x, m_y)){
            if(maps[m_x][m_y] == 'O' && !visited[m_x][m_y]){
                res = Solve(m_x, m_y, cnt + 1);
                if(res != -1){
                    return res;
                }
            } else if(maps[m_x][m_y] == token[ti] && !visited[m_x][m_y]){
                if(ti == 0){
                    ti++;
                    res = Solve(m_x, m_y, cnt + 1);
                    if(res != -1){
                        return res;
                    }
                }else{
                    return cnt + 1;
                }
            }
        }
    }

    visited[x][y] = false;

    return -1;
}

int main()
{
    int m_result;
    ROWCOL m_start;

    Input();

    visited.resize(maps.size());
    for(int i = 0; i < maps.size(); i++){
        visited[i].assign(maps[i].length(), false);
    }

    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].length(); j++){
            if(maps[i][j] == 'X'){
                visited[i][j] = true;
            }
            else if(maps[i][j] == 'S'){
                m_start.x = i;
                m_start.y = j;
            }
        }
    }

    m_result = Solve(m_start.x, m_start.y, 0);

    if(m_result < answer){
        answer = m_result;
    }

    printf("%d\n", answer);

    return 0;
}
