#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    float coefficient;
    int exponent;
    struct node* link;
}node;

node* insert(node* head,float coffe,int expo){
    node* new_node=malloc(sizeof(node));
    new_node->coefficient=coffe;
    new_node->exponent=expo;
    new_node->link=NULL;

    if(head==NULL || expo > head->exponent ){
        new_node->link=head;
        head=new_node;
    }

    else{
        node* temp=head;
        while(temp->link!=NULL && temp->link->exponent > expo){
            temp=temp->link;
        }
        new_node->link=temp->link;
        temp->link=new_node;
    }
    return head;
}


node * create(node * head){
    int expo,n;
    float coffe;
    printf("enter the number of terms \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the coefficient of %d\n",i+1);
        scanf("%f",&coffe);
        printf("enter the exponent of %d\n",i+1);
        scanf("%d",&expo);
        head=insert(head,coffe,expo);
    }
    return head;
}

void print(node* head){
    if(head==NULL){
        printf("sorry \n");
    }
    else{
        node* temp=head;
        while(temp!=NULL){
            printf("(%0.1fx^%d)",temp->coefficient,temp->exponent);
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

void poly_mul(node* head1,node* head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* head3=NULL;

    if(head1==NULL || head2==NULL){
        printf("zero polynomial \n");
    }

    while(ptr1!=NULL){
        while (ptr2!=NULL)
        {
            head3=insert(head3,ptr1->coefficient*ptr2->coefficient,ptr1->exponent+ptr2->exponent);
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
        ptr2=head2;
    }
    printf("before simplification \n");
    print(head3);

    node* ptr3=head3;
    node* temp=NULL;

    while(ptr3->link!=NULL){
        if(ptr3->exponent == ptr3->link->exponent){
            ptr3->coefficient=ptr3->coefficient + ptr3->link->coefficient;
            temp=ptr3->link;
            ptr3->link=ptr3->link->link;
            free(temp);
        }
        else{
            ptr3=ptr3->link;
        }
    }
    printf("\n after simplification \n");
    print(head3);
}

int main(){
    node* head1=NULL;
    node* head2=NULL;

    head1=create(head1);

    head2=create(head2);

    poly_mul(head1,head2);

    return 0;
}