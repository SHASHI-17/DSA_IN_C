#include<stdio.h>
#include<stdlib.h>

void add_at_pos(int arr[],int arr2[],int size,int data,int position){
    int index=position-1;
    for(int i=0;i<index;i++){
        arr2[i]=arr[i];
    }
    arr2[index]=data;
    for(int i=index+1,j=index;i<size+1,j<size;i++,j++){
        arr2[i]=arr[j];
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int pos=5,data=78;
    int size=sizeof(arr)/sizeof(arr[0]);
    int arr2[size+1];
    add_at_pos(arr,arr2,size,data,pos);
    for (int i = 0; i < size+1; i++)
    {
        printf("%d ",arr2[i]);
    }
    
    return 0;
}