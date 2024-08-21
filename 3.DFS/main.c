#include<stdio.h>
#include <stdlib.h>
#include <string.h>
// #include<vector>
// 
#include "vector.h"


// #define DEBUG 1

// 自定义调试打印函数
#ifdef DEBUG
    #define DEBUG_PRINT(fmt, args...)    printf("DEBUG: " fmt, ## args)
#else
    #define DEBUG_PRINT(fmt, args...)    // 空实现，不打印
#endif

int sum = 0;
vector **g_res = NULL;


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


// 目标是什么，找到sum
void dfs(vector *vec, vector *path, int target,int n,int k)
{
    // 终止条件
    if(sum == target)
    {
        // find a path
        DEBUG_PRINT(" i can find a path\n");

        vector *temploc = (vector **)malloc(sizeof(vector *));
        for(int i = 0; i < path->CurrentSize;i++)
        {
            printf("%d ",GetValue(path,i));
        }
        DEBUG_PRINT("\n");
    }else if(sum > target){
        return;
    }
    //向每个方向试探
    for(int i = k; i < n; i++)
    {
        // if((i-1)>=0&&GetValue(vec,i) == GetValue(vec,i-1)) continue;
        int temp = GetValue(vec,i);
        VectorPushback(path,&temp);
        sum = sum + temp;
        dfs(vec,path,target,n,i);
        VectorPopBack(path);
        sum = sum - temp;
    }

}

// 二级指针的使用
int main()
{

    int n,target;
    scanf("%d %d",&n,&target);
    int temp;
    vector *vec1 = (vector *) malloc(sizeof(vector));
    vector *path = (vector *) malloc(sizeof(vector));
    GenertorVector(vec1,n, sizeof(int));
    GenertorVector(path,n, sizeof(int));
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&temp);
        SetValue(vec1,i,temp);
    }


    dfs(vec1,path,target,n,0);


    DestroyVector(vec1);
    return 1;
}