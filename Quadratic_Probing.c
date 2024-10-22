#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10  // Size of the hash table

// Hash function to compute the initial index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key using quadratic probing
void insert(int hashTable[], int key) {
    int index = hashFunction(key);  // Compute the initial index
    int i = 1;  // Attempt number

    // Use quadratic probing in case of collision
    while (hashTable[index] != -1) {
        index = (index + i * i) % TABLE_SIZE;  // Quadratic probing
        i++;  // Increment the attempt number
    }
    hashTable[index] = key;  // Insert the key
}

// Function to search for a key using quadratic probing
int search(int hashTable[], int key) {
    int index = hashFunction(key);  // Compute the initial index
    int i = 1;  // Attempt number

    // Search for the key using quadratic probing
    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;  // Key found, return the index
        index = (index + i * i) % TABLE_SIZE;  // Quadratic probing
        i++;  // Increment the attempt number
    }
    return -1;  // Key not found
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
    int keys[] = {23, 43, 13, 27, 51, 37, 18};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(hashTable, keys[i]);
    }

    // Display the hash table
    display(hashTable);

    // Search for a key
    int keyToSearch = 37;
    int index = search(hashTable, keyToSearch);
    if (index != -1)
        printf("Key %d found at index %d\n", keyToSearch, index);
    else
        printf("Key %d not found\n", keyToSearch);

    return 0;
}
