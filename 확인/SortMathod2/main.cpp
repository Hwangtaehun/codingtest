#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
};

bool compare(const Point &a, const Point &b){
    if(a.x == b.x){
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main()
{
    vector<Point> points = {{3, 4}, {1, 2}, {3, 1}, {2, 5}};
    sort(points.begin(), points.end(), compare);

    for(const Point &p : points) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;

    return 0;
}
