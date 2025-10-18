#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> nodeinfo, answer;

template <typename T>
void Vector_print(T v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void Input(){
    string line;

    freopen("input.txt", "r", stdin);
    getline(cin, line);
    fclose(stdin);

    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());

    stringstream ss(line);
    string token;

    vector<int> temp;
    while (getline(ss, token, ',')) {
        token.erase(0, token.find_first_not_of(" \t\n\r"));
        token.erase(token.find_last_not_of(" \t\n\r") + 1);

        if (!token.empty()) {
            temp.push_back(stoi(token));
            if (temp.size() == 2) {
                nodeinfo.push_back(temp);
                temp.clear();
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);

    printf("[");
    for(int i = 0; i < answer.size(); i++){
        if(i != 0){
            printf(", ");
        }
        printf("[");
        for(int j = 0; j < answer[i].size(); j++){
            if(j != 0){
                printf(", ");
            }
            printf("%d", answer[i][j]);
        }
        printf("]");
    }
    printf("]");

    fclose(stdout);
}

struct Node {
    int id, x, y;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int id, int x, int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }
};

class BinaryTree {
private:
    Node *root = nullptr;

    static bool compareNodes(Node *a, Node *b) {
        if(a->y != b->y){
            return a->y > b->y;
        }

        return a->x < b->x;
    }

    Node *addNode(Node *current, Node *newNode) {
        if(current == nullptr)
            return newNode;

        if(newNode->x  < current->x) {
            current->left = addNode(current->left, newNode);
        } else {
            current->right = addNode(current->right, newNode);
        }

        return current;
    }

    void preOrder(Node *node, vector<int> &traversal) {
        if(node == nullptr)
            return;
        traversal.push_back(node->id);
        preOrder(node->left, traversal);
        preOrder(node->right, traversal);
    }

    void postOrder(Node *node, vector<int> &traversal) {
        if(node == nullptr)
            return;

        postOrder(node->left, traversal);
        postOrder(node->right, traversal);
        traversal.push_back(node->id);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void buildTree(const vector< vector<int> > &nodeinfo){
        vector<Node *> nodes;

        for(int i = 0; i< nodeinfo.size(); ++i) {
            nodes.push_back( new Node( i + 1, nodeinfo[i][0], nodeinfo[i][1] ) );
        }

        sort(nodes.begin(), nodes.end(), compareNodes);

        for(Node *node : nodes) {
            root = addNode(root, node);
        }
    }

    vector<int> getPreOrderTraversal() {
        vector<int> traversal;
        preOrder(root, traversal);

        return traversal;
    }

    vector<int> getPostOrderTraversal() {
        vector<int> traversal;
        postOrder(root, traversal);

        return traversal;
    }
};

void Solve(){
    BinaryTree tree;
    tree.buildTree(nodeinfo);
    answer.push_back(tree.getPreOrderTraversal());
    answer.push_back(tree.getPostOrderTraversal());
}

int main()
{
    Input();
    Solve();
    Output();
    return 0;
}
