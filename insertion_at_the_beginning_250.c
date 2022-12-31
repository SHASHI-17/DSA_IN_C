#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *addtoempty(int data){
    node *temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

node* add_at_beg(node* tail,int data){
    node* temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=tail->next;
    tail->next=temp;
    return tail;
}

void print(node *tail){
    node* p=tail->next;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=tail->next);
}

int main(){
    node* tail=NULL;
    tail=addtoempty(67);
    tail=add_at_beg(tail,78);
    print(tail);
    return 0;
}