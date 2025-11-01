#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

vector<int> answer;
vector< tuple <int, int, int> > edges;
int start, numNodes;

void Input(){
    string s;
    vector<int> temp;

    freopen("input.txt", "r", stdin);

    cin >> start >> numNodes;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);

    fclose(stdin);

    s.erase(remove(s.begin(), s.end(), '['), s.end());
    s.erase(remove(s.begin(), s.end(), ']'), s.end());

    stringstream ss(s);

    while(getline(ss, s, ',')){
        s.erase(0, s.find_first_not_of(" \t\n\r"));
        s.erase(s.find_last_not_of(" \t\n\t") + 1);

        if(!s.empty()){
            temp.push_back(stoi(s));

            if(temp.size() == 3){
                tuple<int, int, int> t = make_tuple(temp[0], temp[1], temp[2]);
                edges.push_back(t);
                temp.clear();
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    cout << "[";
    for(int i = 0; i < answer.size(); i++){
        if(i != 0){
            cout << ", ";
        }
        cout << answer[i];
    }
    cout << "]";
    fclose(stdout);
}

bool Check(vector<bool> v){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == false){
            return true;
        }
    }

    return false;
}

template <typename T>
void vector_Print(T v){
    for(auto a : v){
        cout << a << " ";
    }
    cout << endl;
}

void Solve(){
    int s = start;
    vector<bool> visited(numNodes);

    answer.resize(numNodes);

    for(int i = 0; i < answer.size(); i++){
        answer[i] = 0xFFFFFFF;
    }

    answer[s] = 0;
    visited[s] = true;

    while(Check(visited)){
        int m_min = 0xFFFFFFF;

        for(int i = 0; i < edges.size(); i++){
            if(get<0>(edges[i]) == s){
                int goal = get<1>(edges[i]);
                int price = get<2>(edges[i]) + answer[s];

                answer[goal] = price;
            }
        }

        for(int i = 0; i < answer.size(); i++){
            if(!visited[i] && answer[i] < m_min){
                m_min = answer[i];
                s = i;
            }
        }

        visited[s] = true;
    }
}

//solution
#include <queue>

const int INF = numeric_limits<int>::max();
const int MAX_NODES = 100;
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

vector<int> solution1(){
    vector<int> distances(numNodes, INF);

    for(int i = 0; i < MAX_NODES; i++){
        fill_n(graph[i], MAX_NODES, INF);
        visited[i] = false;
    }

    for(const auto &[from, to, weight] : edges){
        graph[from][to] = weight;
    }

    distances[start] = 0;

    for(int i = 0; i < numNodes - 1; i++){
        int minDistance = INF;
        int closestNode = -1;

        for(int j = 0; j < numNodes; j++){
            if(!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];
                closestNode = j;
            }
        }

        visited[closestNode] = true;

        for(int j = 0; j < numNodes; j++){
            int newDistance = distances[closestNode] + graph[closestNode][j];
            if(!visited[j] && graph[closestNode][j] != INF && newDistance < distances[j]) {
                distances[j] = newDistance;
            }
        }
    }

    return distances;
}

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

vector<int> solution2(){
    priority_queue< pair<int, int> , vector< pair<int, int> >, Compare> pq;
    vector< vector <pair<int, int> > > adjList(numNodes);
    vector<int> distances(numNodes, INF);
    vector<bool> visited(numNodes, false);

    for(const auto& [from, to, weight] : edges) {
        adjList[from].emplace_back(to, weight);
    }

    distances[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if(visited[currentNode]){
            continue;
        }

        visited[currentNode] = true;

        for(const auto& [neighbor, weight] : adjList[currentNode]){
            int newDistance = distances[currentNode] + weight;

            if(newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                pq.push({newDistance, neighbor});
            }
        }
    }

    return distances;
}

int main()
{
    Input();
    Solve();
    vector_Print(solution1());
    vector_Print(solution2());
    Output();
    return 0;
}
