#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    float coeff;
    int expo;
    struct node* link;
}node;

node* insert(node* head,float co,int exp){
     node* temp;
     node* new_node=malloc(sizeof(node));
     new_node->coeff=co;
     new_node->expo=exp;
     new_node->link=NULL;

    if(head==NULL || exp > head->expo){
        new_node->link=head;
        head=new_node;
    }
    else{
        temp=head;
        while(temp->link!=NULL && temp->link->expo > exp){
            temp=temp->link;
        }
        new_node->link=temp->link;
        temp->link=new_node;
    }
    return head;
}

node* create(node* head){
    int n;
    float co;
    int exp;
    printf("enter the number of terms \n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("enter the value of coefficient of %d ",i+1);
        scanf("%f",&co);
        printf("enter the value of exponent of %d ",i+1);
        scanf("%d",&exp);
        head=insert(head,co,exp);
    }
    return head;
}

void print(node* head){
    if(head==NULL){
        printf("no polynomial \n");
    }
    else{
        node* temp=head;
        while(temp!=NULL){
            printf("(%.1fx^%d)",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp!=NULL){
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }
    }
}

int main(){
    node* head=NULL;
    printf("enter your polynomial \n");
    head=create(head);
    print(head);
    return 0;
}