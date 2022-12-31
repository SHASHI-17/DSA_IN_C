#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node *del_list(node *head){
    node *temp=head;
    while (temp!=NULL)
    {
        temp=temp->link;
        free(head);
        head=temp;
    }
    return head;
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
    head=del_list(head);
    if(head==NULL){
        printf("list deleted successfully ");
    }
    return 0;
}