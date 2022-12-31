#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node;

node* add_node_at_beg(node* head,int data){
    node* new_node=malloc(sizeof(node));
    new_node->data=data;
    new_node->link=NULL;

    new_node->link=head;
    head=new_node;
    return head;
}

node* create_LL(node* head,int n){
        while(n!=0){
        head=add_node_at_beg(head,n%10);
        n/=10;
    }
    return head;
}

void print(node* head){
    if(head==NULL){
        printf("no number ");
    }
    else{
        node* temp=head;
        while(temp->link!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->link;
        }
        printf("%d",temp->data);
    }
    printf("\n");
}

node* reverse(node * head){
    if(head==NULL){
        printf("no list");
    }
    node* current=NULL;
    node* next=head->link;
    head->link=NULL;

    while(next!=NULL){
        current=next;
        next=next->link;
        current->link=head;
        head=current;
    }

    // while(head->data==0){
    //     head=head->link;
    // }
    return head;
}
node* add_two_numbers(node* head1,node* head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* head3=NULL;
    int sum,carry=0;

    while(ptr1 || ptr2){  // here instead of null / we can use 0
        sum=0;
        if(ptr1){
            sum+=ptr1->data;
        }
        if(ptr2){
            sum+=ptr2->data;
        }
        sum+=carry;
        carry=sum/10;
        sum=sum%10;

        head3=add_node_at_beg(head3,sum);
        if(ptr1){
            ptr1=ptr1->link;
        }
        if(ptr2){
            ptr2=ptr2->link;
        }
    }
    if(carry){
        head3=add_node_at_beg(head3,carry);
    }
   return head3;
}
void back2num(struct node* head)
{ 
    struct node* temp = head; 
    printf("\nResult = "); 
    while(temp) 
    {
        printf("%d", temp->data); 
        temp = temp->link;
    } 
    return; 
}

int main(){
    int a,b;
    printf("enter two numbers \n");
    scanf("%d %d",&a,&b);

    printf("linked list representation of first number \n");
    node* head1=NULL;
    head1=create_LL(head1,a);
    print(head1);

    printf("linked list representation of second number \n");
    node* head2=NULL;
    head2=create_LL(head2,b);
    print(head2);

    printf("Reversed linked lists -: \n");

    head1=reverse(head1);
    print(head1);

    head2=reverse(head2);
    print(head2);

    printf("adding of two numbers \n");
    node* head3=NULL;
    head3=add_two_numbers(head1,head2);
    print(head3);

    back2num(head3);
    return 0;
}