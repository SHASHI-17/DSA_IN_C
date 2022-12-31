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

void print(node *head){
    node * ptr=head;
        while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
        printf("\n");
}

node *reverse_DLL(node* head){
    node* temp=head;
    node* temp2=temp->next;
    temp->next=NULL;
    temp->prev=temp2;

    while(temp2!=NULL){
    temp2->prev=temp2->next;
    temp2->next=temp;
    temp=temp2;
    temp2=temp->prev;
    }
    head=temp;
    return head;
}
int main(){
    node *head=NULL;
    node *ptr;

    head=addToEmpty(head,56);
    head=add_at_end(head,78);
    head=add_at_end(head,789);
    head=add_at_end(head,85);

    print(head);
    head=reverse_DLL(head);
    print(head);

    return 0;
}