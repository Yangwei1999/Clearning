
# 利用vector 重新写重排列  以dfs的思路去写


利用vector 编写了dfs算法实现全排列


## 遇到的问题
1. 为了泛型编程，所有的vector相关的函数，例如push，pop，insert等，都有两个特点，一个是输入时必须传递void *指针（其实传什么不重要，利用的是首地址和长度参数做memcpy），这导致了有几个不好用的地方，输出的时候考虑到泛型，也只能输出void* 指针
   1. 一个是输入的时候，不能传递常量，因为得传地址，
   2. 输出的时候，需要强转为需要的类型
   3. 这部分应该不改，使用者应该根据自己的类型，再次封装，例如SetValue和GetValue，**里面可以加switch分支，根据类型区分**

```
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

```

*to do list*
- [ ] 容量为0时，应该先扩充1，再双倍扩充
- [ ] 管理工程，这样更新太麻烦了 
## 思考dfs 复习

```
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

```

