#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
// int top=-1,arr[100];
//  void push(){
//     if(top>99){
//         printf("stack overflow \n");
//     }
//     else{
//         top++;
//         printf("enter the element \n");
//         scanf("%d",&arr[top]);  
//     }
// }

// int pop() {
//     if(top<0){
//         printf("stack underflow \n");
//     }
//     else{
//         arr[top]=NULL;
//         top--;
//     }
// }

// void display() {
//     int x=top;
//     for(x;x>=0;x--){
// printf("%d ",arr[x]);
//     }
// }

// int main() {
//     int choice;
//     printf("stack implemention");
//     do{
//         printf("\n 1.push \n 2.pop\n3.display\n4.exit\n");
//         printf("enter your choice \n");
//         scanf("%d",&choice);
//         switch(choice){
//             case 1:
//             push();
//             break;
//             case 2:
//             pop();
//             break;
//             case 3:
//             display();
//             break;
//             case 4 :
//             exit(0);
//         }
//     }while(choice!=4);
//     return 0;
// }


/*
 * C Program to Implement a Queue using an Array
 */
// #include <stdio.h>
 
// #define MAX 50
 
// void insert();
// void delete();
// void display();
// int queue_array[MAX];
// int rear = - 1;
// int front = - 1;
// int main()
// {
//     int choice;
//     while (1)
//     {
//         printf("1.Insert element to queue \n");
//         printf("2.Delete element from queue \n");
//         printf("3.Display all elements of queue \n");
//         printf("4.Quit \n");
//         printf("Enter your choice : ");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//             case 1:
//             insert();
//             break;
//             case 2:
//             delete();
//             break;
//             case 3:
//             display();
//             break;
//             case 4:
//             exit(1);
//             default:
//             printf("Wrong choice \n");
//         } 
//     } 
// } 
 
// void insert()
// {
//     int add_item;
//     if (rear == MAX - 1)
//     printf("Queue Overflow \n");
//     else
//     {
//         if (front == - 1)
//         front = 0;
//         printf("Inset the element in queue : ");
//         scanf("%d", &add_item);
//         rear = rear + 1;
//         queue_array[rear] = add_item;
//     }
// }
 
// void delete()
// {
//     if (front == - 1 || front > rear)
//     {
//         printf("Queue Underflow \n");
//     }
//     else
//     {
//         printf("Element deleted from queue is : %d\n", queue_array[front]);
//         front = front + 1;
//     }
// } 
 
// void display()
// {
//     int i;
//     if (front == - 1)
//         printf("Queue is empty \n");
//     else
//     {
//         printf("Queue is : \n");
//         for (i = front; i <= rear; i++)
//             printf("%d ", queue_array[i]);
//         printf("\n");
//     }
// } 


// queue user=shashi,defined

// int top=-1,down=0,arr[100];


// int insert(){
//     if(top>99){
//         printf("queue overflow \n");
//     }
//     else{
//         top++;
//         printf("enter the element\n");
//         scanf("%d",&arr[top]);
//     }
// }

// int delete() {
//     if(top<0){
//         printf("queue underflow \n");
//     }
//     else{
//       //  arr[down]==NULL;
//       //  printf("the deleted element is %d\n",arr[down]);
//         down++;
//     }
// }

// int display() {
//     for(int i=down;i<=top;i++){
//         printf("%d ",arr[i]);
//     }
// }


// int main() {
//     int choice;
//     while(1){
//         printf("\n1.insert\n2.delete\n3.display\n4.exit \n");
//         printf("enter your choice  \n");
//         scanf("%d",&choice);
//         switch(choice){
//             case 1:
//             insert();
//             break;

//             case 2:
//             delete();
//             break;

//             case 3:
//             display();
//             break;

//             case 4:
//             exit(0);

//             default :
//             printf("sorry \n");
//         }
//     }
// }


// void kira(int *ptr,int x){
//    for(int i=0;i<x;i++){
//        printf("enter the elemnt %d \n",i+1);
//        scanf("%d",ptr);
//        ptr++;
//    }
// }

// int main(){
// int arr[459];
// int x;
// printf("enter the size of array \n");
// scanf("%d",&x);
// kira(arr,x);
// int mx=arr[0];
// for(int i=0;i<x;i++){
//    if(arr[i]<mx){
//        mx=arr[i];
//    }
// }
// printf("the lowest element is %d",mx);
// return 0;
// }


// #include<stdio.h>
// #include<ctype.h>

// char stack[100];
// int top = -1;

// void push(char x)
// {
//     stack[++top] = x;
// }

// char pop()
// {
//     if(top == -1)
//         return -1;
//     else
//         return stack[top--];
// }

// int priority(char x)
// {
//     if(x == '(')
//         return 0;
//     if(x == '+' || x == '-')
//         return 1;
//     if(x == '*' || x == '/')
//         return 2;
//     return 0;
// }

// int main()
// {
//     char exp[100];
//     char *e, x;
//     printf("Enter the expression : ");
//     scanf("%s",exp);
//     printf("\n");
//     e = exp;
    
//     while(*e != '\0')
//     {
//         if(isalnum(*e))
//             printf("%c ",*e);
//         else if(*e == '(')
//             push(*e);
//         else if(*e == ')')
//         {
//             while((x = pop()) != '(')
//                 printf("%c ", x);
//         }
//         else
//         {
//             while(priority(stack[top]) >= priority(*e))
//                 printf("%c ",pop());
//             push(*e);
//         }
//         e++;
//     }
    
//     while(top != -1)
//     {
//         printf("%c ",pop());
//     }return 0;
// }


// int main(){
//     int n,rev=0;
//     printf("enter the number \n");
//     scanf("%d",&n);
//     int lelo=n;
//     while(n!=0){
//         int rem=n%10;
//         rev=rev*10+rem;
//         n/=10;
//     }
// if(lelo==rev){
//     printf("its an palindrome number i.e %d",rev);
// }
// else{
//     printf("its not a palindrome number i.e %d",rev);
// }
// return 123456;
// }


// int main(){
//     int x;
//     scanf("%d",&x);
//     if(x%2==0){
//         printf("eve");
//     }
//     else{
//         printf("odd");
//     }
// }
// int main(){
//     int x,sum=0;
//     scanf("%d",&x);
//     for(int i=1;i<=x;i++){
//         sum+=i;
//     }
//     printf("%d",sum);
// 

// void strncaat(char str1[],char str2[]){
//     int i=0,j=0;
//     while(str1[i]!='\0'){ // this is for counting the first string
//         i++;
//     }
//     str1[i++]=32;
//     while(str2[j]!='\0'){ // i starts from the end of the first string
//         str1[i]=str2[j];
//         i++;
//         j++;
//     }
//     str1[i]='\0';
//     printf("\n concatenated string is %s",str1);
// }


// int main(){
//     char str1[23],str2[45];
//     printf("enter your first string \n");
//     gets(str1);
//     printf("enter your second string \n");
//     gets(str2);
//     strncaat(str1,str2);
//     return 'A';
// }

void swap(int *x,int *y){
    *x=*x^*y;
    *y=*x^*y;
    *x=*x^*y;
}

void selection_sort(int *arr,int n){
    int min;
    for(int i=0;i<(n-1);i++){
         min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
    swap(&arr[i],&arr[min]);
    }
}


void print(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={5,7,2,3,1,8,6};
    int size=sizeof(arr)/sizeof(int);
    printf("%d\n",size);
    print(arr,size);
    selection_sort(arr,size);
    print(arr,size);
}

