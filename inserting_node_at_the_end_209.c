#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

void counting_the_nodes(node *head){
    int count =0;
    if(head==NULL){
        printf("linked list is empty \n");
    }
   // node *ptr=NULL;
   // ptr=head;
    while(head!=NULL){
        count++;
        head=head->link;
    }
    printf("total nodes : %d\n",count);
}

void print_data(node *head){
    if(head==NULL){
        printf("linked list is empty \n");
    }
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->link;
    }
}

void adding_at_end(node *head,int data){
    node *temp=NULL;
    temp=(node *)malloc(sizeof(node));
    temp->data=data;
    (*temp).link=NULL;

    while(head->link!=NULL){ // TRAVERSING through loop we are taking head to the last
        head=head->link;
    }
    head->link=temp;
}

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

        adding_at_end(HEAD,67);
        counting_the_nodes(HEAD);
        print_data(HEAD);
    return 0;
}