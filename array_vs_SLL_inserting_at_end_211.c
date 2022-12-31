#include<stdio.h>
#include<stdlib.h>


// array is not full

// int add_at_end(int arr[],int free,int data){
//     arr[free]=data;
//     free++;
//     return free;
// }

// int main(){
//     int a[5],count;
//     printf("enter the size of the array \n");
//     scanf("%d",&count);
//     for (int i = 0; i < count; i++)
//     {
//         printf("enter the integers %d\n",i+1);
//         scanf("%d",&a[i]);
//     }
//     int freepos=count;
//     freepos=add_at_end(a,freepos,65);
//     for (int i = 0; i < freepos; i++)
//     {
//         printf("%d ",a[i]);
//     }
//     return 0;
// }


// array is full

int add_at_end(int a[],int b[],int n,int freepos,int data){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    b[freepos]=data;
    freepos++;
    return freepos;
}

int main(){
    int a[3],count;
    printf("enter the size of the array \n");
    scanf("%d",&count);
    for (int i = 0; i < count; i++)
    {
        printf("enter the integers %d\n",i+1);
        scanf("%d",&a[i]);
    }

    int size=sizeof(a)/sizeof(int);
    int freepos=count;
    if(count==size){
        int b[size+2];
        freepos=add_at_end(a,b,size,freepos,65);
        freepos=add_at_end(a,b,size,freepos,69);
        for(int i=0;i<freepos;i++){
            printf("%d ",b[i]);
        }
    }
    return 0;
}