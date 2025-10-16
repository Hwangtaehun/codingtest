#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

vector<string> orders, answer;
vector<int> course;

void Input(){
    vector<string> lines;
    string line;

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

            if(!token.empty()) {
                if(i == 0){
                    orders.push_back(token);
                }else{
                    course.push_back(stoi(token));
                }
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);

    cout << "[";
    for(int i = 0; i < answer.size(); i++){
        if(i > 0){
            cout << ",";
        }
        cout << answer[i];
    }
    cout << "]";

    fclose(stdout);
}

void Combination_string(const string src, string cur, string &dst, int depth){
    if(cur.size() == depth){
        sort(cur.begin(), cur.end());
        dst +=  cur + ",";
        return;
    }
    else{
        for(int i = 0; i < src.size(); i++){
            Combination_string(src.substr(i + 1), cur + src[i], dst, depth);
        }
    }
}

vector<string> string_to_vector(string str){
    string m_str = "";
    stringstream ss(str);
    vector<string> v_com;

    while(getline(ss, m_str, ',')){
        m_str.erase(0, m_str.find_first_not_of(" \t\n\r"));
        m_str.erase(m_str.find_last_not_of(" \t\n\r") + 1);

        if(!m_str.empty()){
            v_com.push_back(m_str);
        }
    }

    return v_com;
}

string possible(vector<string> combinat){
    map<string, int> m_map;
    string result = "";
    int m_max = 2;

    for(int i = 0; i < combinat.size(); i++){
        for(int j = i + 1; j < combinat.size(); j++){
            vector<string> order1 = string_to_vector(combinat[i]);
            vector<string> order2 = string_to_vector(combinat[j]);

            for(int m = 0; m < order1.size(); m++){
                for(int n = 0; n < order2.size(); n++){
                    if(order1[m] == order2[n]){
                        m_map[order1[m]]++;
                        string str = order1[m] + ",";
                        result += str;
                    }
                }
            }
        }
    }

    for(auto a: m_map){
        if(m_max < a.second){
            m_max = a.second;
            result = a.first + ",";
        }else if(m_max == a.second){
            result += a.first + ",";
        }
    }

    return result;
}

void Solve(){
    string m_answer;

    for(int i = 0; i < course.size(); i++){
        vector<string> v_com;
        for(int j = 0; j < orders.size(); j++){
            string m_result = "";
            if(orders[j].length() > course[i]){
                Combination_string(orders[j], "", m_result, course[i]);
                v_com.push_back(m_result);
            }else if(orders[j].length() == course[i]){
                m_result = orders[j];
                sort(m_result.begin(), m_result.end());
                v_com.push_back(m_result);
            }
        }
        m_answer += possible(v_com);
    }

    answer = string_to_vector(m_answer);
    sort(answer.begin(), answer.end());
}

//solve
map<string, int> combi;

void combination(string src, string dst, int depth){
    if(dst.size() == depth){
        combi[dst]++;
    }else{
        for(int i = 0; i < src.size(); i++){
            combination(src.substr(i + 1), dst + src[i], depth);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course){
    vector<string> m_answer;

    for (string &order : orders) {
        sort(order.begin(), order.end());
    }

    for (int len : course) {
        for(string order : orders) {
            combination(order, "", len);

        }

        int maxOrder = 0;

        for (auto it : combi) {
            maxOrder = max(maxOrder, it.second);
        }

        for (auto it : combi) {
            if (maxOrder >= 2 && it.second == maxOrder) {
                m_answer.push_back(it.first);
            }
        }

        combi.clear();
    }

    sort(m_answer.begin(), m_answer.end());
    return m_answer;
}

int main()
{
    Input();
    Solve();
    for(auto vstr : solution(orders, course)){
        cout << vstr << " ";
    }
    Output();
    return 0;
}
