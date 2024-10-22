#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 10  // Size of the hash table
#define A 0.618033  // Constant A (commonly the fractional part of the golden ratio)

// Hash function using the multiplication method
int multiplicationHash(int key) {
    // Multiply the key by A and take the fractional part
    double fracPart = key * A - floor(key * A);

    // Multiply by table size and take the floor to get the hash index
    return (int)(floor(TABLE_SIZE * fracPart));
}

// Function to insert a key into the hash table
void insert(int hashTable[], int key) {
    int index = multiplicationHash(key);

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
    int keys[] = {123, 456, 789, 101, 212, 323};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(hashTable, keys[i]);
    }

    // Display the hash table
    display(hashTable);

    return 0;
}
