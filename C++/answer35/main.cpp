#include <iostream>
#include <cstdio>
#include <sstream>
#include <limits>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, answer;
vector<int> parent;
vector<vector <int> > costs;

void Input(){
    string line;
    vector<int> temp;

    freopen("input.txt", "r", stdin);
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, line);
    fclose(stdin);

    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());

    stringstream ss(line);

    while(getline(ss, line, ',')){
        line.erase(0, line.find_first_not_of(" \t\n\r"));
        line.erase(line.find_last_not_of(" \t\n\t") + 1);

        if(!line.empty()){
            temp.push_back(stoi(line));

            if(temp.size() == 3){
                costs.push_back(temp);
                temp.clear();
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << answer;
    fclose(stdout);
}

bool Compare(const vector<int> n1, const vector<int> n2){
    return n1[2] < n2[2];
}

int findParent(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}

void Solve(){
    sort(costs.begin(), costs.end(), Compare);
    parent.resize(n);

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < costs.size(); i++){
        int a = costs[i][0], b = costs[i][1], cost = costs[i][2];

        if(findParent(a) != findParent(b)) {
            unionParent(a, b);
            answer += cost;
        }
    }
}

//solve
class DisjointSet{
private:
    vector<int> m_parent, m_rank;

public:
    DisjointSet(int m_size){
        m_parent.assign(m_size, -1);
        m_rank.assign(m_size, 0);
    }

    int Find(int node){
        if(m_parent[node] == -1){
            return node;
        }

        return m_parent[node] = Find(m_parent[node]);
    }

    void Merge(int node1, int node2){
        int root1 = Find(node1);
        int root2 = Find(node2);

        if(root1 != root2){
            if(m_rank[root1] > m_rank[root2]){
                m_parent[root2] = root1;
            }else if(m_rank[root1] < m_rank[root2]){
                m_parent[root1] = root2;
            }else{
                m_parent[root2] = root1;
                m_rank[root1]++;
            }
        }
    }

    bool isCycle(int node1, int node2){
        return Find(node1) == Find(node2);
    }
};

int Solution(){
    int totalCost = 0;
    DisjointSet disjointSet(n);

    for(const auto &edge : costs){
        int cost = edge[2];
        int node1 = edge[0];
        int node2 = edge[1];

        if(!disjointSet.isCycle(node1, node2)) {
            disjointSet.Merge(node1, node2);
            totalCost += cost;
        }
    }

    return totalCost;
}

int main()
{
    Input();
    Solve();
    printf("%d\n", Solution());
    Output();
    return 0;
}
