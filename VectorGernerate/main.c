#include<stdio.h>
// #include<vector>
// 
#include "vector.h"

int main()
{
    printf("hello wordld\n");
    printf("this is vector genertato\n");

    int a = 1,b = 2;
    char c = 3,d = 4;

    swap(&a,&b,sizeof(a));
    swap(&c,&d,sizeof(c));

    printf("%d %d %d %d\n",a,b,c,d);


    return 1;
}