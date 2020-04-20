//
// Created by 19852 on 2020/4/20.
//
/*
 * 二叉树链表结构定义
 * */
using namespace std;
typedef struct BiTNode
{
    char data;
    struct BiTNode * lchild,*rchild;

}BiTNode,*BiTree;

void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    printf("%c",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)
{
    if(T==NULL)
        return;
    InOrderTraverse(T->lchild)
    printf("%c",T->data);
    InOrderTraverse(T->rchild)
}

void PostOrderTraverse(BiTree)
{
    if(T==NULL)
        return;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    printf("%c",T->data);
}

void CreatBiTree(BiTree *T)
{
    char ch;
    scanf("%c",&ch);
    if(ch=="#")
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTree));
        if(!*T)
        {
            exit();
        }else
        {
            (*T)->data = ch;
            CreatBiTree(&(*T)->lchild);
            CreatBiTree(&(*T)->rchild);
        }
    }
}

typedef enum {Link,Thread} PointerTag;
typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild,*rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiTree,*BiThrTree;
BiThrTree pre;//始终指向刚刚访问过的结点
/***********        中序遍历线索化          ****************/
void InThreading(BiThree p)
{
    if(p)
    {
        InThreading(p->lchild);
        if(!p->lchild)//没有左孩子
        {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if(!pre->rchild)//前驱没有右孩子
        {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

bool InOrderTraverse_Thr(BiThTree T)//遍历树
{
    BiThtree p;
    p = T->lchild;
    while(p!=T)
    {
        while(p->LTag == Link)//LTag==0循环至中序序列第一个结点
            p = p->lchild;

        printf("%c",p->data);
        while(p->RTag==Thread&&p->rchild!=T)
        {
            p = p->rchild;
            printf("%c",p->data);

        }
        p = p->rchild;
    }
    return true;
}

