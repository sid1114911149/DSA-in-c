#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
typedef struct {
    int x, y;
} Point;
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}
int compareX(const void* a, const void* b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return p1->x - p2->x;
}
int compareY(const void* a, const void* b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return p1->y - p2->y;
}
double bruteForce(Point points[], int n) {
    double minDist = FLT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    return minDist;
}
double min(double a, double b) {
    return (a < b) ? a : b;
}
double stripClosest(Point strip[], int size, double d) {
    double minDist = d;
    qsort(strip, size, sizeof(Point), compareY);
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; ++j) {
            double dist = distance(strip[i], strip[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    return minDist;
}
double closestUtil(Point points[], int n) {
    if (n <= 3) {
        return bruteForce(points, n);
    }
    int mid = n / 2;
    Point midPoint = points[mid];
    double dl = closestUtil(points, mid);
    double dr = closestUtil(points + mid, n - mid);
    double d = min(dl, dr);
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(points[i].x - midPoint.x) < d) {
            strip[j++] = points[i];
        }
    }
    return min(d, stripClosest(strip, j, d));
}
double closest(Point points[], int n) {
    qsort(points, n, sizeof(Point), compareX);
    return closestUtil(points, n);
}
int main() {
    Point points[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(points) / sizeof(points[0]);

    printf("The smallest distance is %.6f\n", closest(points, n));

    return 0;
}
