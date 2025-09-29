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
    stack<int> s_index;
    int priceNum = prices.size();

    for(int i = 0; i < priceNum; i++){
        while(!s_index.empty() && prices[s_index.top()] > prices[i]){
            answer[s_index.top()] = i - s_index.top();
            s_index.pop();
        }

        s_index.push(i);
    }

    while(!s_index.empty()) {
        answer[s_index.top()] = priceNum - s_index.top() - 1;
        s_index.pop();
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
