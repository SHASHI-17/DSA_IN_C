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

node *add_after_position(node *head,int data,int position){
    node *temp=NULL,*temp2=NULL,*new_node=NULL;

    new_node=addToEmpty(new_node,data);

    temp=head;
    while(position!=1){
        position--;
        temp=temp->next;
    }
    if(temp->next==NULL){
        temp->next=new_node;
        new_node->prev=temp;
    }
    else{
    temp2=temp->next;
    temp->next=new_node;
    temp2->prev=new_node;
    new_node->prev=temp;
    new_node->next=temp2;
    }
    return head;
}

int main(){
    node *head=NULL;
    node* ptr=head;
    head=addToEmpty(head,45);
    head=add_at_end(head,69);
    head=add_at_end(head,78);
    head=add_after_position(head,67,2);
    ptr=head;

    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}