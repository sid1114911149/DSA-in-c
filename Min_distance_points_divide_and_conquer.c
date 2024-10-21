#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

// A structure to represent a 2D point
typedef struct {
    int x, y;
} Point;

// A utility function to find the distance between two points
double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// Comparator function to sort points by X coordinate
int compareX(const void* a, const void* b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return p1->x - p2->x;
}

// Comparator function to sort points by Y coordinate
int compareY(const void* a, const void* b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return p1->y - p2->y;
}

// A brute force method to calculate the smallest distance between points in a subset
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

// A utility function to find the smaller of two double values
double min(double a, double b) {
    return (a < b) ? a : b;
}

// A function to find the closest distance across the dividing line (strip)
double stripClosest(Point strip[], int size, double d) {
    double minDist = d; // Initialize the minimum distance as d

    // Sort the points in the strip by their Y coordinates
    qsort(strip, size, sizeof(Point), compareY);

    // Check only the next 7 points (important optimization)
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

// A recursive function to find the closest distance in a set of points
double closestUtil(Point points[], int n) {
    // If there are 3 or fewer points, use the brute force approach
    if (n <= 3) {
        return bruteForce(points, n);
    }

    // Find the middle point
    int mid = n / 2;
    Point midPoint = points[mid];

    // Recursively find the smallest distance in the left and right halves
    double dl = closestUtil(points, mid);
    double dr = closestUtil(points + mid, n - mid);

    // Find the smaller of the two distances
    double d = min(dl, dr);

    // Create an array to hold points close to the dividing line (within distance d)
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(points[i].x - midPoint.x) < d) {
            strip[j++] = points[i];
        }
    }

    // Find the closest points in the strip and return the minimum distance
    return min(d, stripClosest(strip, j, d));
}

// A wrapper function to find the closest pair of points
double closest(Point points[], int n) {
    // Sort the points by their X coordinates
    qsort(points, n, sizeof(Point), compareX);

    // Use the recursive utility function to find the closest distance
    return closestUtil(points, n);
}

// Main function to test the closest pair of points algorithm
int main() {
    Point points[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(points) / sizeof(points[0]);

    printf("The smallest distance is %.6f\n", closest(points, n));

    return 0;
}
