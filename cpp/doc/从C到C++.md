# 从C到C++
- [从C到C++](#从c到c)
  - [数据的输入与输出](#数据的输入与输出)
  - [变量的初始化](#变量的初始化)
  - [引用](#引用)
  - [特殊函数](#特殊函数)
    - [函数的默认参数](#函数的默认参数)
    - [函数的重载](#函数的重载)
  - [命名空间](#命名空间)
  - [动态内存分配](#动态内存分配)
  - [基本数值类型的扩展](#基本数值类型的扩展)

## 数据的输入与输出

```cpp
    double number;
    char str[100];
    double list[2] = {1.0, 2.0};
    
    cin >> number >> str;
    cout << number << endl;//根据变量类型打印，不用写格式控制符，如%d,%s
    cout << str << endl;
    cout << list; //无法打印数组
```

## 变量的初始化

- 变量和对象可以用原括号()来初始化
- c++11任何类型可以用花括号{}来初始化

```cpp
    //变量初始化
    double number = 3.14;     //C风格的初始化
    double numberNew(3.1415); //C++风格，用圆括号替代等号来初始化
    double numberNew1 = {3.1415926}; //C++风格，用花括号替代等号来初始化
    double numberNew2{3.1415926}; //C++风格，同上一条，只是省略花括号
    
    //数组初始化
    double list[2] = {1.0, 2.0};//C++风格，用花括号来初始化
    double listNew[2]{1.1, 2.1}; //不支持用圆括号来初始化
    double listNew1[2] = {}; //花括号中为空，则数组元素全部初始化为0

```


## 引用

> 某个变量的引用就是变量的别名，修改引用的值等价于修改这个变量。典型用法是作为函数参数。
引用类似于const指针，必须在创建应用时对其初始化。

```cpp
//引用类似于const指针，即固定指向某对象的指针
int rat;
int & ratRef = rat;//必须在创建应用时对其初始化
int * const prat = &rat;//引用ratref与表达式*prat的含义一致
```

```cpp
//引用作为函数参数
int swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}
```

## 特殊函数

### 函数的默认参数

与python中默认参数用法类似。默认参数定义在函数的声明中，**不能定义在函数实现中。默认参数必须放在无默认参数的右边**。

```cpp
int swap
```

### 函数的重载

>函数名与返回值类型相同，但是函数参数不同。

例如，参数个数与参数类型不同。当时返回值类型不同，不算是函数的重载，因为编译时无法根据实参类型来判断应该调用哪个函数。

## 命名空间

## 动态内存分配
c语言由free和malloc函数来实现堆区的内存分配，申请的内存大小需要通过函数形参传递。
```c
#include <stdlib.h> //malloc, free
// function prototype
void * malloc(size_t size)//内存申请成功返回其首地址，申请失败返回NULL
void free(void *ptr)

// example
int *p=malloc(sizeof(int));
...
free(p);
p=NULL;
```
c++中由new和delete运算符来实现堆区的内存分配
```cpp
int p=new int;
delete p;

int list=new int[10];//申请动态数组
delete [] list;
```

## 基本数值类型的扩展

- 整数类型的上下限定义在头文件**climt**中，浮点型的上下限定义在头文件**cfloat**中

```cpp
/* Maximum and minimum values for ints.
 */
#define INT_MAX		2147483647
#define INT_MIN		(-INT_MAX-1)
```

- 编程中可以用**sizeof()**运算符来确定某个类型或者某个变量占用的字节数

```cpp
#include <climit>
int a = INT_MAX;
cout << sizeof(a) << endl;//计算存储变量a占用的字节数，实测为4
cout << sizeof(long double) << endl;//long double为c++扩充的基本类型，实测占用12字节
```
