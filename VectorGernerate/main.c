#include<stdio.h>
// #include<vector>
// 
#include "vector.h"

int main()
{
    printf("hello wordld\n");
    printf("this is vector genertato\n");
    vector vec1;
    GenertorVector(&vec1,2, sizeof(int));
    int temp;
    temp = 1;
    VectorPrint(&vec1);
    VectorPushback(&vec1,(void *)&temp);
VectorPrint(&vec1);
    temp = 2;
    VectorPushback(&vec1,(void *)&temp);
    VectorPrint(&vec1);

    int *res;

    res = (int *)GetIndex(&vec1,0);

    printf("res : %d\n",*res);

    res = (int *)GetIndex(&vec1,1);

    printf("res : %d\n",*res);

    


    temp = 3;
    VectorPushback(&vec1,(void *)&temp);
    VectorPrint(&vec1);

    DestroyVector(&vec1);


    return 1;
}