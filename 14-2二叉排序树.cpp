#include <iostream>
#include <cstdlib>
using namespace std;
int depth = 0;
//二叉排序树的存储结构同二叉树
typedef struct node{
    int key;  // 为所存储的值类型
    struct node *lchild,*rchild;
}BSTNode,*BSTree;

//二叉排序树插入的递归算法
void InsertBST(BSTree *bst, int key){

    if(*bst ==NULL)
    {
        BSTNode *s = new BSTNode();
        s->key = key;
        s->lchild = NULL;
        s->rchild = NULL;
        *bst = s;
    }   // 如果索要插入的数为空树 ， 则创建树（讲元素放入头结点）
    else if(key < (*bst)->key)
        InsertBST(&((*bst)->lchild),key);
    else if(key > (*bst)->key)
        InsertBST(&((*bst)->rchild),key);
}

//创建二叉排序树*/
void createBST(BSTree *bst){
    int key;
    *bst = NULL;
    cin>>key;
    while(key != 0){  //0为终止符
        InsertBST(bst,key);
        cin>>key;
    }
}//  利用递归

//二叉排序树的删除
BSTNode *delBST(BSTree t, int k){
    BSTNode *p,*f,*s,*q;
    p = t;f = NULL;
    while(p){
        if(p->key == k) break;
        f=p;
        if(p->key >k) p=p->lchild;
        else p =p->rchild;
    }  //找到待删字节  f为待删节点p的父母节点

    if (p == NULL) return t;  //如果没有找到待删字节，则直接返回

    if(p->lchild == NULL){  //如果待删字节的左孩子为空
        if(f == NULL) t=p->rchild;  //p为根，且没有左子树，则t为p的右子树
        else if(f->lchild == p) f->lchild = p->rchild;//若p不是根，则让p的右子树等于f的左子树
        else
            f->rchild = p->rchild;
        free(p);
    }
    else{ //p既有左子树也有右子树
        q = p;s = p->lchild;
        while(s->rchild){
            q = s;
            s = s->lchild;
        }  // 找到p的直接前驱s
        if(q == p) q->lchild = s->lchild;
        else q->rchild =s->rchild;
        p->key = s->key;
        free(s);
    }
    return t;
}

void show(BSTree bst) // 中序遍历展示结果
{
    if(bst!=NULL){
        show(bst->lchild);
        cout<<bst->key<<' ';
        show(bst->rchild);
    }
}

void deep(BSTree t,int m){  //求m在t中的层数
    if(t!=NULL){
        depth ++;
        if (m < t->key && (t->lchild!=NULL)){
             deep(t->lchild,m);
        }
        else if (m > t->key  && (t->rchild!=NULL)){
            deep(t->rchild,m);
        }
    }
}

int main(){
    BSTree *t = new BSTree();
    int n,m;
    createBST(t);
    cin>>n>>m;
    BSTree  q = delBST(*t,n);
    show(q);
    deep(q,m);
    cout<<endl<<depth;
}