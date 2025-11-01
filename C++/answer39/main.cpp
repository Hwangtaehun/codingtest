#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <limits>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

#define INF 0xFFFFFFF

vector<tuple<int, int, int>> edges;
int num_vertices, source;
vector<int> answer;

void Input(){
    string s;
    vector<int> vt;

    freopen("input.txt", "r", stdin);

    cin >> source >> num_vertices;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);

    fclose(stdin);

    s.erase(remove(s.begin(), s.end(), '['), s.end());
    s.erase(remove(s.begin(), s.end(), ']'), s.end());

    stringstream ss(s);

    while(getline(ss, s, ',')){
        s.erase(0, s.find_first_not_of(" \t\n\r"));
        s.erase(s.find_last_not_of(" \t\n\r") + 1);

        if(!s.empty()){
            vt.push_back(stoi(s));

            if(vt.size() == 3){
                tuple<int, int, int> tt = make_tuple(vt[0], vt[1], vt[2]);
                edges.push_back(tt);
                vt.clear();
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

template <typename T>
void vector_Print(T v){
    for(auto a: v){
        cout << a << " ";
    }
    cout << endl;
}

void Solve(){
    answer.assign(num_vertices, INF);
    answer[source]  = 0;

    for(int i = 0; i < num_vertices - 1; i++){
        bool updated = false;

        for(int j = 0; j < edges.size(); j++){
            int s = get<0>(edges[j]), g = get<1>(edges[j]), w = get<2>(edges[j]);
            if(answer[s] != INF && answer[s] + w < answer[g]){
                answer[g] = answer[s] + w;
                updated = true;
            }
        }

        if(!updated){
            break;
        }
    }

    for(int i = 0; i < edges.size(); i++){
        int s = get<0>(edges[i]), g = get<1>(edges[i]), w = get<2>(edges[i]);
        if(answer[s] + w < answer[g]){
            answer.assign(1, -1);
            break;
        }
    }
}

vector<int> solution(){
    vector< vector <pair<int, int> > > graph(num_vertices);
    vector<int> distance(num_vertices, INF);

    for(auto &edge : edges) {
        int from, to, weight;
        tie(from, to, weight) = edge;
        graph[from].emplace_back(to, weight);
    }

    distance[source] = 0;

    for(int i = 0; i < num_vertices - 1; i++){
        for(int u = 0; u < num_vertices; u++){
            for(const auto &[v, weight] : graph[u]){
                if(distance[u] + weight < distance[v]){
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    for(int u = 0; u < num_vertices; u++){
        for(const auto &[v, weight] : graph[u]){
            if(distance[u] + weight < distance[v]){
                return vector<int>(1, -1);
            }
        }
    }

    return distance;
}

int main()
{
    Input();
    Solve();
    vector_Print(solution());
    Output();
    return 0;
}
