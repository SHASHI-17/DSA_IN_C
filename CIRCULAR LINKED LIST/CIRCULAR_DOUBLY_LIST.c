#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

node* add_to_empty(int data){
    node* new_node=malloc(sizeof(node));
    new_node->prev=new_node;
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
    if(tail==NULL){
        printf("list is empty");
    }
    else{
    node* new_node=add_to_empty(data);

    node* temp=tail->next;
    new_node->prev=tail;
    new_node->next=temp;
    tail->prev=new_node;
    tail->next=new_node;
    return tail;
    }
}

node* add_at_end(node* tail,int data){
        if(tail==NULL){
        printf("list is empty");
    }
    else{
    node* new_node=add_to_empty(data);

    // new_node->next=tail->next;
    // new_node->prev=tail;
    // tail->next=new_node;
    // tail=new_node;
    node* temp=tail->next;
    new_node->next=temp;
    new_node->prev=tail;
    tail->next=new_node;
    temp->prev=new_node;
    tail=new_node;

    return tail;
}
}

node* add_after_position(node* tail,int data,int position){
        if(tail==NULL){
        printf("list is empty");
    }
    else{
        node* new_node=add_to_empty(data);
        node* temp=tail->next;
        for(int i=1;i<position;i++){
            temp=temp->next;
        }
        new_node->next=temp->next;
        new_node->prev=temp;
        temp->next->prev=new_node;
        temp->next=new_node;
            if(temp==tail){
                tail=tail->next;
            }
    }
    return tail;
}

node* add_before_position(node* tail,int data,int position){
    if(tail==NULL){
        printf("list is empty");
    }
    node* new_node=add_to_empty(data);
        node* temp=tail->next;
        if(position==1){
            new_node->next=temp;
            new_node->prev=tail;
            tail->next=new_node;
            temp->prev=new_node;
        }
        else{
        position--;
        for(int i=1;i<position;i++){
            temp=temp->next;
        }
        new_node->next=temp->next;
        new_node->prev=temp;
        temp->next->prev=new_node;
        temp->next=new_node;
        if(temp==tail){
            tail=tail->next;
        }
    }
    return tail;
}


node* del_first(node* tail){
    node* temp=tail->next;
    if(temp==tail){
        free(tail);
        tail=NULL;
    }
    else{
        tail->next=temp->next;
        temp=temp->next;
        free(temp->prev);
        temp->prev=tail;
    }
    return tail;
}

node* del_last(node* tail){
    if(tail==tail->next){
        free(tail);
        tail=NULL;
    }
    else{
        node* temp=tail->prev;
        temp->next=tail->next;
        tail->next->prev=temp;
        free(tail);
        tail=temp;
    }
    return tail;
}

node* del_at_position(node* tail,int position){
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
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    if(temp==tail){
        tail=tail->prev;
    }
    free(temp);
    temp=NULL;
    }
    return tail;
}

int main(){
    node* tail=add_to_empty(56);
    tail=add_at_beg(tail,78);
    tail=add_at_end(tail,43);
    tail=add_after_position(tail,54,3);
    tail=add_before_position(tail,32,1);
    print(tail);
    //tail=del_first(tail);
    //tail=del_last(tail);
    tail=del_at_position(tail,5);
    print(tail);
    return 0;
}