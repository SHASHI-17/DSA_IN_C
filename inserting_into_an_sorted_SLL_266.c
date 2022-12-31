#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* add_to_empty(int data){
    node* temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

node* add_to_end(node * head,int data){
    node* new_node=(node *)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;

   node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    return head;
}

node* insert(node*head,int data){
        node* temp=NULL;
    node* new_node=(node *)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    int key=data;
    if(head==NULL || key<head->data){
        new_node->next=head;
        head=new_node;
        return head;
    }
    else{
        temp=head;
        while(temp->next!=NULL && temp->next->data<key){
            temp=temp->next;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
    return head;
}

void print(node* head){
    node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    node* HEAD=NULL;
    HEAD=add_to_empty(45);
    HEAD=add_to_end(HEAD,49);
    HEAD=add_to_end(HEAD,59);
    HEAD=add_to_end(HEAD,69);
    HEAD=add_to_end(HEAD,79);
    HEAD= insert(HEAD,70);
    print(HEAD);
     return 0;
}