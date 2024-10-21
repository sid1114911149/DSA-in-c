#include <stdio.h>
#include <stdlib.h>

void add(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void multiply(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    // Allocate memory for submatrices
    int** A11 = (int**)malloc(k * sizeof(int*));
    int** A12 = (int**)malloc(k * sizeof(int*));
    int** A21 = (int**)malloc(k * sizeof(int*));
    int** A22 = (int**)malloc(k * sizeof(int*));
    int** B11 = (int**)malloc(k * sizeof(int*));
    int** B12 = (int**)malloc(k * sizeof(int*));
    int** B21 = (int**)malloc(k * sizeof(int*));
    int** B22 = (int**)malloc(k * sizeof(int*));
    int** C11 = (int**)malloc(k * sizeof(int*));
    int** C12 = (int**)malloc(k * sizeof(int*));
    int** C21 = (int**)malloc(k * sizeof(int*));
    int** C22 = (int**)malloc(k * sizeof(int*));

    for (int i = 0; i < k; i++) {
        A11[i] = (int*)malloc(k * sizeof(int));
        A12[i] = (int*)malloc(k * sizeof(int));
        A21[i] = (int*)malloc(k * sizeof(int));
        A22[i] = (int*)malloc(k * sizeof(int));
        B11[i] = (int*)malloc(k * sizeof(int));
        B12[i] = (int*)malloc(k * sizeof(int));
        B21[i] = (int*)malloc(k * sizeof(int));
        B22[i] = (int*)malloc(k * sizeof(int));
        C11[i] = (int*)malloc(k * sizeof(int));
        C12[i] = (int*)malloc(k * sizeof(int));
        C21[i] = (int*)malloc(k * sizeof(int));
        C22[i] = (int*)malloc(k * sizeof(int));
    }

    // Dividing the matrices into 4 sub-matrices
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Calculate C11, C12, C21, C22
    int** temp1 = (int**)malloc(k * sizeof(int*));
    int** temp2 = (int**)malloc(k * sizeof(int*));
    for (int i = 0; i < k; i++) {
        temp1[i] = (int*)malloc(k * sizeof(int));
        temp2[i] = (int*)malloc(k * sizeof(int));
    }

    // C11 = A11 * B11 + A12 * B21
    multiply(A11, B11, C11, k);
    multiply(A12, B21, temp1, k);
    add(C11, temp1, C11, k);

    // C12 = A11 * B12 + A12 * B22
    multiply(A11, B12, C12, k);
    multiply(A12, B22, temp1, k);
    add(C12, temp1, C12, k);

    // C21 = A21 * B11 + A22 * B21
    multiply(A21, B11, C21, k);
    multiply(A22, B21, temp1, k);
    add(C21, temp1, C21, k);

    // C22 = A21 * B12 + A22 * B22
    multiply(A21, B12, C22, k);
    multiply(A22, B22, temp1, k);
    add(C22, temp1, C22, k);

    // Combine the results into C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    // Free allocated memory
    for (int i = 0; i < k; i++) {
        free(A11[i]);
        free(A12[i]);
        free(A21[i]);
        free(A22[i]);
        free(B11[i]);
        free(B12[i]);
        free(B21[i]);
        free(B22[i]);
        free(C11[i]);
        free(C12[i]);
        free(C21[i]);
        free(C22[i]);
        free(temp1[i]);
        free(temp2[i]);
    }
    free(A11);
    free(A12);
    free(A21);
    free(A22);
    free(B11);
    free(B12);
    free(B21);
    free(B22);
    free(C11);
    free(C12);
    free(C21);
    free(C22);
    free(temp1);
    free(temp2);
}

int main() {
    int n;

    printf("Enter the size of the matrices (n x n): ");
    scanf("%d", &n);

    // Allocate memory for matrices A, B, and C
    int** A = (int**)malloc(n * sizeof(int*));
    int** B = (int**)malloc(n * sizeof(int*));
    int** C = (int**)malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(n * sizeof(int));
        B[i] = (int*)malloc(n * sizeof(int));
        C[i] = (int*)malloc(n * sizeof(int));
    }

    // Input matrices A and B
    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    // Multiply matrices
    multiply(A, B, C, n);
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            C[j][k]=0;
            for(int l=0;l<n;l++){
                C[j][k]+=A[j][l]*B[l][k];
            }
        }    
    }
    // Output the result
    printf("Resulting matrix C (A * B):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
