#include<stdio.h>
#include<stdlib.h>

struct point{
    int x,y;
};

struct point edit(struct point p1){
    (p1.x)++;
    p1.y+=5;
    return p1;
}

void prrint(struct point p){
    printf("%d %d\n",p.x,p.y);
}

int main(){
    struct point p1={1,2};
    struct point p2={3,4};
    p1=edit(p1);
    p2=edit(p2);
    prrint(p1);
    prrint(p2);
    return 0;
}