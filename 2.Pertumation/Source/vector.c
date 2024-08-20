
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
    VectorInsertByIndex(this,this->CurrentSize,data);
}
void VectorPopBack(vector *this)
{
    VectorDeleteByIndex(this,this->CurrentSize-1);
}

// 获取第i个元素的地址
void* VectorGetElementByIndex(vector *this,int index)
{
    if(index < this->Capacity)
    {
        return ((char *)this->data + index * this ->ElementSize);
    }
    return NULL;
}

void VectorExtendCapacity(vector *this)
{
    void *TempBuff = this->data;
    this->data = (void *)malloc(this->Capacity *this->ElementSize * 2);
    memcpy(TempBuff,this->data,this->Capacity * this ->ElementSize);
    this->Capacity = 2 * this->Capacity;
    free(TempBuff);
}
// 插入第i个元素

void VectorInsertByIndex(vector *this, int index, void *data)
{
    if(index<0 || index >= this->Capacity ||this->CurrentSize == this->Capacity)
    {
        VectorExtendCapacity(this);
    }

    char *TempAddress = (char *) VectorGetElementByIndex(this,index);
    memmove(TempAddress+this->ElementSize,TempAddress,(this->CurrentSize - index) * this->ElementSize);
    memmove(TempAddress,data,this->ElementSize);
    this->CurrentSize ++ ;
}

void VectorDeleteByIndex(vector *this, int index)
{
    if(index<0 || index >= this->Capacity || this->Capacity ==0)
    {
        return;
    }
    char *TempAddress = (char *) VectorGetElementByIndex(this,index);
    memmove(TempAddress,TempAddress+this->ElementSize,(this->CurrentSize - index - 1) * this->ElementSize);
    this->CurrentSize -- ;
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
    printf("Capacity: %d, CurrentNum:%d, NumSize:%d\n",this->Capacity,this->CurrentSize,this->ElementSize);

    for(int i = 0 ; i < this->CurrentSize;i++)
    {
        printf("%d ",*((char*)this->data + i * this->ElementSize));
    }
    printf("\n");
}