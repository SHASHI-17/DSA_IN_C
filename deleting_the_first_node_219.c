#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *link;
}node;

node *del_first(node *head){
    if(head==NULL){
        printf("list is empty \n");
    }
    else{
        node *ptr=head;
        head=head->link;
        free(ptr);
        ptr=NULL;
    }
        return head;
}

int main(){
    node *first=NULL;
    first=(node *)malloc(sizeof(node));
    first->data=56;
    first->link=NULL;
    node *second=NULL;
    second=(node *)malloc(sizeof(node));
    second->data=565;
    second->link=NULL;

    node *third=NULL;
    third=(node *)malloc(sizeof(node));
    third->data=562;
    third->link=NULL;

    first->link=second;
    second->link=third;

    node *head=first;
    head=del_first(head);
    node *ptr=head;

while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->link;
}
    

    return 0;
}