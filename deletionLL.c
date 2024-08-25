#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){

    //CREATION
    struct node *a;
    struct node *b;
    struct node *c;
    struct node *d;
    struct node *m;

    //allocate memory to each node
    a = (struct node*)malloc(sizeof(struct node));
    b = (struct node*)malloc(sizeof(struct node));
    c = (struct node*)malloc(sizeof(struct node));
    d = (struct node*)malloc(sizeof(struct node));
    m = (struct node*)malloc(sizeof(struct node));

    //provide data and link to next
    a -> data = 10;
    a -> next = b;

    b -> data = 20;
    b -> next = c;

    c -> data = 30;
    c -> next = d;

    d -> data = 40;
    d -> next = NULL;


    //deletion of node c 

    b -> next = d;
    free(c);

    //TRAVERSAL AND PRINT
    printf("Traversal and printing of linkedlist\n");
    struct node* current = a; 

    while(current != NULL){
        printf("%d\t",current -> data);
        current = current -> next;
    }


    return 0;
}