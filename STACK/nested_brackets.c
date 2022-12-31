#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int top=-1;
char arr[MAX];

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char data){
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



int match_char(char a,char b){
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
    if(a=='}' && b=='}'){
        return 1;
    }
    return 0;
}

int balance(char * s){
    char temp;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='[' || s[i]=='{' || s[i]=='('){
            push(s[i]);
        }
             if(s[i]==']' || s[i]=='}' || s[i]==')'){
                if(isEmpty()){
                    printf("right brackets are more than the left brackets \n");
                    return 0;
                }
                else{
                    temp=pop();
                    if( ! match_char(temp,s[i])){
                        printf("mismatched brackets \n");
                        return 0;
                    }
                }
             }
    }
    if(isEmpty()){
        printf("brackets are well balanced \n");
        return 1;
    }
    else{
        printf("left brackets are more than the right brackets \n");
        return 0;
    }
}

int main(){
    char shashi[MAX];

    printf("enter the value \n");
    gets(shashi);
   int balanced= balance(shashi);

    if(balanced==1){
        printf("expression is valid \n");
    }
    else if(balanced==0){
        printf("expression is inavalid \n");
    }
    return 0;
}