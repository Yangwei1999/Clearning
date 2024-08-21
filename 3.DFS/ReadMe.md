
# 利用vector 重新组合，


- [ ] 复习二级指针的内容，
- [x] 复习下C中的DebugPrintf
- [ ] 完成组合的dfs算法书写
- [x] int *p,a;还是 int *p,*pal


## 排列组合问题，好好复习下


## C语言中自定义Print，一键取消的方法

```c
#ifdef DEBUG
    #define DEBUG_PRINT(fmt, args...)    printf("DEBUG: " fmt, ## args)
#else
    #define DEBUG_PRINT(fmt, args...)    // 空实现，不打印
#endif
```
```c
甚至可以
// 使用条件编译或条件语句来处理不同的调试级别
#ifdef DEBUG_LEVEL
    #if DEBUG_LEVEL == 1
        #define DEBUG_PRINT(fmt, args...)    printf("DEBUG LEVEL 1: " fmt, ## args)
    #elif DEBUG_LEVEL == 2
        #define DEBUG_PRINT(fmt, args...)    printf("DEBUG LEVEL 2: " fmt, ## args)
    #elif DEBUG_LEVEL == 3
        #define DEBUG_PRINT(fmt, args...)    printf("DEBUG LEVEL 3: " fmt, ## args)
    #else
        #define DEBUG_PRINT(fmt, args...)    // 未定义调试信息
    #endif
#else
    #define DEBUG_PRINT(fmt, args...)        // 未定义调试信息
#endif
```

在代码中可以直接将宏定义或者注释，实现打印的一键消失。 

## 指针的普通变量不要混合声明

正确的做法为：
```c
int *a, *c; // 声明了两个指针 a 和 c
int b, d;   // 声明了两个普通整数 b 和 d
```
## 二级指针

1. 一级指针的所有sizeof 都为一个字节，原因是所有的一级指针变量都是存放的地址（取决于操作系统）——基线地址，一般是一个字节。但是类型的不同会导致解释方式不同，int会取4个字节，char 取1个字节等等
2. 二级指针所有的sizeof 仍然为一个字节，二级指针仍然是存放一个地址（一级指针的地址），
3. 多级指针类似，不管多少级，永远是存放一个地址，再最后一级时，会根据类型翻译需要取的地址长度

## 指针偏移

1. 根据上面的原则，所有大于二级的指针++，都是+1
2. 一级指针++等于  sizeof（type）

- 所以可以通过二级指针取管控二位数组，但是需要自己计算偏移量（把二维）

- 数组指针实际上就是二维指针，但是 p++ = p + sizeof(给出的二维*类型长度)，仅仅限定了这个

- 预定义的二维数组本质上是一维数组，地址是连续的

- 但是malloc分配二维数组时，往往第二个维度不连续，这种只能通过二维指针去访问，而不能通过数组指针（可以方便访问连续的二维数组）


