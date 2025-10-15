#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

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
    string result = "";

    for(int i = 0; i < combinat.size(); i++){
        for(int j = i + 1; j < combinat.size(); j++){
            vector<string> order1 = string_to_vector(combinat[i]);
            vector<string> order2 = string_to_vector(combinat[j]);

            for(int m = 0; m < order1.size(); m++){
                for(int n = 0; n < order2.size(); n++){
                    if(order1[m] == order2[n]){
                        string str = order1[m] + ",";
                        result += str;
                    }
                }
            }

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
                v_com.push_back(orders[j]);
            }
        }
        m_answer += possible(v_com);
    }


    cout << m_answer << endl;
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
