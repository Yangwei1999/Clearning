#include<stdio.h>
// #include<vector>
// 
#include "vector.h"

int main()
{
    printf("hello wordld\n");
    printf("this is vector genertato\n");
    vector vec1;
    GenertorVector(&vec1,4, sizeof(int));
    int temp;
    temp = 1;
    // VectorPrint(&vec1,sizeof(int));
    VectorPushback(&vec1,(void *)&temp);
    VectorPrint(&vec1,sizeof(int));
    temp = 2;
    VectorPushback(&vec1,(void *)&temp);
    VectorPrint(&vec1,sizeof(int));

    int *res;

    res = (int *)VectorGetElementByIndex(&vec1,0);

    printf("res : %d\n",*res);

    temp = 99;

    VectorInsertByIndex(&vec1,0,(void *)&temp);
    printf("res : %d\n",*res);
    

    res = (int *)VectorGetElementByIndex(&vec1,1);

    printf("res : %d\n",*(int *)res);

    
    temp = 3;
    VectorPushback(&vec1,(void *)&temp);
    VectorPrint(&vec1,sizeof(int));

    VectorDeleteByIndex(&vec1,3);
    VectorPrint(&vec1,sizeof(int));

    DestroyVector(&vec1);

    unsigned char a = -1;
    char b = -1;

    printf("a = %u ,b = %d\n",a,b);


    return 1;
}