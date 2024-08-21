

typedef struct vector{

    void *data;
    int Capacity;
    int CurrentSize;
    int ElementSize;

}vector;

void swap(void *,void *,int);

void GenertorVector(vector *this,int n, int ElementSize);
void DestroyVector(vector *this);
void VectorPushback(vector *this,void *data);
void * VectorGetElementByIndex(vector *this,int index);
void VectorPrint(vector *this);
void VectorExtendCapacity(vector *this);
void VectorInsertByIndex(vector *this, int index, void *data);
void VectorDeleteByIndex(vector *this, int index);
void VectorPopBack(vector *this);