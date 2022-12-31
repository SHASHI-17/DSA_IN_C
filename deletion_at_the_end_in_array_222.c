#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[]={1,2,2,4,43,54,5,534};
    int size=sizeof(arr)/sizeof(int);
    size--;
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}