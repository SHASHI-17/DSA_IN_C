#include<stdio.h>
#include<stdlib.h>

struct code{
    int x;
    char y;
    struct code *ptr;
};

int main(){
    struct code var1;
    struct code var2;

    var1.x=65;
    var1.y='A';
    var1.ptr=NULL;

    var2.x=66;
    var2.y='B';
    var2.ptr=NULL;

    var1.ptr=&var2;

    printf("%d %c ",var1.ptr->x,var1.ptr->y);
    return 0;
}