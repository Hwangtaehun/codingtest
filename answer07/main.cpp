#include <algorithm>
#include <cstdio>
#include <vector>

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

bool Compare(const pair<int, int> &i, const pair<int, int> &j){
    if(i.first == j.first){
        return i.second < j.second;
    }

    return i.first < j.first;
}

void Solve(){
    vector< pair <int, int> > m_route;
    int x = 0, y = 0;

    for(int i = 0; i < g_data.size(); i++){
        pair<int, int> m_move = Trans(g_data[i]);
        if(Check(x + m_move.first, y + m_move.second)){
            x += m_move.first;
            y += m_move.second;
            m_route.push_back({x, y});
        }
    }


    sort(m_route.begin(), m_route.end(), Compare);
    m_route.erase(unique(m_route.begin(), m_route.end()), m_route.end());

    g_result = m_route.size();
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
