#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int k;
vector<string> id_list, report;
vector<int> answer;

void Input(){
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    scanf("%d", &k);

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
                    id_list.push_back(token);
                } else {
                    report.push_back(token);
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

vector< pair <string, string> > Sort_report(const vector<string> report){
    set<string> ndr;
    vector< pair <string, string> > res_ret;

    for(int i = 0; i < report.size(); i++){
        ndr.insert(report[i]);
    }

    for(auto str : ndr){
        stringstream ss(str);
        string id, report_id;

        ss >> id >> report_id;
        res_ret.push_back({id, report_id});
    }

    return res_ret;
}

vector<string> Stop_id(vector< pair <string, string> > m_report, int k){
    unordered_map<string, int> m_id;
    vector<string> res;

    for(int i = 0; i < m_report.size(); i++){
        m_id[m_report[i].second]++;
    }

    for(auto value : m_id){
        if(value.second >= k){
            res.push_back(value.first);
        }
    }

    return res;
}

void Solve(){
    vector< pair <string, string> > m_report = Sort_report(report);
    vector<string> m_stop_id = Stop_id(m_report, k);
    unordered_map<string, int> mail_count;

    sort(m_report.begin(), m_report.end());
    answer.resize(id_list.size());

    for(int i = 0; i < m_report.size(); i++){
        for(int j = 0; j < m_stop_id.size(); j++){
            if(m_stop_id[j] == m_report[i].second){
                mail_count[m_report[i].first]++;
            }
        }
    }

    for(int i = 0; i < id_list.size(); i++){
        for(auto a: mail_count){
            if(id_list[i] == a.first){
                answer[i] = a.second;
            }
        }
    }
}

vector<int> solution(){
    vector<int> Answer;
    unordered_map<string, unordered_set<string> > reported_user;
    unordered_map<string, int> count;

    for(string &r: report) {
        stringstream ss(r);
        string user_id, reported_id;
        ss >> user_id >> reported_id;
        reported_user[reported_id].insert(user_id);
    }

    for(auto &[reported_id, user_id_lst]: reported_user) {
        if(user_id_lst.size() >= k){
            for(const string &uid : user_id_lst) {
                count[uid]++;
            }
        }
    }

    for(string &id : id_list){
        Answer.push_back(count[id]);
    }

    return Answer;
}

int main()
{
    Input();
    Solve();
    for(auto m : solution()){
        printf("%d ", m);
    }
    Output();
    return 0;
}
