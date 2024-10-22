#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 10  // Size of the hash table

// Function to extract middle digits from a squared value
int midSquareHash(int key) {
    // Square the key
    long square = (long)key * key;

    // Convert the squared value to a string for easy digit extraction
    char squareStr[20];
    sprintf(squareStr, "%ld", square);

    // Find the length of the squared value
    int len = strlen(squareStr);

    // Extract the middle two or three digits (depending on the length)
    int mid = len / 2;

    // Get 2 middle digits for this example
    char midDigits[3];
    midDigits[0] = squareStr[mid - 1];
    midDigits[1] = squareStr[mid];
    midDigits[2] = '\0';

    // Convert the extracted middle digits to an integer
    int hashIndex = atoi(midDigits);

    // Ensure the index fits within the table size using modulo operation
    return hashIndex % TABLE_SIZE;
}

// Function to insert a key into the hash table
void insert(int hashTable[], int key) {
    int index = midSquareHash(key);

    // Linear probing in case of collision
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

// Function to display the hash table
void display(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1)
            printf("[%d] --> Empty\n", i);
        else
            printf("[%d] --> %d\n", i, hashTable[i]);
    }
}

int main() {
    int hashTable[TABLE_SIZE];

    // Initialize the hash table with -1 (indicating empty slots)
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    // Insert keys into the hash table
    int keys[] = {23, 45, 67, 89, 12, 56, 78};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(hashTable, keys[i]);
    }

    // Display the hash table
    display(hashTable);

    return 0;
}
