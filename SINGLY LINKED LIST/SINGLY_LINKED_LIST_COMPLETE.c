#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node;

node* add_to_empty(int data){
    node* temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->link=NULL;
    return temp;
}

node* add_at_beg(node* head,int data){
    node* new_node=malloc(sizeof(node));
    new_node->data=data;
    new_node->link=NULL;

    new_node->link=head;
    head=new_node;
    return head;
}

void print(node* head){
    if(head==NULL){
        printf("empty list ");
    }
    else{
        node* temp=head;
        while(temp->link!=NULL){
            printf("%d ->",temp->data);
            temp=temp->link;
        }
        printf(" %d",temp->data);
    }
    printf("\n");
}

node* add_at_end(node* head,int data){
    node* new_node=malloc(sizeof(node));
    new_node->data=data;
    new_node->link=NULL;

    node* temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=new_node;
    return head;
}

node* add_after_pos(node* head,int data,int position){
    node* new_node=add_to_empty(data);

    node* temp=head;
    for(int i=1;i<position;i++){
        temp=temp->link;
    }
    new_node->link=temp->link;
    temp->link=new_node;
    return head;
}

node* add_before_position(node* head,int data,int position){
    node* new_node=add_to_empty(data);

    node* temp=head;
    if(position==1){
        new_node->link=head;
        head=new_node;
        return head;
    }
    position--;
    for(int i=1;i<position;i++){
        temp=temp->link;
    }
    new_node->link=temp->link;
    temp->link=new_node;
    return head;
}


node* reverse(node * head){
    if(head==NULL){
        printf("no list");
    }
    node* current=NULL;
    node* next=head->link;
    head->link=NULL;

    while(next!=NULL){
        current=next;
        next=next->link;
        current->link=head;
        head=current;
    }
    return head;
}

node* del_first(node* head){
    if(head==NULL){
        printf("list is empty");
    }
    node* temp=head;
    head=head->link;
    free(temp);
    temp=NULL;
    return head;
}

node* del_end(node*head){
        if(head==NULL){
        printf("list is empty");
    }
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
    node* temp=head;
    while(temp->link->link!=NULL){
        temp=temp->link;
    }
    free(temp->link->link);
    temp->link=NULL;
    return head;
    }
}

node* del_inter(node* head,int position){
    node* temp=head;
    node* previous=NULL;
        if(head==NULL){
        printf("list is empty");
    }
    else if(position==1 ){
        head=head->link;
        free(temp);
        temp=NULL;
    }
    else{
    for(int i=1;i<position;i++){
        previous=temp;// it will stop before the node
        temp=temp->link;
    }
    previous->link=temp->link;
    free(temp);
    temp=NULL;
    return head;
    }
}

node* del_entire(node* head){
while(head!=NULL){
    head->link=NULL;
    head=head->link;
}
}

int main(){
    node* head=NULL;
    head=add_to_empty(56);
    head=add_at_beg(head,67);
    head=add_at_beg(head,17);
   // head=add_at_end(head,86);
    //head=add_at_end(head,92);
    //head=add_after_pos(head,23,1);
    //head=add_before_position(head,67,2);
   // printf("before reverse \n");
    print(head);
   // printf("after reverse \n");
    //head=reverse(head);
   // print(head);
    //head=del_first(head);
    //head=del_end(head);
   // head=del_inter(head,2);
   //head=del_entire(head);
    print(head);
    return 0;
}