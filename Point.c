// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

#include <stdio.h>
#include <string.h>
#include <math.h>



int main()
{
   
   // 指针永远是存储一个64位（ 8Bytes）的地址， 取决于计算机硬件
   printf("%d %d %d %d\n",sizeof(int ),sizeof(int *),sizeof(int **),sizeof(int ***));
   printf("%d %d %d %d\n",sizeof(char ),sizeof(char *),sizeof(char **),sizeof(char ***));
   printf("%d %d %d %d\n",sizeof(float ),sizeof(float *),sizeof(float **),sizeof(float ***));
   // sizeof(void ) 实际上是编译器进行优化了
   printf("%d %d %d %d\n",sizeof(void ),sizeof(void *),sizeof(void **),sizeof(void ***));


   // 多级（大于2）指针没有实际意义，任何类型都等价于void 型
   unsigned int temp = 0x1234ff78;
   // 一级指针的自加，编译器会根据类型优化
   printf("temp add : %08x\n",&temp);
   printf("%x \n",&temp + 1); // temp + 1 = temp + sizeof(type(temp)) = temp + sizeof(int)<->4

   printf("temp add : %08x\n",(unsigned char *)&temp);
   printf("%x \n",(unsigned char *)&temp + 1); 

   printf("temp add : %08x\n",( char *)&temp);
   printf("%x \n",( char *)&temp + 1); 

   printf("void temp add : %08x\n",( void *)&temp);
   printf("%x \n",( void *)&temp + 1); 

   //一级指针的访问内存，编译器根据内存会优化
   printf("*(&temp) : %08x\n",*(&temp));
   printf("*(&temp) : %08x\n",*((char *)&temp));
   printf("*(&temp) : %08x\n",*((unsigned char *)&temp));

   printf("*(&temp) : %08x\n",*(&temp));
   printf("*(&temp) : %d\n",*((char *)&temp + 1));
   printf("*(&temp) : %08x\n",*((unsigned char *)&temp + 2));
   printf("*(&temp) : %08x\n",*((char *)&temp + 3));

   printf("*(&temp) : %08x\n",*((unsigned char *)&temp + 2));
//    printf("*(&temp) : %08x\n",*((void *)&temp));

    unsigned int *p = &temp;
    unsigned int **p2 = &p;
    // 二级指针，自加永远是加1
    // 都是加8，因为地址都是占8个bytes，所有的指针都是

    printf("%x %x %x %x\n",p2,p2+1,(unsigned char **)p2 +1,(void **)p2 + 1);





   return 0;
}

 