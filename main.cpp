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

double stripClosest(vector<Point>& strip, double d) {
    double minDist = d;

    sort(strip.begin(), strip.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
    });

    for(size_t=e;i<strip.size();i++){
       for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = min(minDist, calculateDistance(strip[i], strip[j]));
        }
    }
}

double divideAndConquer(vector<Point>& points, int left, int right) {
    if (right - left <= 3) {
        return bruteForce(points, left, right);
    }

    int mid = left + (right - left) / 2;
    Point midPoint = points[mid];

   
    double leftDist = divideAndConquer(points, left, mid);
    double rightDist = divideAndConquer(points, mid + 1, right);

    double minDist = min(leftDist, rightDist);

  
    vector<Point> strip;
    for (int i = left; i <= right; ++i) {
        if (abs(points[i].x - midPoint.x) < minDist) {
            strip.push_back(points[i]);
        }
    }

 
    return min(minDist, stripClosest(strip, minDist));
}
  
  double optimizeRoutes(vector<Point>& points) {
    // Sort points by x-coordinate
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });

    return divideAndConquer(points, 0, points.size() - 1);
}
int main()   
{

       // Example delivery points
    vector<Point> deliveryPoints = {
        {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}
    };

    // Optimize the delivery routes
    double shortestDistance = optimizeRoutes(deliveryPoints);
    // for displaying the delivery points
    displayPoints(deliveryPoints);

    //Calculating the average distance between points
    //Just for the sake of having general insights in to how far the points relative to each other
    double averageDistance = calculateAverageDistance(deliveryPoints);
    
    cout << "Average distance between all points: " << averageDistance << endl;
    cout << "Closest points: (" << closestPair.first.x << ", " << closestPair.first.y << ") and (" << closestPair.second.x << ", " << closestPair.second.y << ")" << endl;
    cout << "Total distance calculations performed: " << distanceCalculations << endl;


    cout << "Shortest delivery route distance: " << shortestDistance << endl;
    return 0;
}
