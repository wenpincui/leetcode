#include <iostream>
#include <vector>
#include <map>

using namespace std;
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        map<double, int> slope_map;
        vector<Point>::iterator iter1, iter2;
        map<double, int>::iterator iter3;
        double slope;
        int max1 = 0, max2 = 0, same = 0, vertical = 0;

        if (points.size() == 1)
            return 1;

        for (iter1 = points.begin(); iter1 != points.end(); iter1++) {
            if (max1 < vertical)
                max1 = vertical;
            if (max2 < max1 + same + 1)
                max2 = max1 + same + 1;

            max1 = 0;
            same = 0;
            vertical = 0;
            slope_map.clear();
            for (iter2 = iter1 + 1; iter2 != points.end(); iter2++) {
                if ((*iter1).x == (*iter2).x) {
                    if ((*iter1).y == (*iter2).y)
                        same++;
                    else
                        vertical++;
                    continue;
                }

                slope = findSlope(&(*iter1), &(*iter2));
                iter3 = slope_map.find(slope);
                if (iter3 == slope_map.end()) {
                    slope_map.insert(pair<double, int>(slope, 1));
                    if (max1 < 1)
                        max1 = 1;
                } else {
                    iter3->second += 1;
                    if (max1 < iter3->second)
                        max1 = iter3->second;
                }
            }
        }

        return max2;
    }

private:
    double findSlope(Point *p1, Point *p2) {
        return 1.0*(p2->y - p1->y)/(p2->x - p1->x);
    }
};

int main(int argc, char **argv)
{
    vector<Point> points;
    Solution *sol = new Solution();

    points.push_back(Point(-4, 1));
    points.push_back(Point(-7, 7));
    points.push_back(Point(-1, 5));
    points.push_back(Point(9, -25));


    printf("max line %d\n", sol->maxPoints(points));

    return 0;
}
