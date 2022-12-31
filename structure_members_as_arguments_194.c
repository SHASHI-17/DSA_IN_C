#include<stdio.h>
#include<stdlib.h>

// struct student{
//     char *ptr;
//     int roll_no;
//     int age;
//     float marks;
//     };

//     void prrint(char *ptr,int r,int a,float m){
//         printf("%s %d %d %0.2f ",ptr,r,a,m);
//     }

// int main(){
//     struct student st1={"shashi",123,22,98.9};
//     prrint(st1.ptr,st1.roll_no,st1.age,st1.marks);
//     return 0;
// }

// same thing by call by reference(or passsing address)
struct charset{
    char ptr;
    int x;
};

void setvalue(char *ptr,int *x){
    scanf("%c %d",ptr,x);
}

int main(){
    struct charset cs;
    setvalue(&cs.ptr,&cs.x);
    printf("%c %d",cs.ptr,cs.x);
}