#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node;

node* circular_doubly(int data){
    node* temp=(node *)malloc(sizeof(node));
    temp->prev=temp;
    temp->data=data;
    temp->next=temp;
    return temp;
}

int main(){
    int data=34;
    node* tail=NULL;
    tail=circular_doubly(data);
    printf("%d ",tail->data);
    return 0;
}