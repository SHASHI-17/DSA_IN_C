#include<stdio.h>
#include<stdlib.h>


int main() {
    int x,y;
    printf("enter the size of the array \n");
    scanf("%d",&x);

    int *ptr=(int *) malloc(x*sizeof(int));

      if(ptr==NULL){
        printf("memory not available \n");
        exit(1);
    }

    for(int i=0;i<x;i++){
        printf("enter the integers \n");
        scanf("%d",ptr+i);
    }
    printf("enter the size for reallocating \n");
    scanf("%d",&y);

    ptr=(int *)realloc(ptr,y*sizeof(int));
    for(int i=x;i<y;i++){
        printf("enter the integers \n");
        scanf("%d",ptr+i);
    }

      if(ptr==NULL){
        printf("memory not available \n");
        exit(1);
    }

    for(int i=0;i<y;i++){
        printf("%d ",*(ptr+i));
    }
}