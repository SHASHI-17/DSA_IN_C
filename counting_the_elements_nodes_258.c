#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* add_to_empty(int data){
    node* temp=malloc(sizeof(node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

node *add_at_end(node *tail,int data){
    node* temp=malloc(sizeof(temp));
    temp->data=data;
    temp->next=tail->next;
    tail->next=temp;
    tail=tail->next;
    return tail;
}

node* creating_CSL(node* tail){
    int n,data;
    printf("enter the number of nodes \n");
    scanf("%d",&n);

    if(n==0){
        return tail;
    }
    printf("enter the element of node 1 \n");
    scanf("%d",&data);
    tail=add_to_empty(data);

    for(int i=1;i<n;i++){
        printf("enter the elment of node %d\n",i+1);
        scanf("%d",&data);
        tail=add_at_end(tail,data);
    }
    return tail;
}

void print(node* tail){
    int count=0;
    if(tail==NULL){
        printf("list is empty \n");
    }
    else{
    node*p=tail->next;
    do{
        count++;
        printf("%d ",p->data);
        p=p->next;
    }while(p!=tail->next);
} 
printf("\nThe total number of nodes in the list are %d\n",count);
}

int main(){
    node* tail=NULL;
    tail=creating_CSL(tail);
    print(tail);
    return 0;
}