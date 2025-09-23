#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> numbers = {1, 2, 3, 4, 5};
    int targets[] = {3, 7};

    for(int target: targets) {
        auto it = numbers.find(target);

        if(it != numbers.end()){
            cout << "원소" << target << "를 찾았습니다. 값: " << *it << endl;
        } else {
            cout << "원소" << target << "를 찾지 못했습니다."<< endl;
        }
    }
    return 0;
}
