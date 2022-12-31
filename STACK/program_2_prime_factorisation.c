#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int arr[MAX],top=-1;

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top==(MAX-1)){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){
    if(isFull()){
        printf("stack overflow");
        exit(1);
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
        int value=arr[top--];
        return value;
    }
}

void prime_fact(int num){
    int i=2;
    while(num!=1){
        while(num%i==0){
            push(i);
            num=num/i;
        }
        i++;
    }

    while(top!=-1){
        printf("%d ",pop());
    }
}

int main(){
    int data;
    printf("enter the number for prime factorisaation \n");
    scanf("%d",&data);
    prime_fact(data);
    return 0;
}