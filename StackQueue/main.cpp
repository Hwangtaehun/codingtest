#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void queueTest();
void stackTest();

int main()
{
    queueTest();
    stackTest();
    return 0;
}

void queueTest()
{
    queue <int> q1;
    q1.push(11);
    q1.push(22);
    q1.push(33);
    cout << "q1 size : " << q1.size() << endl;
    cout << q1.front() << " " << q1.back() <<endl;

    while(!q1.empty()){
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
    cout << "q1 size : " << q1.size() << endl;

    queue<pair<int, int>> q2;
    q2.push(make_pair(1, 2));
    pair<int, int> p = make_pair(33, 44);
    q2.push(p);

    cout << q2.front().first << " " << q2.front().second << "\t";
    cout << q2.back().first << " " << q2.back().second << endl;

    while( !q2.empty())
    {
        pair<int, int> n = q2.front();
        cout << n.first << ' ' << n.second << '\n';
        q2.pop();
    }

    q2.push(make_pair(5, 6));
    q2.push(make_pair(7, 8));
    cout << "q2 size : " << q2.size() << endl;

    queue<pair<int, int>> tmp;
    swap(q2, tmp);

    cout << "q2 size : " << q2.size() << endl;
}

void stackTest()
{
    stack <int> s1;
    s1.push(11);
    s1.push(22);
    s1.push(33);
    cout << "\ns1 size : " << s1.size() << endl;
    cout << "s1.top() : " << s1.top() <<endl;

    while(!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    cout << "s1 size : " << s1.size() << endl;

    stack<pair<int, int>> s2;
    s2.push(make_pair(1, 2));
    s2.push(make_pair(3, 4));
    s2.push(make_pair(5, 6));

    while( !s2.empty() ) {
        cout << s2.top().first << " " << s2.top().second << endl;
        s2.pop();
    }
}
