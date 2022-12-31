#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node * add_at_end(node *head,int data){  // its a pointer so it will return address
    node *temp=NULL;
    temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->link=NULL;

    head->link=temp; // main line 
    return temp;
}

int main(){
    node *HEAD=NULL;
    HEAD=(node *)malloc(sizeof(node));
    HEAD->data=1;
    HEAD->link=NULL;
    
    node *ptr=HEAD;
    ptr=add_at_end(ptr,2);
    ptr=add_at_end(ptr,3);
    ptr=add_at_end(ptr,4);

    ptr=HEAD; // for printing the linked list we will bring back to the first node

    while(ptr!=NULL){ //TRAVERSING to print
        printf("%d ",ptr->data);
        ptr=ptr->link; // 1st node will having the address of second node
    }
    return 0;
}