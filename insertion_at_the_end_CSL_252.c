#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node * add_to_empty(int data){
    node* temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=temp;
}

node* add_at_beg(node* tail,int data){
    node* temp=malloc(sizeof(node));
    temp->data=data;
    temp->next=tail->next;
    tail->next=temp;
    return tail;
}

node* add_at_end(node* tail,int data){
    node* new_node=(node *)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULL;
    new_node->next=tail->next;
    tail->next=new_node;
    tail=tail->next;
    return tail;
}

void print(node* tail){
    node* p=tail->next;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=tail->next);
}

int main(){
    node* tail=NULL;
    tail=add_to_empty(56);
    tail=add_at_beg(tail,67);
    tail=add_at_end(tail,78);
    print(tail);
    return 0;
}