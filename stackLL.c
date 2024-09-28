#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char data;
    struct Node* next;
};


void push(struct Node** top_ref, char value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Stack Overflow\n");
        return;
    }
    new_node->data = value;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}


char pop(struct Node** top_ref) {
    char value;
    struct Node* top;

    if (*top_ref == NULL) {
        printf("Stack Underflow\n");
        return '\0';
    }
    else {
        top = *top_ref;
        value = top->data;
        *top_ref = top->next;
        free(top);
        return value;
    }
}


void reverseLinkedList(struct Node** head_ref) {
    struct Node* stack = NULL;
    struct Node* current = *head_ref;
    
    while (current != NULL) {
        push(&stack, current->data);
        current = current->next;
    }
    
    current = *head_ref;
    while (stack != NULL) {
        current->data = pop(&stack);
        current = current->next;
    }
}

struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%c -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = newNode('I');
    head->next = newNode('S');
    head->next->next = newNode('R');
    head->next->next->next = newNode('O');

    printf("Original Linked List: ");
    printList(head);

    reverseLinkedList(&head);

    printf("Reversed Linked List: ");
    printList(head);

    return 0;
}