#include<stdio.h>
#include<stdlib.h>// for exit(1)
#define MAX 5

int first=-1,arr[MAX];

int isEmpty(){
    if(first==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(first==(MAX-1)){
        return 1;
    }
    else{
        return 0;
    }
}

int peek(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    else{
        return arr[0];
    }
}

void push(int data){
        if(isFull()){
        printf("stack overflow");
        exit(1);
    }
    else{
    first++;
    for(int i=first;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=data;
}
}

void print(){
    if(first==-1){
        printf("stack underflow");
        exit(1);
    }
    for(int i=0;i<=first;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int pop(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    else{
    int value;
    value=arr[0];
    for(int i=0;i<first;i++){
        arr[i]=arr[i+1];
    }
    first--;
    return value;
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