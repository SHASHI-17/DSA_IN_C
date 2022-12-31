#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

int main(){
    node *Head=NULL;
    Head=(node *) malloc(sizeof(node));
    (*Head).data=45;
    Head->link=NULL;

    printf("%d ",(*Head).data);
    return 0;
}