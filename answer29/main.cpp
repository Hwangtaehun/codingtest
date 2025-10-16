#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> lst, search_lst;
vector<bool> answer;

class Node {
    public:
        int val, height;
        Node *left, *right;

        Node(int key) {
            val = key;
            height = 1;
            left = nullptr;
            right = nullptr;
        }
};

class BST {
    private:
        Node* root;

        int getHeight(Node *node) {
            return node ? node->height : 0;
        }

        int getBalanceFactor(Node* node) {
            return node ? (getHeight(node->left) - getHeight(node->right)) : 0;
        }

        bool searchNode(Node* node, int key){
            if(!node) {
                return false;
            }

            if(key == node->val) {
                return true;
            }

            return key < node->val ? searchNode(node->left, key) : searchNode(node->right, key);
        }

        void updateHeight(Node* node){
            if(node) {
                node->height = 1 + max(getHeight(node->left), getHeight(node->right));
            }
        }

        Node* rightRotate(Node* y) {
            Node* x = y->left;
            Node* temp = x->right;

            x->right = y;
            y->left = temp;

            updateHeight(y);
            updateHeight(x);

            return x;
        }

        Node* leftRotate(Node *x){
            Node* y = x->right;
            Node* temp = y->left;

            y->left = x;
            x->right = temp;

            updateHeight(x);
            updateHeight(y);

            return y;
        }

        Node* insertNode(Node* node, int key) {
            int balance;

            if(!node) {
                return new Node(key);
            }

            if(key < node->val) {
                node->left = insertNode(node->left, key);
            } else if(key > node->val) {
                node->right = insertNode(node->right, key);
            } else {
                return node;
            }

            updateHeight(node);
            balance = getBalanceFactor(node);

            if (balance > 1 && key < node->left->val) {
                return rightRotate(node);
            } else if (balance < -1 && key < node->right->val){
                return leftRotate(node);
            } else if (balance > 1 && key > node->left->val) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            } else if (balance < -1 && key < node->right->val) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            return node;
        }

    public:
        BST() {
            root = nullptr;
        }

        void m_insert(int key) {
            root = insertNode(root, key);
        }

        bool m_search(int key) {
            return searchNode(root, key);
        }
};

void Input() {
    string line;
    vector<string> lines;

    freopen("input.txt", "r", stdin);

    while(getline(cin, line)) {
        if(!line.empty()) {
            lines.push_back(line);
        }
    }

    fclose(stdin);

    for(int i = 0; i < lines.size(); i++) {
        string s;
        stringstream ss;

        lines[i].erase(remove(lines[i].begin(), lines[i].end(), '['), lines[i].end());
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), ']'), lines[i].end());
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), '\"'), lines[i].end());
        ss.str(lines[i]);

        while(getline(ss, s, ',')) {
            s.erase(0, s.find_first_not_of(" \t\n\r"));
            s.erase(s.find_last_not_of(" \t\n\r") + 1);

            if(!s.empty()) {
                if(i == 0) {
                    lst.push_back(stoi(s));
                } else if(i == 1){
                    search_lst.push_back(stoi(s));
                }
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);

    printf("[");

    for(int i = 0; i < answer.size(); i++){
        if(i != 0){
            printf(",");
        }

        if(answer[i]){
            printf("true");
        }else{
            printf("false");
        }
    }

    printf("]");

    fclose(stdout);
}

void Solve(){
    BST bst;

    for(int key : lst){
        bst.m_insert(key);
    }

    for(int search_val : search_lst) {
        answer.push_back(bst.m_search(search_val));
    }
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
