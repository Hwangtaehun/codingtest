#include <iostream>
#include <vector>

using namespace std;

struct nodeInfo {
    int V;
    int W;
};

vector<vector <nodeInfo> > adjList;

void addEdge(int u, int v, int w){
    adjList[u].push_back({v, w});
}

void printAdjList() {
    for(int i = 0; i < adjList.size(); i++){
        cout << "Node" << i << ":";
        for(const auto& node : adjList[i]) {
            cout << " -> (V: " << node.V << ", W: " << node.W << ")";
        }
        cout << endl;
    }
}

int main()
{
    int N = 5;
    adjList.resize(N);
    addEdge(1, 2, 3);
    addEdge(2, 1, 6);
    addEdge(2, 3, 5);
    addEdge(3, 2, 1);
    addEdge(3, 4, 13);
    addEdge(4, 4, 9);
    addEdge(4, 1, 42);
    printAdjList();
    return 0;
}
