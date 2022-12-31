#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int arr[MAX],top=-1;

int isempty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(){
    if(top==(MAX-1)){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){
    if(isfull()){
        printf("stack overflow");
        exit(1);
    }
    else{
        arr[++top]=data;
    }
}

int pop(){
    if(isempty()){
        printf("stack underflow ");
        exit(1);
    }
    else{
        int data=arr[top--];
        return data;
    }
}

void dec2bin(int n){
    while(n!=0){
        push(n%2);
        n/=2;
    }
    while(top!=-1){
        printf("%d ",pop());
    }
}

int main(){
    int x;
    printf("enter the number for conversion\n");
    scanf("%d",&x);
    dec2bin(x);
    return 0;
}