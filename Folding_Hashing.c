#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10  // Size of the hash table

// Hash function using the folding method
int foldingHash(int key) {
    int sum = 0;

    // Break the key into parts and sum the digits
    while (key > 0) {
        sum += key % 100;  // Take two digits at a time
        key /= 100;
    }

    // Ensure the hash index fits within the table size
    return sum % TABLE_SIZE;
}

// Function to insert a key into the hash table
void insert(int hashTable[], int key) {
    int index = foldingHash(key);

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
    int keys[] = {1234, 5678, 91011, 2345, 6789};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(hashTable, keys[i]);
    }

    // Display the hash table
    display(hashTable);

    return 0;
}
