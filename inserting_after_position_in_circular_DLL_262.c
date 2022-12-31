#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;

}node;

node* add_to_empty(int data){
    node* temp=(node *)malloc(sizeof(node));
    temp->prev=temp;
    temp->data=data;
    temp->next=temp;
    return temp;
}

void print(node* tail){
    if(tail==NULL){
        printf("list is empty \n");
    }
    else{
        node*temp=tail->next;
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=tail->next);
    }
    printf("\n");
}

node* add_at_beg(node* tail,int data){
    node* new_node=add_to_empty(data);
    if(tail==NULL){
        return new_node;
    }
    else{
        node* temp=tail->next;
        new_node->next=temp;
        new_node->prev=tail;
        temp->prev=new_node;
        temp->next=new_node;
        return tail;
    }
}

node* add_at_end(node* tail,int data){
    if(tail==NULL){
        printf("list is empty \n");
    }
    else{
        node* temp=tail->next;
        node* new_node=add_to_empty(data);
        new_node->next=temp;
        new_node->prev=tail;
        tail->next=new_node;
        temp->prev=new_node;
        tail=new_node;
        return tail;
    }
}

node* add_at_position(node* tail,int position,int data){
    if(tail==NULL){
        printf("list is empty \n");
        return tail;
    }
    else{
        node* temp=tail->next;
        while(position>1){
            position--;
            temp=temp->next;
        }
        node* new_node=add_to_empty(data);
        new_node->prev=temp;
        new_node->next=temp->next;
        temp->next->prev=new_node;
        temp->next=new_node;
        if(temp==tail){
            tail=tail->next;// moving tail pointer to the end
        }
        return tail;
    }
}

int main(){
    node* tail=NULL;
    tail=add_to_empty(67);
    tail=add_at_beg(tail,78);
    tail=add_at_end(tail,89);
    tail=add_at_position(tail,1,98);
    print(tail);
    return 0;
}