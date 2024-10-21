#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_RECORDS 100
#define MAX_DIGITS 10


typedef struct {
    char name[MAX_NAME_LEN];
    int rollno;
    char dob[11]; 
} Record;

// Function prototypes
void radixSort(Record arr[], int n);
void countingSort(Record arr[], int n, int exp);
void printRecords(Record arr[], int n);

int main() {
    int n;
    printf("Enter the number of records: ");
    scanf("%d", &n);

    Record records[MAX_RECORDS];

    printf("Enter the records (NAME ROLLNO DOB):\n");
    for (int i = 0; i < n; i++) {
        printf("Record %d: ", i + 1);
        scanf("%s %d %s", records[i].name, &records[i].rollno, records[i].dob);
    }

    radixSort(records, n);

    printf("\nSorted records by ROLLNO:\n");
    printRecords(records, n);

    return 0;
}

void radixSort(Record arr[], int n) {
    int maxRollno = arr[0].rollno;


    for (int i = 1; i < n; i++) {
        if (arr[i].rollno > maxRollno) {
            maxRollno = arr[i].rollno;
        }
    }

    for (int exp = 1; maxRollno / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void countingSort(Record arr[], int n, int exp) {
    Record output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i].rollno / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i].rollno / exp) % 10] - 1] = arr[i];
        count[(arr[i].rollno / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void printRecords(Record arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("NAME: %-15s ROLLNO: %d DOB: %s\n", arr[i].name, arr[i].rollno, arr[i].dob);
    }
}