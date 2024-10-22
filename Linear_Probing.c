#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10  // Size of the hash table

// Function to calculate the hash index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key using linear probing
void insert(int hashTable[], int key) {
    int index = hashFunction(key);  // Compute the hash index

    // Find the next available slot if there's a collision
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;  // Move to the next slot (wrap around)
    }
    hashTable[index] = key;  // Place the key in the found slot
}

// Function to search for a key in the hash table
int search(int hashTable[], int key) {
    int index = hashFunction(key);  // Compute the hash index

    // Search for the key using linear probing
    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;  // Key found, return the index
        index = (index + 1) % TABLE_SIZE;  // Move to the next slot (wrap around)
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
