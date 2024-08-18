
#include <string.h>
#include <stdlib.h>
#include <vector.h>
#include <stdio.h>


// 构造函数 根据大小 类型 初始化vector

void GenertorVector(vector *this,int n, int ElementSize)
{

    this->data = (void *)malloc(n * ElementSize);
    this->ElementSize = ElementSize;
    this->CurrentSize = 0;
    this->Capacity    = n;  
}

void DestroyVector(vector *this)
{
    free(this->data);
    this->data = NULL;
    this->Capacity = 0;
    this->CurrentSize = 0;
    this->ElementSize = 0;
}

void VectorPushback(vector *this,void *data)
{
    if(this->CurrentSize == this->Capacity)
    {
        //
        this->Capacity = this->Capacity * 2;
        void *TempBuff = this->data;
        this->data = (void *)malloc(this->Capacity *this->ElementSize);
        memcpy(TempBuff,this->data,this->Capacity * this ->ElementSize);
        free(TempBuff);
    }else{
        memcpy((char *)this->data + this->CurrentSize*this->ElementSize,data,this->ElementSize);
        this->CurrentSize++;
    }
}

void* GetIndex(vector *this,int index)
{
    return ((char *)this->data + index * this ->ElementSize);
}

void  swap(void *a,void *b,int Size_)
{
    void *temp = (void *) malloc(Size_);

    memcpy(temp,a,Size_);
    memcpy(a,b,Size_);
    memcpy(b,temp,Size_);

    free(temp);

   
}

void VectorPrint(vector *this)
{
    printf("Capacity: %d, CurrentNum:%d, NumSize:%d",this->Capacity,this->CurrentSize,this->ElementSize);

    // for(int i = 0 ; i < this->CurrentSize;i++)
    // {
    //     printf("%d ",*((char*)this->data + i * this->ElementSize));
    // }
}