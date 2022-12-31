#include<stdio.h>
#include<stdlib.h>

int main(){
    int x;
    printf("enter the size of the array \n");
    scanf("%d",&x);

    int *ptr=(int *)malloc(x*sizeof(int));

    if(ptr==NULL){
        printf("memory not available \n");
        exit(1);
    }

    for(int i=0;i<x;i++){
        printf("enter the integers in the array \n");
        scanf("%d",ptr+i);
        //ptr++;
    }
    for(int i=0;i<x;i++){
        printf("%d ",*(ptr+i));
        //ptr++;
    }
    free(ptr);
    ptr=NULL; // to make to empty ..coz of dangling
    return 123;
}
