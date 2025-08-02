#include <cstdio>
#include <vector>

using namespace std;

int a, b, w, node;
int vertex, edge, data[101][101];
vector <int> v1[100];
vector <pair <int, int>> v2[100];

void input1();
void output1();
void input2();
void output2();
void input3();
void output3();
void input4();
void output4();

int main()
{
    input1();
    output1();
    input2();
    output2();
    input3();
    output3();
    input4();
    output4();
    return 0;
}

void input1() {
    freopen("B01.txt", "r", stdin);
    scanf("%d %d", &vertex, &edge);
    for (int i = 0; i < edge; i++) {
        scanf("%d %d %d", &a, &b, &w);
        data[a][b] = data[b][a] = w;
    }
}

void output1(){
    printf("1. 인접행렬 정점의 수 %d, 간선의 수 = %d\n\n", vertex, edge);
    for(int i = 1; i <= vertex; i++) {
        for(int j = 1; j <= vertex; j++) {
            printf("%5d", data[i][j]);
        }
        printf("\n");
    }
}

void input2() {
    freopen("B01.txt", "r", stdin);
    scanf("%d %d", &node, &edge);
    for(int i = 0; i < edge; i++) {
        scanf("%d %d %d", &a, &b, &w);
        v1[a].push_back(b);
        v1[b].push_back(a);
    }
}

void output2() {
    printf("\n2. 가중치 없는 인접리스트 vector 사용 \n");
    for( int  i = 1; i <= node; i++){
        printf("node %d : ", i);
        for( int j = 0; j < v1[i].size(); j++) {
            printf("%5d", v1[i][j]);
        }
        printf("\n");
    }
}

void input3() {
    for(int i = 0; i < edge; i++) {
        vi[i].clear();
    }
    freopen("B01.txt", "r", stdin);
    scanf("%d %d", &node, &edge);
    for(int i = 0; i < edge; i++) {
        scanf("%d %d %d", &a, &b, &w);
        v1[a].push_back(b);
        v1[a].push_back(w);
        v1[b].push_back(a);
        v1[b].push_back(w);
    }
}

void output3() {
    printf("\n3. 가중치 있는 인접리스트 vector 사용 \n");
    for( int i = 1; i <= node; i++ ) {
        printf("node %d : ", i);
        for( int j = 0; j < v1[i].size(); j++ ) {
                printf("%5d", v1[i][j]);
        }
        printf("\n");
    }
}

void input4() {
    freopen("B01.txt", "r", stdin);
    scanf("%d %d", &node, &edge);
    for( int i = 0; i < edge; i++) {
        scanf("%d %d %d", &a, &b, &w);
        v2[a].push_back(make_pair(b, w));
        v2[b].push_back(make_pair(a, w));
    }
}

void output4() {
    printf("\n4.가중치 있는 인접리스트 vector, pair 사용 \n");
    for ( int i = 1; i <= node; i++ ) {
        printf("node %d : ", i);
        for( int j = 0; j < v2[i].size(); j++ ) {
            printf("%5d%5d", v2[i][j].first, v2[i][j].second);
        }
        printf("\n");
    }
}
