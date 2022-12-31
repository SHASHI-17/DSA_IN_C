#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node;

node* addToEmpty(node *head,int data){
    node* temp=malloc(sizeof(node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}


node *add_at_end(node *head,int data){
    node* temp,*traverse;
    temp=(node *)malloc(sizeof(node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    traverse=head;
    while(traverse->next!=NULL){
        traverse=traverse->next;
    }
    traverse->next=temp;
    temp->prev=traverse;
    return head;
}

node* create_list(node* head){
    int size,data;
    printf("enter the number of nodes \n");
    scanf("%d",&size);
    if(size==0){
        return 0;
    }
        printf("enter the element for the node 1 \n");
        scanf("%d",&data);
        head=addToEmpty(head,data);
        for(int i=1;i<size;i++){
        printf("enter the element for the node %d \n",i+1);
        scanf("%d",&data);
        head=add_at_end(head,data);
        }
    
    return head;
}

int main(){
    node *head=NULL,*ptr;
    head=create_list(head);
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}