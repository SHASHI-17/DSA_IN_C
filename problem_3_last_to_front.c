#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node *move_to_front(node *head){
        node *p=head,*q=NULL;
    if(head==NULL || head->link==NULL){
        printf("list is empty \n");
    }
    else{
        while(p->link!=NULL){
            q=p;
            p=p->link;
        }
        q->link=NULL; 
        p->link=head;
        head=p;
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

    node *fourth=NULL;
    fourth=(node *)malloc(sizeof(node));
    fourth->data=4;
    fourth->link=NULL;

    first->link=second;
    second->link=third;
    third->link=fourth;

    node *head=first;
    head=move_to_front(head);

    while(head->link!=NULL){
        printf("%d ",head->data);
        head=head->link;
    }
    return 0;
}