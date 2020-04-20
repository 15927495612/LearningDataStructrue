#include <stdio.h>
#include "iostream"
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    /* data */
}node;

typedef struct DulNode
{
    int data;
    struct DulNode *prior;
    struct DulNode *next;
    
    /* data */
}DulNode,*DuLinkList;//双向链表的节点


typedef struct Node *LinkList;//定义一个Node类型

void creatListHead(LinkList *L,int n)
{
    LinkList p;
    int i;
    //srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for(i = 0;i<n;i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;

        p->next = (*L)->next;
        (*L)->next = p;
        //p->next = (*L);创建一个循环链表

        
    }


}

bool ListInsert(LinkList *L ,int i, int e)
{
    int j;
    LinkList p,s;
    p = *L;
    j=1;
    /*for(j = 0;j<i;j++)
    {
        p = p->next;
        
        if(j==i) 
        {
            s = p->next;
            p->next = (LinkList)malloc(sizeof(Node));
            p->next->data = e;
            p->next->next = s;
        }
    }我这样写程序不够健壮*/
    while (p&&j<i)
    {
        /* code */
        p = p->next;
        ++j;
    }
    if(!p||j>i)
    {
        return false;//当没有第i个元素返回错误
    }
    s = (LinkList)malloc(sizeof(Node));//创建一个新的节点
    s->next = p->next;
    p->next = s;
    s->data = e;

    return true;//插入成功

}

bool deleteOne(LinkList *L ,int i,int *e)//通过引用传递删除的值
{
    int j;
    LinkList p,s;
    p = *L;
    j=1;
    /*for(j = 0;j<i;j++)
    {
        p = p->next;
        
        if(j==i) 
        {
            s = p->next;
            p->next = (LinkList)malloc(sizeof(Node));
            p->next->data = e;
            p->next->next = s;
        }
    }我这样写程序不够健壮*/
    while (p&&j<i)
    {
        /* code */
        p = p->next;
        ++j;
    }
    if(!p->next||j>i)
    {
        return false;//当没有第i个元素返回错误
    }
    s = p->next;
    p->next = s->next;
    *e = s->data;
    free(s);
    return true;//插入成功
}

bool GetElem(LinkList *L,int i,int *e)
{
    int j;
    LinkList p;
    p = (*L)->next;
    j= 1;
    while (p&&j<i)
    {
        p=p->next;
        /* code */
        ++j;
    }
    if(!p||j>i)
    {
        return false;//当没有第i个元素返回错误
    }
    
    *e = p->data;
    
    return true;//返回成功
    
}

bool ClearList(LinkList *L)
{
    LinkList p,q;
    while (p)
    {
        q=p->next;
        free(q);
        p=q;
        /* code */
    }
    (*L)->next = NULL;//头指针指向空
    return true;
}




