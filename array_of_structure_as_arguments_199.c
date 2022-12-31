#include<stdio.h>
#include<stdlib.h>

struct point{
    int x;
    char y;
};

void prrint(struct point arr[]){
    for(int i=0;i<2;i++){
        printf("%d %d ",arr[i].x,arr[i].y);
    }
}

int main(){
    struct point arr[2]={{1,2},{3,4}};
    prrint(arr);
    return 0;
}