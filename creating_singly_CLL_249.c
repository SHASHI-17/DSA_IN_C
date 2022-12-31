#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* circular_singly(int data){
    node* temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=temp;
    return temp;
}



int main(){
    int data=34;
    node* tail=NULL;
    tail=circular_singly(data);
    printf("%d ",tail->data);
    return 0;
}