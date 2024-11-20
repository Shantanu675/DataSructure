#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Enqueue operation
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add %d.\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0; // Initialize front when first element is added
    }
    q->items[++q->rear] = value;
    printf("Added %d to the queue.\n", value);
}

// Dequeue operation
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot delete.\n");
        return;
    }
    printf("Deleted %d from the queue.\n", q->items[q->front]);
    if (q->front == q->rear) {
        // Queue becomes empty after this operation
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

// Print the queue
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Queue q;
    int choice, value;

    initQueue(&q);

    while (1) {
        printf("\nQueue Operations:\n");
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