#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node *reverse(node *head){
    node *temp=NULL;
    node *temp2=NULL;
    while(head!=NULL){
        temp2=head->link;
        head->link=temp;
        temp=head;
        head=temp2;
    }
    return temp;
}

int main(){
    node *first=NULL;
    first=(node *)malloc(sizeof(node));
    first->data=1;
    first->link=NULL;

    node *second=NULL;
    second=(node *)malloc(sizeof(node));
    second->data=2;
    second->link=NULL;

    node *third=NULL;
    third=(node *)malloc(sizeof(node));
    third->data=3;
    third->link=NULL;

    first->link=second;
    second->link=third;

    node *head=first;

    head=reverse(head);
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->link;
    }
    return 0;
}