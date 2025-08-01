#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void pairTest()
{
    pair<char, double> pa = make_pair('A', 56.7);
    int aa = 11, bb = 22;
    pair<int, int> pb;
    pb = make_pair(aa, bb);

    cout << pa.first << "\t" << pa.second << endl;
    cout << pb.first << "\t" << pb.second << endl;
}

void vectorPrn(char *str, vector<int> iv)
{
    cout << str << " : ";
    for(int i = 0; i < iv.size(); i++){
        cout << iv[i] << " ";
    }
    cout << endl;
}

void vectorTest()
{
    vector<int> iv1;
    vector<int> iv2(3);
    vector<int> iv3(5, 2);

    iv1.push_back(1);
    iv1.push_back(2);
    iv1.push_back(3);

    vectorPrn("iv1 ", iv1);
    iv2.push_back(123);
    vectorPrn("iv2 ", iv2);
    vectorPrn("iv3 ", iv3);

    vector<pair<int, int>> pv;
    pv.push_back(make_pair(2,4));
    pv.push_back(make_pair(1,5));
    cout << "pv[0] : " << pv[0].first << "\t" << pv[0].second << endl;
    cout << "pv[1] : " << pv[1].first << "\t" << pv[1].second << endl;

    iv1.resize(4);
    cout << " iv1.size() : " << iv1.size() << endl;
    cout << " iv1.front() : " << iv1.front() << endl;
    cout << " iv1.back() : " << iv1.back() << endl;
    iv1.pop_back();
    cout << " iv1.size() : " << iv1.size() << endl;
    iv1.clear();
    cout << " iv1.size() : " << iv1.size() << endl;
}

int main()
{
    pairTest();
    vectorTest();
    return 0;
}
