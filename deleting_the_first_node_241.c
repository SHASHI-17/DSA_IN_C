#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node;

node* addToEmpty(node *head,int data){
    node* temp=malloc(sizeof(node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}


node *add_at_end(node *head,int data){
    node* temp,*traverse;
    temp=(node *)malloc(sizeof(node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    traverse=head;
    while(traverse->next!=NULL){
        traverse=traverse->next;
    }
    traverse->next=temp;
    temp->prev=traverse;
    return head;
}

node *del_first_node(node * head){
    // head=head->next;
    // free(head->prev);
    // head->prev=NULL;
    node *temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    head->prev=NULL;
}

int main(){
    node *head=NULL;
    node *ptr;

    head=addToEmpty(head,56);
    head=add_at_end(head,78);
    head=add_at_end(head,789);
    head=del_first_node(head);

    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}