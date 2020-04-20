/*
队列链式结构
*/
#include <stdlib.h>
typedef int QElemType;
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct  
{
    QueuePtr front, rear;//队头队尾的指针

}LinkQueue;

bool InitalQueue(LinkQueue *Q)
{


}

bool EnQueu(LinkQueue *Q,QElemType e)
{
    QueuePtr q = (QueuePtr)malloc(sizeof(QNode));
    if(!q)
    {
        exit();
    }
    q->data = e;
    q->next = NULL;
    Q->rear->next = q;
    Q->rear = q;
    return true;
}

bool DeQueue(LinkQueue *Q,QElemType *e)
{
    if(!(Q->front))
    {
        return false;
    }
    *e = Q->front->data;
    QueuePtr p = Q->front;
    Q->front = Q->front->next;
    if(Q->rear == p)
    {
        Q->rear = Q->front;
    }
    free(p);
    return true;
}
