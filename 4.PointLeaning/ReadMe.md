
# 指针小结

记录关于多级指针的使用和一些理解


## 关于多级指针

   指针（不论多少级）永远是存储一个64位（ 8Bytes）的地址， 取决于计算机硬件是32位还是64位（居多），实际上是地址线的个数，
   
   **牢记：指针=存储一个64位的地址**
```c
   printf("%d %d %d %d\n",sizeof(int ),sizeof(int *),sizeof(int **),sizeof(int ***));
   printf("%d %d %d %d\n",sizeof(char ),sizeof(char *),sizeof(char **),sizeof(char ***));
   printf("%d %d %d %d\n",sizeof(float ),sizeof(float *),sizeof(float **),sizeof(float ***));
   // sizeof(void ) 实际上是编译器进行优化了
   printf("%d %d %d %d\n",sizeof(void ),sizeof(void *),sizeof(void **),sizeof(void ***));
   结果：
    4 8 8 8
    1 8 8 8
    4 8 8 8
    1 8 8 8

```
可以看到，不同类型的指针，实际上大小是一样的，因为指针就是存放一个地址，只是指向的位置不同`int *a = &b`为定义一个指针变量存在变量`b`的地址，`int **c = &a`代表定义一个指针指向一个指针变量的地址，之所要有两个**，一个是方便阅读，很明显c为指针的指针，a为变量的指针。另一个是编译器知道如何优化它，例如，*a，编译器解释为访问a中存储的地址对应的变量，*c为访问一个指针变量，**c访问一个变量。

---


多级（大于2）指针没有实际意义，任何类型都等价于void 型，本质上

## 一级指针
**一级指针的自加，编译器会根据类型优化**
`temp + 1 = temp + sizeof(type(temp))`

```c
   unsigned int temp = 0x1234ff78;
   printf("%08x %08x\n",&temp，&temp + 1);
   printf("%08x %08x\n",(unsigned char *)&temp);
   printf("%08x %08x\n",( char *)&temp，( char *)&temp + 1);
   printf("%08x %08x\n",( void *)&temp，( void *)&temp + 1);
   printf("%x \n",( void *)&temp + 1); 
```

**一级指针的访问内存，编译器根据内存会优化**
  ```c
   // unsigned int temp = 0x1234ff78;
   printf("*(&temp) : %08x\n",*(&temp));
   printf("*((unsigned char *)&temp): %x\n",*((unsigned char *)&temp));
   printf("*((unsigned char *)&temp + 1) : %x\n",*((unsigned char *)&temp + 1));
   printf("*((unsigned char *)&temp + 2) : %x\n",*((unsigned char *)&temp + 2));
   printf("*((unsigned char *)&temp + 3) : %x\n",*((unsigned char *)&temp + 3));
    // 所以一种访问的方式可以是
   res：
    *(&temp) : 1234ff78
    *((unsigned char *)&temp): 78
    *((unsigned char *)&temp + 1) : ff
    *((unsigned char *)&temp + 2) : 34
    *((unsigned char *)&temp + 3) : 12
  ```
**多级指针的自加，永远是+8**
因为指针变量永远占8个byte

```
 printf("%x %x %x %x\n",p2,p2+1,(unsigned char **)p2 +1,(void **)p2 + 1);
 6fdff3f0 6fdff3f8 6fdff3f8 6fdff3f8
```


## 数组指针`(*p1)[n]`和二维指针`**p2`的区别

在传递一维数组的时候，我们往往将其传递给一个一维指针变量，想当然，传递二维数组的时候，我们往往想是否应该将二维数组传递给一个二维指针？

先说一下区别：
1. p1++ = sizeof(int or ...) * n;
2. p2++ = p2 + 8(depend on your system)

其实不该定义为数组指针，因为它要求第二个维度是固定的，比较固定，二维指针处理就很灵活，不需要在函数中固定
直接上代码：

需要需要打印一个m*n 的矩阵，那么如果传递二维指针

```
void PrintMatrix1(int p[][3], int m , int n)
{

   for(int i = 0 ; i < m ; i++)
   {
      for(int j = 0 ; j < n ; j++)
      {
         printf("%d ",*(*(p+i)+j));
      }
      printf("\n");
   }
}

void PrintMatrix2(int *p, int m , int n)
{

   for(int i = 0 ; i < m ; i++)
   {
      for(int j = 0 ; j < n ; j++)
      {
         // 以下就是int p[][3]做的操作，也就是为什么需要第二个维度的原因
         printf("%d ",*(p + n*i + j));

         // printf("%x ",(int *)p + n*i + j);
         // printf("%x ",*(p+n*i*1) + j);
         // printf("%d\n",sizeof(int *));  
      }
      printf("\n");
   }
}
// 使用二级指针的话 复杂些，原理一样
void PrintMatrix3(int **p, int m , int n)
{
   int *BaseLine = p;
   p = (int **)malloc(sizeof(int *) * m);
   for(int i = 0 ; i <m ; i++)
   {
      p[i] = BaseLine + n * i;
   }
   for(int i = 0 ; i < m ; i++)
   {
      for(int j = 0 ; j < n ; j++)
      {
         printf("%d ",p[i][j]);
      }
      printf("\n");
   }
   free(p);
}
```



一般如果是malloc分配的二维数组，就方便用二级指针去控制，p[i][j] 动态分配，不然就一级指针就可以

**二级指针实际上就是指针数组不能动态分配的缺点，不然用指针数组也是一样的**

二级指针如果要指向二维数组，一定要将各数组的首地址作为值初始化二级指针。


## 思考

我本来想通过计算偏移量将`**p`指向一个二维数组`a[m][n]`，但是存在一些问题：
1. p本身没有分配内存，无法存储地址，导致无法访问数组a
2. 在这种情况下`p`可以当作一维数组使用
3. 如果使用`*(*(p+a)+b)`的形式，显然是错误的，因为`*(*(p+a)+b)`就已经是一个变量的，而不是一个地址了，再次取*会导致将这个变量的值当作地址去访问，会导致内存泄漏（红线）