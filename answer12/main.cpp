#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

vector<int> prices;
vector<int> answer;

void Input(){
    string m_data;
    freopen("input.txt", "r", stdin);
    getline(cin, m_data);
    fclose(stdin);

    for(char c: m_data){
        if(c != ' ' && c != ','){
            int n = c - '0';
            prices.push_back(n);
        }
    }

    answer.resize(prices.size());
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("[");
    for(int i = 0; i < answer.size(); i++){
        printf("%d", answer[i]);
        if(i != answer.size() - 1){
            printf(", ");
        }
    }
    printf("]");
    fclose(stdout);
}

void Print(stack<int> m_index){
    stack<int> temp = m_index;

    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

void Solve(){
    stack<int> m_index, m_price;

    for(int i = 0; i < prices.size(); i++){
        int m_time = 0;

        if(!m_price.empty()){
            while(m_price.top() > prices[i]){
                m_time = i - m_index.top();
                m_index.pop();
                m_price.pop();
            }
        }

        if(m_time != 0){
            answer[i - 1] = m_time;
        }

        m_index.push(i);
        m_price.push(prices[i]);
    }

    while(!m_index.empty()){
        int m_num = m_index.top();
        answer[m_num] = prices.size() - m_num - 1;
        m_index.pop();
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
