/*list.c--实现文件*/
#include<stdio.h>
#include<stdlib.h>
#include"list.h"

/*局部函数原型*/
static void CopyToNode(Item item,Node * pnode);
//具有内部链接的函数，该函数是实现的一部分但不是接口的一部分。
//只在定义他的文件中可见

/*接口函数*/
/*吧列表设置为空列表*/
void InitializeList(List *plist)
{
    *plist = NULL;
}

/*如果列表为空则返回true，否则返回false*/
//这个函数不改变列表，不需要传递指针参数，参数可以
//设置为List类型而不是指向List的指针
// 电子科技大学出品

bool ListIsEmpty(const List *plist)
{
    if(*plist == NULL)
        return true;
    else
        return false;
}

/*如果列表已满则返回true*/
/*这一段不大懂了*/
bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;
    
    //列表的大小受可用内存数量的限制。尝试为一个新项目分配足够的空间，
    //如果分配失败，则说明列表已满
    pt = (Node *)malloc(sizeof(Node));
    if(pt == NULL)
        full = true;
    else 
    //如果分配内存成功，就需要释放刚分配的内存以使其为真正的项目所用
        full = false;
    free(pt);
    return full; 
}

/*返回节点数*/
unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    Node * pnode = *plist;/*设置到列表开始处*/

    while(pnode != NULL)
    {
        ++count;
        pnode = pnode->next;
        //*plist = (*plist)->next不能这么实现，plist是const
        //但是这并不是说*plist指向的数据是const，所以，以下代码是可以得
        //(*plist)->item.rating = 3，此代码并没有改变*plist,只是改变
        //了*plist所指向的数据
    }
    return count;
}

/*创建存放项目的节点，并把它添加到*/
/*由plist指向的列表（较慢的实现方法）尾部*/
bool AddItem(Item item,List *plist)
{
    Node *pnew;
    Node *scan = *plist;//用于分析列表是否为空
    //若列表为空，则添加的内容放到列表开头，头则追加

    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL)    //分配内存失败
        return false;   //失败时推出函数
    CopyToNode(item,pnew);
    pnew->next = NULL;
    if(scan == NULL)    //空列表
        *plist = pnew;
    else
        {
            while(scan->next != NULL)//寻找列表尾部
                scan = scan->next;
            scan->next = pnew;
        }
    return true;
}

/*访问每个节点，并对他们分别执行由pfun指向的函数*/
void Traverse(const List *plist, void (*pfun) (Item item))
{
    Node *pnode = *plist;   //设置到列表开始处
    while(pnode != NULL)
    {
        (*pfun) (pnode->item);  //把函数作用到列表中的项目
        pnode = pnode->next;
    }
}


/*释放由malloc分配的内存，并把列表指针设置为NULL*/
void EmptyTheList(List *plist)
{
    Node *psave;
    while(psave != NULL)
    {
        psave = (*plist)->next;    //因为要释放掉（*plist），所以要保存下一个节点
        free(*plist);             //释放当前结点
        *plist = psave;           //前进到下一个节点
    }
}


/*局部函数定义*/
static void CopyToNode(Item item,Node * pnode)
{
    pnode->item = item;
}