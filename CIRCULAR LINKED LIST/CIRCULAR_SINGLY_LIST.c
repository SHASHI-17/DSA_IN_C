#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* add_to_empty(int data){
    node* new_node=malloc(sizeof(node));
    new_node->data=data;
    new_node->next=new_node;
    return new_node;
}

void print(node* tail){
    if(tail==NULL){
        printf("empty list ");
    }
    else{
        node* temp=tail->next;
        do{
            printf("%d ->",temp->data);
            temp=temp->next;
        }while(temp!=tail);
        printf(" %d",temp->data);
    }
    printf("\n");
}

node* add_at_beg(node* tail,int data){
    node* new_node=add_to_empty(data);

    new_node->next=tail->next;
    tail->next=new_node;
    return tail;
}

node* add_at_end(node* tail,int data){
    node* new_node=add_to_empty(data);

    new_node->next=tail->next;
    tail->next=new_node;
    tail=new_node;
    return tail;
}

node* add_after_position(node* tail,int data,int position){
    node* new_node=add_to_empty(data);
    node* temp=tail->next;
    for(int i=1;i<position;i++){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    if(temp==tail){
        tail=tail->next;
    }
    return tail;
}

node*  add_before_position(node * tail,int data,int position){
    node* new_node=add_to_empty(data);

    node* temp=tail->next;
    if(position==1){
        new_node->next=temp;
        tail->next=new_node;
    }
else{
        position--;
    for(int i=1;i<position;i++){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    if(temp==tail){
        tail=tail->next;
    }
}
    return tail;
}

node* del_first(node* tail){
    if(tail==NULL){
        printf("list is empty");
    }
    if(tail==tail->next){
        free(tail);
        tail=NULL;
    }
    else{
    node* temp=tail->next;
        tail->next=temp->next;
        free(temp);
        temp=NULL;
        return tail;
    }
}

node* del_at_position(node * tail,int position){
        if(tail==NULL){
        printf("list is empty");
    }
    if(tail==tail->next){
        free(tail);
        tail=NULL;
    }
    else{
        node* temp=tail->next;
        for(int i=1;i<position;i++){
            temp=temp->next;
        }
        node* temp2=temp->next;
        temp->next=temp2->next;
        if(temp2==tail){
            tail=temp;
        }
        free(temp2);
        temp2=NULL;
    }
        return tail;
}

node* del_last(node* tail){
        if(tail==NULL){
        printf("list is empty");
    }
    if(tail==tail->next){
        free(tail);
        tail=NULL;
    }
    else{
        node* temp=tail->next;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=tail->next;
        free(tail);
        tail=temp;
        temp=NULL;
    }
    return tail;
}

int main(){
    node* head=add_to_empty(78);
    head=add_at_beg(head,56);
    head=add_at_end(head,67);
    head=add_after_position(head,90,1);
    head=add_before_position(head,43,2);
    print(head);
   // head=del_first(head);
    // head=del_last(head);
    //head=del_at_position(head,1);
    head=reverse(head);
    print(head);
    return 0;
}