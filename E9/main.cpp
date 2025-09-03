#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> >g_data;
int g_size;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    fclose(stdin);
}

void Output(){
    //freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_data.size(); i++){
        for(int j = 0; j < g_size; j++){
            if(g_data[i][j] != 0){
                printf("%d ", g_data[i][j]);
            }
        }
        printf("\n");
    }
    //fclose(stdout);
}

int Sum(int arr[]){
    int m_sum = 0;
    for(int i = 0; i < g_size; i++){
        m_sum += arr[i];
    }
    return m_sum;
}

void mySolve(int arr[], int num, int index){
    arr[index] = num;

    if(index == g_size - 1){
        if(Sum(arr) == g_size){
            vector<int> m_ele;
            for(int i = 0; i < g_size; i++){
                m_ele.push_back(arr[i]);
                //printf("%d ", arr[i]);
            }
            //printf("\n");
            g_data.push_back(m_ele);
        }
        return;
    }

    for(int i = num; i >= 0; i--){
        if(num >= i){
            mySolve(arr, i, index+1);
        }
    }
}

int main()
{
    Input();
    int *m_arr = new int[g_size];

    for(int i = g_size; i > 0; i--){
        for(int j = 0; j < g_size; j++){
            m_arr[j] = 0;
        }
        mySolve(m_arr, i, 0);
    }
    Output();
    return 0;
}
