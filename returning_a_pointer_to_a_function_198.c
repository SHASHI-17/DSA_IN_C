#include<stdio.h>
#include<stdlib.h>

struct point{
    int x,y;
};

struct point* fun(int a,int b){
    struct point *ptr=(struct point *)malloc(sizeof(struct point));
    (*ptr).x=a;
    ptr->y=b+5;
    return ptr; // to return same type
}


void prrint(struct point *ptr){
    printf("%d %d\n",(*ptr).x,ptr->y);
}

int main(){
    struct point *ptr1,*ptr2;
    ptr1=fun(1,2);
    ptr2=fun(3,4);//here
    prrint(ptr1);
    prrint(ptr2);
    free(ptr1);
    free(ptr2);
    ptr1=ptr2=NULL;
    return 0;
}