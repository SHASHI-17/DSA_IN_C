#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node;

int isEmpty(node* top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data,node** top){
    node* new_node=malloc(sizeof(node));
    new_node->data=data;
    new_node->link=NULL;

    if(new_node==NULL){
        printf("stack overflow \n");
    }
    new_node->link=*top;
    *top=new_node;
}


int pop(node** top1){
    node* temp=*top1;
    if(isEmpty(*top1)){
        printf("stack underflow \n");
        exit(1);
    }
    else{
        int value=temp->data;
        *top1=(*top1)->link;
        free(temp);
        temp=NULL;
        return value;
    }
}

void print(node* top1){
    if(isEmpty(top1)){
        printf("stack underflow \n");
        exit(1); 
        }
        else{
            node* temp=top1;
            while(temp){
                printf("%d ",temp->data);
                temp=temp->link;
            }
            printf("\n");
        }
}

void reverse_stack(node** top){
    node* top1=NULL;
    node* top2=NULL;
    //print(*top);
    while(*top!=NULL){
        push(pop(top),&top1);
    }
    while(top1!=NULL){
        push(pop(&top1),&top2);
    }

    while(top2!=NULL){
        push(pop(&top2),top);
    }
    //print(*top);
}
int main(){
    node* top=NULL;
    node* top1=NULL;
    node* top2=NULL;

    // int data;

    // push(1,&top);
    // push(2,&top);
    // push(3,&top);
    // printf("before reverse \n");
    // print(top);

    // data=pop(&top);
    // push(&top1,data);
    // data=pop(&top);
    // push(&top1,data);
    // data=pop(&top);
    // push(&top1,data);

    // data=pop(&top1);
    // push(&top2,data);    
    // data=pop(&top1);    
    // push(&top2,data);    
    // data=pop(&top1);    
    // push(&top2,data);

    // data=pop(&top2);
    // push(&top,data);
    // data=pop(&top2);
    // push(&top,data);
    // data=pop(&top2);
    // push(&top,data);

    // printf("after reverse \n");
    // print(top);

    int choice,data;
    while(4){
        printf("1.push\n2.print\n3.reveerse the stack \n4.exit\n");
        printf("enter the choice\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("enter the element to be pushed \n");
            scanf("%d",&data);
            push(data,&top);
            break;

            case 2:
            print(top);
            break;

            case 3 :
            printf("\nstack is reversed \n");
            reverse_stack(&top);
            break;

            case 4:
            exit(1);

            default:{
                printf("invalid choice\n");
            }
        }
    }
    return 0;
}