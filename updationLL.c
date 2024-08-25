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

    //allocate memory to each node
    a = (struct node*)malloc(sizeof(struct node));
    b = (struct node*)malloc(sizeof(struct node));
    c = (struct node*)malloc(sizeof(struct node));
    d = (struct node*)malloc(sizeof(struct node));
   

    //provide data and link to next
    a -> data = 10;
    a -> next = b;

    b -> data = 20;
    b -> next = c;

    c -> data = 30;
    c -> next = d;

    d -> data = 40;
    d -> next = NULL;

    //TRAVERSAL AND PRINT
    printf("Traversal and printing of linkedlist\n");
    struct node* current = a; 

    while(current != NULL){
        printf("%d\t",current -> data);
        current = current -> next;
    }
    printf("\n***********************************************\n");
    
    //UPDATE
    printf("Updation and printing of linkedlist\n");
    int fData, newData;

    printf("Enter which data you want change : ");
    scanf("%d",&fData);
    printf("Enter new data : ");
    scanf("%d",&newData);

    current = a;
    while(current -> data != fData){
        current = current -> next;
        break;
    }

    current -> data = newData;

    current = a;
    while(current != NULL){
        printf("%d\t",current -> data);
        current = current -> next;
    }

    return 0;
}