#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node *add_at_end(node *head,int data){
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->link=NULL;

    head->link=ptr;
    return ptr;
}
node * add_beg(node *head,int data){
    node *ptr=(node *)malloc(sizeof(node));
    ptr->data=data;
    ptr->link=NULL;

    ptr->link=head;// giving addressof 1st node to new node
    head=ptr;// pointing to the first node
    return head;
}
void adding_at_end(node *head,int data){
    node *temp=NULL;
    temp=(node *)malloc(sizeof(node));
    temp->data=data;
    (*temp).link=NULL;

    while(head->link!=NULL){ // TRAVERSING through loop we are taking head to the last
        head=head->link;
    }
    head->link=temp;
}

void add_at_certain_pos(node *head,int data,int position){
    node *ptr2=(node *)malloc(sizeof(node));
    ptr2->data=data;
    ptr2->link=NULL;

    position--;
    while(position!=1){
        head=head->link;
        position--;
    }
    ptr2->link=head->link; // updating the new link address
    head->link=ptr2;// updating the positioned node
}
void counting_the_nodes(node *head){
    int count =0;
    if(head==NULL){
        printf("linked list is empty \n");
    }
   // node *ptr=NULL;
   // ptr=head;
    while(head!=NULL){
        count++;
        head=head->link;
    }
    printf("total nodes : %d\n",count);
}

void print_data(node *head){
    if(head==NULL){
        printf("linked list is empty \n");
    }
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->link;
    }
}
int main(){
    node *HEAD=(node *)malloc(sizeof(node));
    HEAD->data=48;
    HEAD->link=NULL;

    node *ptr=HEAD;
    ptr=add_at_end(ptr,32);
    ptr=add_at_end(ptr,47);

    int data=45,position=3;

    ptr=HEAD;
   add_at_certain_pos(ptr,data,position);
    ptr=HEAD;

    HEAD=add_beg(HEAD,67);
    ptr=HEAD;
    
    counting_the_nodes(ptr);// count k liye
    // while(ptr!=NULL){
    //     printf("%d ",ptr->data);
    //     ptr=ptr->link;
    // }

    print_data(ptr);

    return 0;
}