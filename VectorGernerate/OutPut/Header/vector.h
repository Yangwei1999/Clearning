

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
void * GetIndex(vector *this,int index);
void VectorPrint(vector *this);