#include<stdio.h>
#include<stdlib.h>

 struct node{
    int data;
    struct node* link;
} *top=NULL;

int isEmpty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int peek(){
    if(isEmpty()){
        printf("stack underflow ");
    }
    else{
        return top->data;
    }
}

void push(int data){
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=NULL;

    if(newnode==NULL){
        printf("stack overflow");
        exit(1);
    }
    newnode->link=top;
    top=newnode;
}

int pop(){
    struct node* temp=top;
    if(isEmpty()){
        printf("stack underflow ");
        exit(1);
    }
    else{
        top=top->link;
        int value =temp->data;
        free(temp);
        temp=NULL;
        return value;
    }
}

void print(){
struct node* temp=top;
if(isEmpty()){
    printf("stack underflow \n");
    exit(1);
}
while(temp){
    printf("%d ",temp->data);
    temp=temp->link;
}
printf("\n");
}

int main(){
    int data,choice;
    while(1){
        printf("\n1.push\n2.pop\n3.peek\n4.print\n5.exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice){

            case 1:
            printf("enter the element that you want to push\n");
            scanf("%d",&data);
            push(data);
            break;

            case 2 :
            printf("the deleted the element is %d",pop());
            break;

            case 3 :
            printf("the toppest element is %d",peek());
            break;

            case 4:
            print();
            break;
            
            case 5:
            exit(1);
            default :
            printf("invalid choice");
        }
    }
    return 0;
}