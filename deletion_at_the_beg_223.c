#include<stdio.h>
#include<stdlib.h>

int del_at_beg(int arr[],int n){
    if(n==0){
        printf("array is empty \n");
    }
    else{
        for(int i=0;i<n-1;i++){
            arr[i]=arr[i+1];
        }
    }
    return --n;
}

int main(){
    int arr[8],n;
    printf("enter the size of the array \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the elements of %d\n",i+1);
        scanf("%d",&arr[i]);
    }
    n=del_at_beg(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}