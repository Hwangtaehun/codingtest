#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#define SIZE 2

using namespace std;

vector<string> genres;
vector<int> plays, answer;

void Input(){
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    while(getline(cin, line)){
        if(!line.empty()) {
            lines.push_back(line);
        }
    }

    fclose(stdin);

    for(int i = 0; i < lines.size(); i++){
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), '['), lines[i].end());
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), ']'), lines[i].end());
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), '\"'), lines[i].end());

        stringstream ss(lines[i]);
        string token;

        while(getline(ss, token, ',')) {
            token.erase(0, token.find_first_not_of(" \t\n\r"));
            token.erase(token.find_last_not_of(" \t\n\r") + 1);

            if(!token.empty()){
                if(i == 0){
                    genres.push_back(token);
                }else{
                    int n = stoi(token);
                    plays.push_back(n);
                }
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < answer.size(); i++){
        printf("%d ", answer[i]);
    }
    fclose(stdout);
}

bool Compare_pair(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

bool Compare_second(const pair<string, int>  &a, const pair<string, int> &b) {
    return a.second > b.second;
}

vector< pair<string, int> > Genres_sort(vector<string> genres, vector<int> plays){
    unordered_map<string, int> m_gen;
    vector< pair<string, int> > v_gen;

    for(int i = 0; i < genres.size(); i++){
        m_gen[genres[i]] += plays[i];
    }

    for(auto a: m_gen){
        v_gen.push_back({a.first, a.second});
    }

    sort(v_gen.begin(), v_gen.end(), Compare_second);

    return v_gen;
}

void Solve(){
    vector< pair<int, int> > sort_plays;
    vector< pair<string, int> >gen_cnt = Genres_sort(genres, plays);

    for(int i = 0; i < plays.size(); i++){
        sort_plays.push_back({i, plays[i]});
    }

    sort(sort_plays.begin(), sort_plays.end(), Compare_pair);

    for(int i = 0; i < gen_cnt.size(); i++){
        string geners_name = gen_cnt[i].first;
        int cnt = 0;

        for(int j = 0; j < sort_plays.size(); j++){
            if(geners_name == genres[sort_plays[j].first]){
                answer.push_back(sort_plays[j].first);
                cnt++;
            }

            if(cnt == 2){
                break;
            }
        }
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
