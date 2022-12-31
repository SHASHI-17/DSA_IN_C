#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node* prev;
    int data;
    struct node* next;
}node;

node* add_to_empty(int data){
    node* new_node=malloc(sizeof(node));
    new_node->prev=NULL;
    new_node->data=data;
    new_node->next=NULL;
}

void print(node* head){
    if(head==NULL){
        printf("list is empty \n");
    }
    else{
        node* temp=head;
        while(temp->next!=NULL){
            printf("%d ->",temp->data);
            temp=temp->next;
        }
        printf(" %d",temp->data);
    }
    printf("\n");
}

node* add_at_beg(node* head,int data){
    node* new_node=add_to_empty(data);

    new_node->next=head;
    head->prev=new_node;
    head=new_node;
    return head;
}

node* add_at_end(node* head,int data){
    node* new_node=add_to_empty(data);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
    return head;
}

node* add_before_position(node* head,int data,int position){
    node* new_node=add_to_empty(data);

    node*temp=head;
    if(position==1){
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        return head;
    }
    else{
    position--;
    for(int i=1;i<position;i++){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    new_node->prev=temp;
    }
    return head;
}

node* add_after_position(node* head,int data,int position){
    node* new_node=add_to_empty(data);
    node* temp=head;
    for(int i=1;i<position;i++){
        temp=temp->next;
    }
    if(temp->next==NULL){
        new_node->prev=temp;
        temp->next=new_node;
    }
    else{
   new_node->next=temp->next; 
   temp->next=new_node;
   new_node->prev=temp;
    }
    return head;
}

node* del_first(node* head){
    if(head==NULL){
        printf("list is empty");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        head=head->next;
        free(head->prev);
        head->prev=NULL;
    }
    return head;
}

node* del_last(node* head){
        if(head==NULL){
        printf("list is empty");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
    return head;
}

node* del_inter(node * head,int position){
            if(head==NULL){
        printf("list is empty");
    }
    else if(position==1){
        head=del_first(head);
    }
    else{
        node* temp=head;
    for(int i=1;i<position;i++){
            temp=temp->next;
    }
    if(temp->next==NULL){
        head=del_last(head);
    }
    else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
    }
    return head;
}

node* reverse(node* head){
    node* temp=head;
    node* temp2=temp->next;
    temp->next=NULL;
    temp->prev=temp2;
    while(temp2!=NULL){
        temp2->prev=temp2->next;
        temp2->next=temp;
        temp=temp2;
        temp2=temp2->prev;
    }
    head=temp;
    return head;
}

node* create_DLL(node* head){
    int size,data;
    printf("enter the size \n");
    scanf("%d",&size);
    printf("enter the element of the first node \n");
    scanf("%d",&data);
    head=add_to_empty(data);
    for (int i = 0; i < size; i++)
    {
        printf("enter the elments of %d node ",i+1);
        scanf("%d",&data);
        head=add_at_end(head,data);
    }
    return head;
}

int main(){
    node* head=NULL;// creating
    // node* head=add_to_empty(56);
    // head=add_at_beg(head,87);
    // head=add_at_end(head,54);
    // head=add_at_end(head,74);
    // head=add_after_position(head,78,3);
    // head=add_before_position(head,98,5);
head=create_DLL(head);
  //  head=del_first(head);
    // head=del_last(head);
    // head=del_inter(head,6);
    print(head);
    head=reverse(head);
    print(head);
    return 0;
}