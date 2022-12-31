#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int arr[MAX],top=-1;

int isfull(){
    if(top==(MAX-1)){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){
    if(isfull()){
        printf("stack overflow");
        return;
    }
    else{
        arr[++top]=data;
    }
}

int pop(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    else{
     int value;
    value=arr[top--];
    return value;
    }
}

void print(){
    if(top==-1){
        printf("stack underflow");
    }
    else{
        for(int x=top;x>=0;x--){
            printf("%d ",arr[x]);
        }
        printf("\n");
    }
}

int peek(){
    if(isEmpty()){
        printf("stack underflow \n");
        exit(1);
    }
    else{
        return arr[top];
    }
}

int main(){
    int data,choice;
    printf("stack implememtation \n");
    while(1){
        printf("\n1.push\n2.pop\n3.print the top element\n4.print all the elements of stack\n5.exit\n");
        printf("enter your choice \n");
        scanf("%d",&choice);

        switch(choice){
            case 1 :
            printf("enter the element to be pushed \n");
            scanf("%d",&data);
            push(data);
            break;
            
            case 2:
            data=pop();
            printf("the deleted element is %d",data);
            break;

            case 3 :
            printf("\nthe topmost element of stack is %d\n",peek());
            break;

            case 4:
            print();
            break;

            case 5:
            exit(1);

            default :
            printf("invalid choice \n");
        }
    }
    return 0;
}