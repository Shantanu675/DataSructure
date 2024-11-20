#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // Maximum size of the circular queue

typedef struct CircularQueue {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

// Initialize the circular queue
void initQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(CircularQueue* q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(CircularQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Enqueue operation
void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add %d.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Initialize front for the first element
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Added %d to the queue.\n", value);
}

// Dequeue operation
void dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot delete.\n");
        return;
    }
    printf("Deleted %d from the queue.\n", q->items[q->front]);
    if (q->front == q->rear) {
        // Queue becomes empty after this operation
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

// Print the queue
void printQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    do {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    } while (i != (q->rear + 1) % MAX);
    printf("\n");
}

// Main function
int main() {
    CircularQueue q;
    int choice, value;

    initQueue(&q);

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Add (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}