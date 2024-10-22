#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10      // Size of the hash table
#define PRIME_SIZE 7       // A prime number smaller than TABLE_SIZE

// First hash function
int hash1(int key) {
    return key % TABLE_SIZE;
}

// Second hash function
int hash2(int key) {
    return PRIME_SIZE - (key % PRIME_SIZE);
}

// Function to insert a key using double hashing
void insert(int hashTable[], int key) {
    int index = hash1(key);  // Compute the initial index

    // Use double hashing if there's a collision
    int i = 0;  // Attempt number
    while (hashTable[(index + i * hash2(key)) % TABLE_SIZE] != -1) {
        i++;  // Increment the attempt number
    }

    // Insert the key in the found slot
    hashTable[(index + i * hash2(key)) % TABLE_SIZE] = key;
}

// Function to search for a key using double hashing
int search(int hashTable[], int key) {
    int index = hash1(key);  // Compute the initial index

    // Search for the key using double hashing
    int i = 0;
    while (hashTable[(index + i * hash2(key)) % TABLE_SIZE] != -1) {
        if (hashTable[(index + i * hash2(key)) % TABLE_SIZE] == key)
            return (index + i * hash2(key)) % TABLE_SIZE;  // Key found
        i++;
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
