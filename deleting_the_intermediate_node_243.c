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

void print(node *head){
    node * ptr=head;
        while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
        printf("\n");
}

node *del_first_node(node * head){
    // head=head->next;
    // free(head->prev);
    // head->prev=NULL;
    node *temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    head->prev=NULL;
}

node *del_the_last_node(node* head){
    node* temp=head;
    // while(temp->next->next!=NULL){
    //     temp=temp->next;
    // }
    // free(temp->next);
    // temp->next=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    temp=NULL;
    return head;
}

node* del_inter(node* head,int position){
    node* temp=head,*temp2=NULL;
    if(position==1){
        head=del_first_node(head);
    }
    while(position>1){
        temp=temp->next;
        position--;
    }
    if(temp->next==NULL){
        head=del_the_last_node(head);
    }
    else{
    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    temp=NULL;
    }
    return head;
}

int main(){
     node *head=NULL;

    head=addToEmpty(head,56);
    head=add_at_end(head,78);
    head=add_at_end(head,789);

    print(head);
   head=del_inter(head,3);
    print(head);
    return 0;
}