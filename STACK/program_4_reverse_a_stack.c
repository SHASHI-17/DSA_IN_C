#include<stdio.h>
#include<stdlib.h>
int value;
typedef struct node
{
    int data ;
    struct node *link;
}node;

int isempty(node* top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

node* push(int data,node* top){
    node* new_node=malloc(sizeof(node));
    new_node->data=data;
    new_node->link=NULL;

    if(new_node==NULL){
        printf("stack overflow");
    }
    new_node->link=top;
    top=new_node;
    return top;
}

node* pop(node* top){
    if(isempty(top)){
        printf("stack underflow ");
        exit(23);
    }
    else{
        node* temp=top;
        top=top->link;
        value=temp->data;
        free(temp);
        temp=NULL;
        return top;
    }
}

void print(node* top){
    if(isempty(top)){
        printf("stack underflow ");
        exit(1);
    }
    else{
        node*temp=top;
        while(temp){
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

void change_val(int **ptr){
    int val2=85;
    *ptr=&val2;
}

int main(){
    node* top1=NULL;
    node* top2=NULL;
    node* top3=NULL;

    top1=push(1,top1);
    top1=push(2,top1);
    top1=push(3,top1);
    print(top1);

    top1=pop(top1);
    top2=push(value,top2);

    top1=pop(top1);
    top2=push(value,top2);

    top1=pop(top1);
    top2=push(value,top2);

    print(top2);

    int val=45;
    int *ptr=&val;

    printf("%d\n",*ptr);

    change_val(&ptr);
    printf("%d",*ptr);
    return 0;
}