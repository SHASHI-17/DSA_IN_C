#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}node;

// node *del_last(node *head){
// //void del_last(node *head){
//     if(head==NULL){
//         printf("linked list is empty \n");
//     }
//     else if(head->link==NULL){
//         free(head);
//         head=NULL;
//     }
//     else{
//         node *ptr=head;
//         node *ptr2=head;
//         while(ptr->link !=NULL){// loop will not allow to update null into ptr2
//             ptr2=ptr;
//             ptr=ptr->link;
//         }
//         ptr2->link=NULL;
//         free(ptr);
//         ptr=NULL;
//     return head; // we will return 1000 back to the main function
//     }
// }
node *del_last(node *head){
//void del_last(node *head){
    if(head==NULL){
        printf("linked list is empty \n");
    }
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
       node *ptr=head;
       free(ptr->link->link);
       ptr->link->link=NULL;
       return head;
    }
}

int main(){
     node *first=NULL;
    first=(node *)malloc(sizeof(node));
    first->data=56;
    first->link=NULL;

    node *second=NULL;
    second=(node *)malloc(sizeof(node));
    second->data=565;
    second->link=NULL;

    node *third=NULL;
    third=(node *)malloc(sizeof(node));
    third->data=562;
    third->link=NULL;

    first->link=second;
    second->link=third;

    node *head=first;
    head=del_last(head);
    //del_last(head);
    node *ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}