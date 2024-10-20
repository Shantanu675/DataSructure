#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void create(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void traverse() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

void insert_beg(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insert_end(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void delete_beg() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = last->next;
    if (last->next == last) {
        last = NULL;
    } else {
        last->next = temp->next;
    }
    free(temp);
}

void delete_end() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = last->next;
    if (last->next == last) {
        free(last);
        last = NULL;
    } else {
        while (temp->next != last)
            temp = temp->next;
        temp->next = last->next;
        free(last);
        last = temp;
    }
}

int main() {
    int choice, value;
    while(1) {
        printf("\n1. Create\n2. Traverse\n3. Insert at Beginning\n4. Insert at End\n5. Delete from Beginning\n6. Delete from End\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                create(value);
                break;
            case 2:
                traverse();
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_beg(value);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_end(value);
                break;
            case 5:
                delete_beg();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}