#include <algorithm>
#include <cstdio>
#include <vector>
#include <tuple>
#include <set>

using namespace std;

vector<char> g_data;
int g_result = 0;

void Input(){
    char m_str[500];
    freopen("input.txt", "r", stdin);
    scanf("%s", m_str);
    fclose(stdin);

    for(int i = 0; m_str[i] != '\0'; i++){
        g_data.push_back(m_str[i]);
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_result);
    fclose(stdout);
}

pair<int, int> Trans(char c){
    pair<int, int> m_pair = {0, 0};

    switch(c){
    case 'U':
        m_pair.first += 1;
        break;
    case 'D':
        m_pair.first -= 1;
        break;
    case 'R':
        m_pair.second += 1;
        break;
    case 'L':
        m_pair.second -= 1;
        break;
    }

    return m_pair;
}

bool Check(int x, int y){
    if((x >= -5 && x <= 5) && (y >= -5 && y <= 5)){
        return true;
    }

    return false;
}

void Solve(){
    set<tuple <int, int, int, int> > m_route;
    int x = 0, y = 0;

    for(int i = 0; i < g_data.size(); i++){
        pair<int, int> m_move = Trans(g_data[i]);
        if(Check(x + m_move.first, y + m_move.second)){
            pair<int, int> s_pos = {x, y};
            pair<int, int> g_pos = {x + m_move.first, y + m_move.second};

            if (current_pos > next_pos) {
                swap(current_pos, next_pos);
            }

            m_route.insert({s_pos.first, s_pos.second, g_pos.first, g_pos.second});

            x += m_move.first;
            y += m_move.second;
        }
    }

    g_result = m_route.size();
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
