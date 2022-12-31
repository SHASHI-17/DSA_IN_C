#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

int main(){
    node *HEAD=NULL;
    HEAD=(node *)malloc(sizeof(node)); // first node
    (*HEAD).data=45;
    HEAD->link=NULL;

    node *current=NULL; 
    current=(node *)malloc(sizeof(node)); // second node
    (*current).data=69;
    current->link=NULL;

    HEAD->link=current;

    current=(node *)malloc(sizeof(node));// third node without making another pointer/updating the current node
    (*current).data=79;
    current->link=NULL;

        HEAD->link->link=current;
    return 0;
}