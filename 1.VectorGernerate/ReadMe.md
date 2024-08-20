
# 利用C语言实现了任意类型的vector容器

实现了：

1. 构造函数、析构函数
2. PushBack和PopBack函数
3. Insert和Delete函数
4. 扩展容量函数和获取索引地址函数

## 注意this指针

&emsp;&emsp;实际上this在C++里面常用，对于一个类，this指针实际上是指向自身类的一个指针，实际上目前struct中只封装了属性，进一步利用**函数指针**将函数封装进来，与基本的类是等价的。

&emsp;&emsp;再将this指针隐藏（仅仅是为了简洁，可以发现，所有的函数都利用了this指针），就是一个基本类的雏形（面对对象的思想）。

## 与C++的联系
 
&emsp;&emsp;C语言中经常会用到指针的概念，但是C++几乎不会遇到指针，这是因为直接操作地址是非常不安全的，所以C++中对指针进行了封装，

例如：
1. 利用传递引用代替传递指针
2. 利用类的封装代替结构体对函数指针的封装
3. 多态本质上也是函数指针的一种应用

## 灵活应用地址

void * char * int *.....对于硬件来说，它们没有任何区别，仅仅是编译器可以通过前面的标识去解释它：

例如：
1. sizeof（char *） = sizeof（int *） = sizeof（void *）
2. char *++ = char * + sizeof（char ）、int *++ = int * + sizeof（int ），在进行自加的时候，编译器会根据类型确定不同的递增量
3. 对于同一个地址，*char 访问时会取1个字节，*int 访问时会取4个字节（depend on system）


## 原码、反码、补码

所有的数字在计算机内都是以补吗存储，`type a = num` 被汇编解释为，将num的补码存在变量`a`的地址中，位宽由type决定。

假设有
```
uint8_t a = -1;
int8_t  b  = -1;
```
赋值时：
- 第一行代码将-1转换为补码 1111 1111(0xff)，存放到a的地址中
- 第一行代码将-1转换为补码 1111 1111(0xff)，存放到b的地址中
- 前面类型仅仅决定范围，不影响上述的转换
取值时：
- 找到地址，确定数据长度，根据类型翻译
- 对于uint8_t形状，为无符号整型，补码等于原码，所以翻译为255
- 对于int8_t形状，为有符号整形，所以补码转为原码-1

![alt text](fig1.png)

## 类型决定翻译方式
显然，当有符号数大于等于0时，强转为无符号数时，不会有问题。
同理，无符号数在范围内时，也没有问题。其实`a==b`，因为不管怎么类型转换，再进行比大小的时候都会转为一个类型，用一个类型解释补码，所以一样







---
[环境配置头文件配置](https://ask.csdn.net/questions/1054690)

```  -I <dir>                Add directory to the end of the list of include search paths
  --libomptarget-amdgcn-bc-path=<value>
                          Path to libomptarget-amdgcn bitcode library
  --libomptarget-amdgpu-bc-path=<value>
                          Path to libomptarget-amdgcn bitcode library
  --libomptarget-nvptx-bc-path=<value>
                          Path to libomptarget-nvptx bitcode library
  -L <dir>                Add directory to library search path
  ```

---

- 


  ## 遇到问题
  1. 有时间报错编译一下就解决
  2. 在函数内，printf无法知道类型
  3. push_back 无法传递常量
