#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node * del_at_pos(node *head,int position){
    node *current =head;
    node *previous =head;
    if(head==NULL){
        printf("linked list is empty \n");
    }
    else if(position==1){
        head=current->link; //assidgning the address of 2nd node
        free(current);
        current=NULL;
    }
    else{
        while(position!=1){
            previous=current;// this is required for deleting the third node
            current=current->link;
            position--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
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
    head=del_at_pos(head,3);
    node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}