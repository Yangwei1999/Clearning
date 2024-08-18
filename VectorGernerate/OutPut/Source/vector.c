
#include <string.h>
#include <stdlib.h>


void  swap(void *a,void *b,int Size_)
{
    void *temp = (void *) malloc(Size_);

    memcpy(temp,a,Size_);
    memcpy(a,b,Size_);
    memcpy(b,temp,Size_);

    free(temp);

   
}