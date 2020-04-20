/*
ADT 栈(stack)
Data
    与线性表相同，元素具有相同的数据类型，相邻元素具有前驱和后继的关系
Operation
    InitStack(*S);初始化栈，建立一个空栈
    DestroyStack(*S);若栈存在则销毁栈
    ClearStack(*S);将栈清空
    StackEmpty(S);若栈为空则返回true，否则返回false
    GetTop(s,*e);若栈存在且非空，用e返回栈顶元素
    Push(*s,e);若栈存在，插入新元素e到栈顶
    Pop(*s,e);删除栈s中栈顶元素，用e返回其值
    StackLength(S);返回栈S的元素个数
endADT
*/
#include <stdlib.h>
typedef int SElemType;
typedef struct StackNode  
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;

bool Push(LinkStack *s,SElemType e)
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->next = s->top;
    p->data = e;
    s->top = p;
    s->count++;
    return true;
}

bool Pop(LinkStack *s,SElemType *e)
{
    if(s->top)
    {
        LinkStackPtr p = s->top;
        *e = p->data;

        s->top = p->next;
        s->count--;
        free(p);
    }else
    {
        return false;
    }
}



