#include <cstdio>
#include <vector>
#define SIZE 3

using namespace std;

int g_len, g_min = 0x7fffffff;
int g_ins[SIZE] = {1, 2, 3};

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_len);
    fclose(stdin);
}

void Output(){
    //freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    //fclose(stdout);
}

void Print(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool myCheck(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        int m_itv = (arr.size() - i) / 2;
        for(int j = 1; j <= m_itv; j++){
            bool same = true;
            for(int k = 0; k < j; k++){
                if(arr[k + i] != arr[k + i + j]){
                    same = false;
                }
            }

            if(same){
                return true;
            }
        }
    }

    return false;
}

void mySolve(vector<int> arr){
    //Print(arr);

    if(arr.size() >= g_len){
        if(!myCheck(arr)){
            int m_res = 0;
            for(int i = 0; i < arr.size(); i++){
                m_res = m_res * 10 + arr[i];
            }
            //printf("m_res = %d\n", m_res);
            if(m_res < g_min){
                g_min = m_res;
            }
            return;
            }
    }

    if(myCheck(arr)){
        return;
    }

    for(int i = 0; i < SIZE; i++){
        arr.push_back(g_ins[i]);
        mySolve(arr);
        arr.pop_back();
    }
}

int main()
{
    vector<int> m_arr;
    Input();
    mySolve(m_arr);
    Output();
    return 0;
}
