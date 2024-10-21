#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

// A utility function to swap two points
void swap(Point* a, Point* b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
}

// A utility function to find the orientation of three points (p, q, r).
// It returns:
// 0 if p, q, r are collinear
// 1 if Clockwise
// 2 if Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // collinear
    return (val > 0) ? 1 : 2;  // clockwise or counterclockwise
}

// Comparator function to sort points by x-coordinate (and y if x is equal)
int compareX(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->x == p2->x) ? (p1->y - p2->y) : (p1->x - p2->x);
}

// Function to find the upper tangent between two convex hulls
int findUpperTangent(Point left[], int nL, Point right[], int nR, int* iLeft, int* iRight) {
    *iLeft = nL - 1;  // Start from the rightmost point of the left hull
    *iRight = 0;      // Start from the leftmost point of the right hull

    while (1) {
        int changed = 0;

        // Move iLeft counter-clockwise if needed
        while (orientation(left[*iLeft], right[*iRight], right[(*iRight + 1) % nR]) == 2) {
            *iRight = (*iRight + 1) % nR;
            changed = 1;
        }

        // Move iRight clockwise if needed
        while (orientation(right[*iRight], left[*iLeft], left[(*iLeft - 1 + nL) % nL]) == 1) {
            *iLeft = (*iLeft - 1 + nL) % nL;
            changed = 1;
        }

        if (!changed) break;
    }
    return 0;
}

// Function to merge two convex hulls into one
void mergeHulls(Point left[], int nL, Point right[], int nR, Point hull[], int* hullSize) {
    int iLeft, iRight;

    // Find upper tangent
    findUpperTangent(left, nL, right, nR, &iLeft, &iRight);

    // Traverse left hull counter-clockwise from upper tangent to lower tangent
    int start = iLeft;
    do {
        hull[(*hullSize)++] = left[iLeft];
        iLeft = (iLeft + 1) % nL;
    } while (iLeft != start);

    // Traverse right hull clockwise from upper tangent to lower tangent
    start = iRight;
    do {
        hull[(*hullSize)++] = right[iRight];
        iRight = (iRight + 1) % nR;
    } while (iRight != start);
}

// Recursive function to find the convex hull using divide and conquer
void convexHullDivideAndConquer(Point points[], int n, Point hull[], int* hullSize) {
    // Base case: If there are only a few points, return their convex hull
    if (n <= 3) {
        for (int i = 0; i < n; i++) {
            hull[i] = points[i];
        }
        *hullSize = n;
        return;
    }

    // Step 1: Divide the points into two halves
    int mid = n / 2;
    Point left[mid];
    Point right[n - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = points[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = points[i];
    }

    // Step 2: Recursively find the convex hull for each half
    Point leftHull[mid * 2];
    Point rightHull[(n - mid) * 2];
    int leftHullSize = 0, rightHullSize = 0;

    convexHullDivideAndConquer(left, mid, leftHull, &leftHullSize);
    convexHullDivideAndConquer(right, n - mid, rightHull, &rightHullSize);

    // Step 3: Merge the two convex hulls
    *hullSize = 0;
    mergeHulls(leftHull, leftHullSize, rightHull, rightHullSize, hull, hullSize);
}

// Wrapper function for convex hull
void convexHull(Point points[], int n) {
    if (n < 3) {
        printf("Convex hull not possible\n");
        return;
    }

    // Sort points by x-coordinate
    qsort(points, n, sizeof(Point), compareX);

    Point hull[n * 2];
    int hullSize = 0;

    // Call divide and conquer function
    convexHullDivideAndConquer(points, n, hull, &hullSize);

    // Print the points in the convex hull
    printf("The points in Convex Hull are:\n");
    for (int i = 0; i < hullSize; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

// Main function to test the convex hull algorithm
int main() {
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);

    convexHull(points, n);

    return 0;
}
