#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    float coefficeint;
    int exponent;
    struct node * link;
}node;

node* insert(node* head,float coffe,int expo){
    node *new_node=malloc(sizeof(node));
    new_node->coefficeint=coffe;
    new_node->exponent=expo;
    new_node->link=NULL;

    if(head==NULL || expo > head->exponent){
        new_node->link=head;
        head=new_node;
    }
    else{
        node*temp=head;
        while(temp->link!=NULL &&  temp->link->exponent > expo){
            temp=temp->link;
        }
        new_node->link=temp->link;
        temp->link=new_node;
    }
        return head;
}

node* create(node* head){
    int n,expo;
    float coffe;
    printf("enter the number of terms \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the value of coefficeint of %d \n",i+1);
        scanf("%f",&coffe);
        printf("enter the value of exponent of %d \n",i+1);
        scanf("%d",&expo);
        head=insert(head,coffe,expo);
    }
    return head;
}

void print(node* head){
    if(head==NULL){
        printf("no polynomial ");
    }
    else{
        node* temp=head;
        while(temp!=NULL){
            printf("(%0.1fx^%d)",temp->coefficeint,temp->exponent);
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

void poly_add(node* head1,node* head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* head3=NULL;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->exponent == ptr2->exponent){
            head3=insert(head3,(ptr1->coefficeint + ptr2->coefficeint),ptr1->exponent);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->exponent > ptr2->exponent){
            head3=insert(head3,ptr1->coefficeint,ptr1->exponent);
            ptr1=ptr1->link;
        }
        else if(ptr1->exponent < ptr2->exponent){
            head3=insert(head3,ptr2->coefficeint,ptr2->exponent);
            ptr2=ptr2->link;
        }
    }
    while(ptr1!=NULL){
        head3=insert(head3,ptr1->coefficeint,ptr1->exponent);
        ptr1=ptr1->link;
    }
    while(ptr2!=NULL){
        head3=insert(head3,ptr2->coefficeint,ptr2->exponent);
        ptr2=ptr2->link;
    }
    printf("ADDED POLYNOMIALS \n");
    print(head3);
}

int main(){
    node* HEAD1=NULL;
    node* HEAD2=NULL;
    
    HEAD1=create(HEAD1);
    print(HEAD1);

    HEAD2=create(HEAD2);
    print(HEAD2);

    poly_add(HEAD1,HEAD2);
    return 0;
}