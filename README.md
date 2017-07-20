# 构造接口
## 借口头文件

## 简单列表的构造有两部分
*   描述数据如何表示
*   描述实现ADT操作的函数

### 接口的设计应和ADT的描述尽可能的保持一致，因此，应该用某种通用的Item类型来进行表达，而不是用诸如int或struct film之类的专用类型，这样的做法之一是使用C的typedef工具将Item定义为所需类型。
*   typedef struct film Item；
### 然后可以在其余的定义中使用Item类型。

## 在链表的结构中，每一个链接被称为一个节点（node），每一个节点包含形成列表内容的信息和指向下一节点的指针。为了管理链表，需要一个指向其开始处的指针，通过typedef是List成为只想Node类型的指针的名称。
*   typedef Node *List;  
### 因此
*   List movies；  
### 的声明表明movies是一个适合指向链表的指针。

只有IntiializeList()、AddItem()和EmptyTheList()函数修改列表，因此，从技术上讲，只有这些方法需要一个指针参数。然而，如果用户必须记住吧一个List参数传递给某个函数并把一个List的地址作为参数传递给另外一个函数，这很容易混淆。因此，为了简单化，所有的函数都是使用指针参数。

## 程序流程
*   接口定义（list.h）
*   使用接口（films3.c）
*   实现接口（list.c）

在list.c中集中进行函数定义。  
## 整个程序由三个文件组成
*   list.h  定义数据结构并为用户接口提供原型
*   list.c  提供函数代码实现接口
*   films3.c  将接口列表应用于具体的编程问题的源代码文件。

# 多源代码文件程序的编译
    windows系统下的编译器是面向工程的。工程描述了一个特定的程序使用的资源。这些资源中包括源代码文件。使用这种编译器运行单文件程序时，必须创建工程。而对于多文件工程，需要使用相应的菜单命令将源代码文件加入到一个工程之中。而且，工程必须包括所有的源代码文件（扩展名为.c文件）。但是，头文件（扩展名为.h文件）不能包含在工程中。因为工程只管理所使用的源代码文件，而使用哪些头文件需要由源代码文件中的#include指令确定。