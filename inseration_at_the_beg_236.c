#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node;

node* add_at_beg(node *head,int data){
    node* temp=(node *)malloc(sizeof(node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}

node* addToEmpty(node *head,int data){
    node* temp=malloc(sizeof(node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}


int main(){
    node *head=NULL;
    head=addToEmpty(head,45);
    head=add_at_beg(head,69);
    node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}