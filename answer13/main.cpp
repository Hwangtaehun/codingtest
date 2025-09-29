#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> board;
vector<int> moves;
int answer = 0;

vector<vector<int>> readMatrix() {
    vector<vector<int>> result;
    vector<int> row;
    int num;
    char ch;

    while (true) {
        if (scanf("%c", &ch) != 1) break; // EOF

        if (ch == '[') {
            row.clear();
        } else if (ch == ']') {
            if (!row.empty()) {
                result.push_back(row);
                row.clear();
            }
        } else if (ch == ',' || ch == ' ') {
            continue;
        } else if (ch == '\n') {
            break;
        } else if (ch >= '0' && ch <= '9') {
            ungetc(ch, stdin);
            scanf("%d", &num);
            row.push_back(num);
        }
    }
    return result;
}

vector<int> readMat(){
    vector<int> row;
    int num;
    char ch;

    while (true) {
        if (scanf("%c", &ch) != 1) break; // EOF

        if (ch == '[') {
            row.clear();
        } else if (ch == ']') {
            if (!row.empty()) {
                return row;
            }
        } else if (ch == ',' || ch == ' ') {
            continue;
        } else if (ch >= '0' && ch <= '9') {
            ungetc(ch, stdin);
            scanf("%d", &num);
            row.push_back(num);
        }
    }
}

void Input(){
    freopen("input.txt", "r", stdin);
    board = readMatrix();
    moves = readMat();
    fclose(stdin);

    /*
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    printf("-----------------\n");
    for(int i = 0; i < moves.size(); i++){
        printf("%d ", moves[i]);
    }
    */
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", answer);
    fclose(stdout);
}

void Stack_print(stack<int> s){
    stack<int> temp = s;

    while(!temp.empty()){
        printf("%d ", temp.top());
        temp.pop();
    }
    printf("\n");
}

void Solve(){
    stack<int> s_bring;

    for(int i: moves){
        int m_pos = i - 1;
        for(int j = 0; j < board.size(); j++){
            if(board[j][m_pos] != 0){
                int m_item = board[j][m_pos];
                if(!s_bring.empty() && s_bring.top() == m_item){
                    s_bring.pop();
                    answer += 2;
                }else{
                    s_bring.push(m_item);
                }
                board[j][m_pos] = 0;
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
