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

//使用顺序存储实现栈的结构
#define MaxSize  100
typedef int SElemType;

typedef struct 
{
    SElemType data[MaxSize];
    int top;
}SqStack;

bool push(SqStack *s,SElemType e)
{
    if((s->top+1)<MaxSize)
    {
        s->top = s->top+1;
        s->data[s->top] = e;
    }else
    {
        return false;
    }
    return true;

}

bool pop(SqStack *s,SElemType *e)
{
    if(s->top>=0)
    {
        *e = s->data[s->top];
        s->top = s->top -1;

    }else
    {
        return false;
    }
    return true;
    
}

typedef struct 
{
    /* 两栈共享空间 */
    SElemType data[MaxSize];
    int top1;//栈1的顶
    int top2;//栈2的顶
}SqDoubleStack;

bool DoubleStackPush(SqDoubleStack *s,SElemType e,int stackNumber)
{
    if((s->top1+1) == s->top2)
    {
        return false;
    }else if(stackNumber == 1)
    {
        s->top1 = s->top1+1;
        s->data[s->top1] = e;
        /* code */
    }else if(stackNumber == 2)
    {
        s->top2 = s->top2-1;
        s->data[s->top2] = e;
    }
    return true;
    
}

bool DoubleStackPop(SqDoubleStack *s,SElemType *e,int stackNumber)
{
    if(stackNumber==1){
        if(s->top1>=0)
        {
            *e = s->data[s->top1];
            s->top1 = s->top1 -1;

        }else
        {
            return false;
        }
    }
    if(stackNumber==2){
        if(s->top2<=MaxSize-1)
        {
            *e = s->data[s->top2];
            s->top2 = s->top2 -1;

        }else
        {
            return false;
        }
    }
    return true;

}
