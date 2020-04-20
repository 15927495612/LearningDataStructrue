/*
 * ADT tree(树)
 * Data
 *     树是由一个根结点和若干棵子树构成。树中结点具有相同数据类型以及层次结构
 * Operation
 *     InitTree(*T);构造空树T
 *     DestroyTree(*T);销毁树
 *     CreateTree(*T,definition);按definition中给出的定义来构造树
 *     ClearTree(*T);若树存在将树清空
 *     TreeEmpty(T);若树为空树返回true，否则返回false
 *     Root(T);返回T的根节点
 *     Value(T,cur_e);cur_e是树T中一个结点，返回此结点的值
 *     Assign(T,cur_e,value);给树T的结点cur_e赋值为value
 *     Parent(T,cur_e);若cur_e是树的非根结点，返回他的双亲，否则返回空
 *     LeftChild(T,cur_e);若cur_e是树的非叶结点，返回它的最左孩子，否则人返回空
 *     RightSibling(T,cur_e);若cur_e有右兄弟，则返回它的右兄弟，否则返回空
 *     InsertChild(*T,*p,i,c);其中p指向树T的某结点，i为所指结点p的度加1，非空树c与T不向交，操作结构为插入c为树T中p指结点的第i棵子树
 *     DeleteChild(*T,*p,i);其中p指向树T的某个结点，i为所指结点p的度，操作结果为删除T中p所指结点的第i棵子树
 * EndADT
 * */

#include <stdio.h>
#include <string>
using namespace std;

/*
 * 双亲表示
 * 在每一个结点附设一个指示器指示其双亲结点到链表中的位置
 * */
#define maxSize 100

typedef int TElemTypedef;
typedef struct PTNode//结点结构
{
    TElemTypedef data;
    int parent;//指示双亲的位置

}PTNode;
typedef struct
{
    PTNode node[maxSize];
    int r,n;//根的位置和结点数
}PTree;

/*
 * 
 * */


typedef struct TreeNode
{
    int data;
    struct TreeNode * next;
    struct TreeNode * front;
}TreeNode,*LinkNode;
void main()
{

}