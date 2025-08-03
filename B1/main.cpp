#include <stdio.h>
#include <algorithm>

using namespace std;

int m_size, m_cnt, m_pla[31], m_data[31][31];

void Input() {
    freopen("input.txt", "r", stdin);

    scanf("%d", &m_size);
    for( int i = 0; i < 7; i++ ){
        for(int j = 0; j < 7; j++){
            scanf("%d", &m_data[i][j]);
        }
    }

    fclose(stdin);
}

void Dfs(int r, int c, int no) {
    if( r < 0 || r >= m_size || c < 0 || c >= m_size || m_data[r][c] != 1)
        return;

    m_data[r][c] = no;

    Dfs(r +1, c, no);
    Dfs(r - 1, c, no);
    Dfs(r, c + 1, no);
    Dfs(r, c - 1, no);
}

bool compare(int left, int right) {
    return left > right;
}

void Solve() {
    for( int i = 0; i < 7; i++ ) {
        for(int j = 0; j < 7; j++) {
            if( m_data[i][j] == 1){
                m_cnt++;
                Dfs(i, j, m_cnt+1);
            }
        }
    }

    for( int i = 0; i < 7; i++ ) {
        for(int j = 0; j < 7; j++) {
            if( m_data[i][j] ){
                m_pla[m_data[i][j] - 2]++;
            }
        }
    }

    sort(m_pla, m_pla + m_cnt, compare);
}

void Output(){
    freopen("output.txt", "w", stdout);

    printf("%d\n", m_cnt);
    for( int  i = 0; i < m_cnt; i++){
        printf("%d\n", m_pla[i]);
    }

    fclose(stdout);
}

void ArrayPrn()
{
    printf("탐색 후 배열 내용 \n");
    for( int i = 0; i < 7; i++ ) {
        for(int j = 0; j < 7; j++) {
            printf("%2d", m_data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{

    Input();
    Solve();
    ArrayPrn();
    Output();

    return 0;
}
