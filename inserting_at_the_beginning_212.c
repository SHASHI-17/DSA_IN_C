#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}node;

node * add_beg(node *head,int data){
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->link=NULL;

    ptr->link=head;
    head=ptr;
    return head;
}

int main(){
    node *HEAD=(node *)malloc(sizeof(node));
    HEAD->data=34;
    (*HEAD).link=NULL;

    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=74;
    (*ptr).link=NULL;

    HEAD->link=ptr;

    HEAD=add_beg(HEAD,66);

    ptr=HEAD;// to point to 1st node
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

    return 0;
}