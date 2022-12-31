#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
char infix[MAX],postfix[MAX];
int top=-1;

int space(char symbol){
    if(symbol== ' ' || symbol =='\t'){
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
        printf("stack overflow \n");
        return;
    }
    else{
        stack[++top]=data;
    }
}

int pop(){
    if(isEmpty()){
        printf("stack undeflow \n");
        exit(1);
    }
    else{
        int value;
        value=stack[top--];
        return value;
    }
}

int precedence(char symbol){
    switch(symbol){
        case '^' :
        return 3;

        case '*' :
        case '/' :
        return 2;

        case '+' :
        case '-' :
        return 1;

        default :
        return 0;
    }
}

void intoPost(){
    int j=0;
    char symbol, next;
    for(int i=0;i<strlen(infix);i++){
        symbol=infix[i];
        if(!space(symbol)){
        switch(symbol){

            case '(' :
            push(symbol);
            break;

            case ')' :
                while((next=pop())!='(') {
                    postfix[j++]=next;
                }
                    break;
             

        case '^' :
        case '*' :
        case '/' :
        case '+' :
        case '-' :
        while(!isEmpty() && precedence(stack[top] >= precedence(symbol))){
            postfix[j++]=pop();
        }
            push(symbol);
            break;

            default :
            postfix[j++]=symbol;
        }
    }
}
    while(!isEmpty()){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

void print(){
    printf("the equivalent postfix expression is :");
    for(int i=0;i<strlen(postfix);i++){
        printf("%c",postfix[i]);
    }
}

int main(){
    printf("enter the infix expression \n");
    gets(infix);

    intoPost();
    print();
    return 0;
}
