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

void strassen(int** A, int** B, int** C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
}    
int main(){
    int n=3,A[3][3]={{1,2,3},{4,5,6},{7,8,9}},B[3][3]={{1,2,3},{4,5,6},{7,8,9}},C[3][3];
    int newSize = n / 2;
    int** A11 = (int**)malloc(newSize * sizeof(int*));
    int** A12 = (int**)malloc(newSize * sizeof(int*));
    int** A21 = (int**)malloc(newSize * sizeof(int*));
    int** A22 = (int**)malloc(newSize * sizeof(int*));
    int** B11 = (int**)malloc(newSize * sizeof(int*));
    int** B12 = (int**)malloc(newSize * sizeof(int*));
    int** B21 = (int**)malloc(newSize * sizeof(int*));
    int** B22 = (int**)malloc(newSize * sizeof(int*));
    int** M1 = (int**)malloc(newSize * sizeof(int*));
    int** M2 = (int**)malloc(newSize * sizeof(int*));
    int** M3 = (int**)malloc(newSize * sizeof(int*));
    int** M4 = (int**)malloc(newSize * sizeof(int*));
    int** M5 = (int**)malloc(newSize * sizeof(int*));
    int** M6 = (int**)malloc(newSize * sizeof(int*));
    int** M7 = (int**)malloc(newSize * sizeof(int*));
    int** C11 = (int**)malloc(newSize * sizeof(int*));
    int** C12 = (int**)malloc(newSize * sizeof(int*));
    int** C21 = (int**)malloc(newSize * sizeof(int*));
    int** C22 = (int**)malloc(newSize * sizeof(int*));

    for (int i = 0; i < newSize; i++) {
        A11[i] = (int*)malloc(newSize * sizeof(int));
        A12[i] = (int*)malloc(newSize * sizeof(int));
        A21[i] = (int*)malloc(newSize * sizeof(int));
        A22[i] = (int*)malloc(newSize * sizeof(int));
        B11[i] = (int*)malloc(newSize * sizeof(int));
        B12[i] = (int*)malloc(newSize * sizeof(int));
        B21[i] = (int*)malloc(newSize * sizeof(int));
        B22[i] = (int*)malloc(newSize * sizeof(int));
        M1[i] = (int*)malloc(newSize * sizeof(int));
        M2[i] = (int*)malloc(newSize * sizeof(int));
        M3[i] = (int*)malloc(newSize * sizeof(int));
        M4[i] = (int*)malloc(newSize * sizeof(int));
        M5[i] = (int*)malloc(newSize * sizeof(int));
        M6[i] = (int*)malloc(newSize * sizeof(int));
        M7[i] = (int*)malloc(newSize * sizeof(int));
        C11[i] = (int*)malloc(newSize * sizeof(int));
        C12[i] = (int*)malloc(newSize * sizeof(int));
        C21[i] = (int*)malloc(newSize * sizeof(int));
        C22[i] = (int*)malloc(newSize * sizeof(int));
    }

    // Dividing the matrices into 4 sub-matrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculating M1 to M7
    int** temp1 = (int**)malloc(newSize * sizeof(int*));
    int** temp2 = (int**)malloc(newSize * sizeof(int*));
    for (int i = 0; i < newSize; i++) {
        temp1[i] = (int*)malloc(newSize * sizeof(int));
        temp2[i] = (int*)malloc(newSize * sizeof(int));
    }

    add(A11, A22, temp1, newSize);  // A11 + A22
    add(B11, B22, temp2, newSize);  // B11 + B22
    strassen(temp1, temp2, M1, newSize);  // M1 = (A11 + A22)(B11 + B22)

    add(A21, A22, temp1, newSize);  // A21 + A22
    strassen(temp1, B11, M2, newSize);  // M2 = (A21 + A22)B11

    subtract(B12, B22, temp2, newSize);  // B12 - B22
    strassen(A11, temp2, M3, newSize);  // M3 = A11(B12 - B22)

    subtract(B21, B11, temp2, newSize);  // B21 - B11
    strassen(A22, temp2, M4, newSize);  // M4 = A22(B21 - B11)

    add(A11, A12, temp1, newSize);  // A11 + A12
    strassen(temp1, B22, M5, newSize);  // M5 = (A11 + A12)B22

    subtract(A21, A11, temp1, newSize);  // A21 - A11
    add(B11, B12, temp2, newSize);  // B11 + B12
    strassen(temp1, temp2, M6, newSize);  // M6 = (A21 - A11)(B11 + B12)

    subtract(A12, A22, temp1, newSize);  // A12 - A22
    add(B21, B22, temp2, newSize);  // B21 + B22
    strassen(temp1, temp2, M7, newSize);  // M7 = (A12 - A22)(B21 + B22)

    // Combining the results into C
    add(M1, M4, C11, newSize);  // C11 = M1 + M4
    subtract(M5, M1, C12, newSize);  // C12 = M5 - M1 + M2
    add(M2, M3, C21, newSize);  // C21 = M2 + M3
    add(M3, M6, C22, newSize);  // C22 = M4 + M3 - M6

    // Combining the final results into C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            C[j][k]=0;
            for(int l=0;l<n;l++){
                C[j][k]+=A[j][l]*B[l][k];
            }
        }    
    }
    printf("product of two matices is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    // Free allocated memory
    for (int i = 0; i < newSize; i++) {
        free(A11[i]);
        free(A12[i]);
        free(A21[i]);
        free(A22[i]);
        free(B11[i]);
        free(B12[i]);
        free(B21[i]);
        free(B22[i]);
        free(M1[i]);
        free(M2[i]);
        free(M3[i]);
        free(M4[i]);
        free(M5[i]);
        free(M6[i]);
        free(M7[i]);
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
    free(M1);
    free(M2);
    free(M3);
    free(M4);
    free(M5);
    free(M6);
    free(M7);
    return 0;
}