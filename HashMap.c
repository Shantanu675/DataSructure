#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node for chaining
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Hash Table for Chaining
typedef struct {
    Node* buckets[TABLE_SIZE];
} HashTableChaining;

// Hash Table for Open Addressing
typedef struct {
    int keys[TABLE_SIZE];
    int occupied[TABLE_SIZE]; // 0: empty, 1: occupied, -1: deleted
} HashTableOpenAddressing;

// Hash Function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// ============================ Chaining ============================
void initHashTableChaining(HashTableChaining* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
}

void insertChaining(HashTableChaining* table, int key) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}

int searchChaining(HashTableChaining* table, int key) {
    int index = hashFunction(key);
    Node* current = table->buckets[index];
    while (current) {
        if (current->key == key) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

void deleteChaining(HashTableChaining* table, int key) {
    int index = hashFunction(key);
    Node* current = table->buckets[index];
    Node* prev = NULL;

    while (current) {
        if (current->key == key) {
            if (prev) {
                prev->next = current->next;
            } else {
                table->buckets[index] = current->next;
            }
            free(current);
            printf("Key %d deleted.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Key %d not found.\n", key);
}

void displayChaining(HashTableChaining* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* current = table->buckets[i];
        while (current) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// ============================ Open Addressing ============================
void initHashTableOpenAddressing(HashTableOpenAddressing* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->keys[i] = 0;
        table->occupied[i] = 0;
    }
}

void insertOpenAddressing(HashTableOpenAddressing* table, int key) {
    int index = hashFunction(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int probeIndex = (index + i) % TABLE_SIZE;
        if (table->occupied[probeIndex] == 0 || table->occupied[probeIndex] == -1) {
            table->keys[probeIndex] = key;
            table->occupied[probeIndex] = 1;
            return;
        }
    }
    printf("Hash table is full!\n");
}

int searchOpenAddressing(HashTableOpenAddressing* table, int key) {
    int index = hashFunction(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int probeIndex = (index + i) % TABLE_SIZE;
        if (table->occupied[probeIndex] == 0) {
            return 0; // Not found
        }
        if (table->occupied[probeIndex] == 1 && table->keys[probeIndex] == key) {
            return 1; // Found
        }
    }
    return 0; // Not found
}

void deleteOpenAddressing(HashTableOpenAddressing* table, int key) {
    int index = hashFunction(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int probeIndex = (index + i) % TABLE_SIZE;
        if (table->occupied[probeIndex] == 0) {
            printf("Key %d not found.\n", key);
            return;
        }
        if (table->occupied[probeIndex] == 1 && table->keys[probeIndex] == key) {
            table->occupied[probeIndex] = -1; // Mark as deleted
            printf("Key %d deleted.\n", key);
            return;
        }
    }
    printf("Key %d not found.\n", key);
}

void displayOpenAddressing(HashTableOpenAddressing* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->occupied[i] == 1) {
            printf("Index %d: %d\n", i, table->keys[i]);
        } else if (table->occupied[i] == -1) {
            printf("Index %d: DELETED\n", i);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
}

// ============================ Main Function ============================
int main() {
    int choice, key;
    HashTableChaining tableChaining;
    HashTableOpenAddressing tableOpenAddressing;

    initHashTableChaining(&tableChaining);
    initHashTableOpenAddressing(&tableOpenAddressing);

    while (1) {
        printf("\nChoose operation:\n");
        printf("1. Insert (Chaining)\n");
        printf("2. Search (Chaining)\n");
        printf("3. Delete (Chaining)\n");
        printf("4. Display (Chaining)\n");
        printf("5. Insert (Open Addressing)\n");
        printf("6. Search (Open Addressing)\n");
        printf("7. Delete (Open Addressing)\n");
        printf("8. Display (Open Addressing)\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert (Chaining): ");
                scanf("%d", &key);
                insertChaining(&tableChaining, key);
                break;
            case 2:
                printf("Enter key to search (Chaining): ");
                scanf("%d", &key);
                if (searchChaining(&tableChaining, key)) {
                    printf("Key %d found.\n", key);
                } else {
                    printf("Key %d not found.\n", key);
                }
                break;
            case 3:
                printf("Enter key to delete (Chaining): ");
                scanf("%d", &key);
                deleteChaining(&tableChaining, key);
                break;
            case 4:
                displayChaining(&tableChaining);
                break;
            case 5:
                printf("Enter key to insert (Open Addressing): ");
                scanf("%d", &key);
                insertOpenAddressing(&tableOpenAddressing, key);
                break;
            case 6:
                printf("Enter key to search (Open Addressing): ");
                scanf("%d", &key);
                if (searchOpenAddressing(&tableOpenAddressing, key)) {
                    printf("Key %d found.\n", key);
                } else {
                    printf("Key %d not found.\n", key);
                }
                break;
            case 7:
                printf("Enter key to delete (Open Addressing): ");
                scanf("%d", &key);
                deleteOpenAddressing(&tableOpenAddressing, key);
                break;
            case 8:
                displayOpenAddressing(&tableOpenAddressing);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}