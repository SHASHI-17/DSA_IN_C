#include<stdio.h>
#include<stdlib.h>

struct point{
    int x,y;
};

void prrint(struct point p){
    printf("%d %d\n",p.x,p.y);
}

int main(){
    struct point p1={1,2};
    struct point p2={3,4};
    prrint(p1);
    prrint(p2);
    return 0;
}