#include<stdio.h>
#include <stdlib.h>
#include <string.h>
// #include<vector>
// 
#include "vector.h"

int GetValue(vector *vec,int index)
{
    // 这个用来强转，由调用者实现
    return *((int *)VectorGetElementByIndex(vec,index));
}

void  SetValue(vector *vec,int index,int value)
{
    // 这个用来强转，由调用者实现
     *((int *)VectorGetElementByIndex(vec,index)) = value;
}

void dfs(vector *vec,vector *used, vector *path, int n)
{
    // 终止条件
    if(path->CurrentSize == n)
    {
        // find a path
        // printf(" i can find a path\n");
        for(int i = 0 ; i < path->CurrentSize;i++)
        {
            printf("%d ",GetValue(path,i));
        }
        printf("\n");
    }

    //向每个方向试探

    for(int i = 0;i<n;i++)
    {
        if(GetValue(used,i)) continue;  //如果已经走过，不走重复路

        // 如果没有走过，从该点开始继续dfs
        SetValue(used,i,1);
        int temp = GetValue(vec,i);
        VectorPushback(path,&temp);

        dfs(vec,used,path,n);

        SetValue(used,i,0);

        VectorPopBack(path);
        
    }

}

int main()
{

    int n ;
    scanf("%d",&n);


    vector *vec1 = (vector *) malloc(sizeof(vector));
    vector *used = (vector *) malloc(sizeof(vector));
    vector *path = (vector *) malloc(sizeof(vector));
    GenertorVector(vec1,n, sizeof(int));
    GenertorVector(used,n, sizeof(int));
    GenertorVector(path,n, sizeof(int));

    memset(used->data,0,used->Capacity*used->ElementSize);
    used->CurrentSize = n;
    for(int i = 1; i <=n;i++)
    {
        VectorPushback(vec1,&i);
    }

    dfs(vec1,used,path,n);


    DestroyVector(vec1);
    DestroyVector(used);
    return 1;
}