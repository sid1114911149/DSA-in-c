#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    char* question;
    bool answer;
    struct Node* yes;
    struct Node* no;
} Node;

Node* createNode(char* question, bool answer) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->question = question;
    newNode->answer = answer;
    newNode->yes = NULL;
    newNode->no = NULL;
    return newNode;
}

void traverseTree(Node* root) {
    if (root == NULL) {
        return;
    }
    
    if (root->question != NULL) {
        char response;
        printf("%s (y/n): ", root->question);
        scanf(" %c", &response);
        
        if (response == 'y' || response == 'Y') {
            traverseTree(root->yes);
        } else if (response == 'n' || response == 'N') {
            traverseTree(root->no);
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
            traverseTree(root);
        }
    } else {
        printf("Decision: %s\n", root->question);
    }
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->yes);
    freeTree(root->no);
    free(root);
}

int main() {
    Node* root = createNode("are you a male?", false);
    root->yes = createNode("are you an adult?", false);
    root->yes->yes = createNode("are you in graduation?", true);
    root->yes->no = createNode("are you in school?", true);
    root->no = createNode("are you an adult?", false);
    root->no->yes = createNode("do you like jwellery?", true);
    root->no->no = createNode("do you like toys?", true);
    
    traverseTree(root);

    freeTree(root);

    return 0;
}

