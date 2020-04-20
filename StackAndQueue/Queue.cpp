/*
ADT 队列 Queue
    同线性表，元素有相同的数据类型，相邻的元素具有前驱和后继的关系
Operation
    InitQueue(*Q);//初始化操作，建立一个空队列Q
    DestroyQueue(*Q)://若队列存在则销毁队列
    ClearQueue(*Q);//将队列清空
    QueueEmpty(Q);//若队列为空则返回true，否则返回false
    GetHead(Q,*e);//若队列存在，则用e返回队列头元素
    EnQueue(*Q,e);若队列Q存在，插入新元素e之队尾
    DeQueue(*Q,*e);删除队列的头元素，用e返回其值
    QueueLength(Q);返回队列Q的元素个数

endADT
*/
#define maxSize 100
typedef int QElemType;
typedef struct 
{
    QElemType data[maxSize];
    int front;
    int rear;
}SqQueue;

bool InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return true;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + maxSize) % maxSize;
}

bool EnQueue(SqQueue *Q,QElemType e)
{
    if((Q->rear+1)%maxSize == Q->front)
    {
        return false;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % maxSize;
    return true;
}

bool DeQueue(SqQueue *Q,QElemType *e)
{
    if (QueueLength(*Q)>0)
    {
        *e = Q->data[Q->front];
        Q->front =( Q->front+1)%maxSize;
    }else
    {
        return false;
    }
    return true;
}

