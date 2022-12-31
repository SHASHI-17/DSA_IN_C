#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int arr[MAX],top=-1;

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data){
    if(top==(MAX-1)){
        printf("stack overflow ");
        return;
    }
    else{
        arr[++top]=data;
    }
}

int pop(){
    if(isEmpty()){
        printf("stack underflow\n");
        exit(1);
    }
    else{
        int value;
        value=arr[top--];
        return value;
    }
}

void print(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    else{
        for(int x=top;x>=0;x++){
            printf("%d ",arr[top]);
        }
    }
}

int peek(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    else{
        return arr[top];
    }
}

void palindrome(char *s){
    int i=0;
    while(s[i]!='X'){
        push(s[i]);
        i++;
    }
    i++;
    while(s[i]){
        if(isEmpty() || s[i]!=pop()){
            printf("not a palindrome");
            exit(1);
        }
        i++;
    }
    if(isEmpty()){
        printf("palindrome");
    }
    else{
        printf("not a palindrome");
    }
}

int main(){
    char s[20];
    printf("enter the string \n");
    scanf("%s",s);

    palindrome(s);
    return 0;
}