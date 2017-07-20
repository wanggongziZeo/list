/*films3.c--使用ADT风格的链表*/
/*和list.c一起编译*/

//通过定义接口程序，使编程细节和概念模型区分开，同时
//隐藏了细节，并用与任务直接相关的语言来表达程序。
//即他讨论的是创建列表和向列表添加项目这样的任务，


#include<stdio.h>
#include<stdlib.h>  //为exit()提供原型
#include"list.h"
//#include"list.c"

void showmovies(Item item);

int main()
{
    List movies;
    Item temp;

    /*初始化*/
    /*void InitializeList(List *plist);*/
    InitializeList(&movies);

    if(ListIsFull(&movies))
        {
            fprintf(stderr,"Nomemory available! Bye!\n");
            exit(1);
        }
    
    /*收集并存储*/
    puts("Enter first movie title:");
    while(gets(temp.title) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating<0-10>:");
        scanf("%lf",&temp.score);
        printf("a = %lf\n",temp.score);
        while(getchar() != '\n')
            continue;
        if(AddItem(temp,&movies) == false)
        {
            fprintf(stderr,"Problem allocating memory\n");
            break;
        }
        if(ListIsFull(&movies))
        {
            puts("The list is full now!");
            break;
        }
        puts("Enter next movie title(empty line to quit):");
    }

    /*display*/
    if(ListIsEmpty(&movies))
        printf("No data entered!\n");
    else
    {
        printf("Here is the list:\n");
        Traverse(&movies, showmovies);
        putchar('\n');
    }

    printf("You entered %d movies.\n",ListItemCount(&movies));

    /*清除*/
    EmptyTheList(&movies);
    printf("Bye!\n");
    
    system("PAUSE");
    return 0;
}

void showmovies(Item item)
{
    printf("Movies: %s    Score:%lf\n",item.title,item.score);
}