#include<stdio.h>
#include<stdlib.h>

// apna wala
// when array is full
// int add_at_beg(int arr[],int brr[],int count,int data){
//     brr[0]=data;
//     for (int i = 1,j=0; i <=count; i++,j++)
//     {
//         brr[i]=arr[j];
//     }
// }

// int main(){
//     int count,arr[5],brr[5];
//     printf("enter the size of the array \n");
//     scanf("%d",&count);

//     for (int i = 0; i < count; i++)
//     {
//         printf("enter the integers of %d\n",i+1);
//         scanf("%d",&arr[i]);
//     }
//     count=add_at_beg(arr,brr,count,45);
//     for (int i = 0; i < count; i++)
//     {
//         printf("%d ",brr[i]);
//     }
//     return 0;
// }


// when array is not full
int add_at_beg(int arr[],int n,int data){
    for(int i=n-1;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=data;
    return n+1;
}

int main(){
    int arr[5],data=45,count;
        printf("enter the size of the array \n");
    scanf("%d",&count);
    for (int i = 0; i < count; i++)
    {
        printf("enter the integers of %d\n",i+1);
        scanf("%d",&arr[i]);
    }
count=add_at_beg(arr,count,data);
    for (int i = 0; i < count; i++)
    {
        printf("%d ",arr[i]);
    }
}