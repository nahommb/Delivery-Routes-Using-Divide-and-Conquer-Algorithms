#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

double calculateDistance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double bruteForce(vector<Point>& points, int left, int right) {
    double minDist = numeric_limits<double>::max();
    for (int i = left; i <= right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            minDist = min(minDist, calculateDistance(points[i], points[j]));
        }
    }
    return minDist;
}
int main()
{

    
    return 0;
}
