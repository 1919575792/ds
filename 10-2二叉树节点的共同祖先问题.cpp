#include<iostream>
#include<malloc.h>
#include<cstring>
using namespace std;
typedef struct Node{
    char data;
    struct Node *LChild;
    struct Node *RChild;
}BiTNode,*BiTree;


BiTree createBiTree(char *pre, char *in, int n)//pre存放前序序列，in存放中序序列，n为序列的长度
{
    int i=0;
    int n1=0,n2=0;
    int m1=0,m2=0;
    BiTree node = NULL;
    char lchild_pre[50],rchild_pre[50] ;//lchild_pre[N] 存放前序序列中的左子树；rchild_pre[N]存放前序序列中的右子树
    char lchild_in[50],rchild_in[50]; //lchild_in[N]存放中序序列中的左子树；rchild_in[N]存放中序序列中的右子树
    if(n==0)
    {
        return NULL;
    }
    node = (BiTree)malloc(sizeof(BiTNode));
    if(node==NULL)
    {
        return NULL;
    }
    node->data = pre[0]; //前序序列的第一个元素一定是根节点
    for(i=0; i<n; i++)
    {
        //求前序序列中的左子树和右子树
        if((i<=n1)&&(in[i]!=pre[0]))
        {
            lchild_in[n1++]=in[i];
        }
        else if(in[i]!=pre[0])
        {
            rchild_in[n2++] = in[i];
        }
    }
    for(i=1; i<n; i++)
    {
        //求中序序列中的左子树和右子树
        if(i<(n1+1))
        {
            lchild_pre[m1++]=pre[i];
        }
        else
        {
            rchild_pre[m2++]=pre[i];
        }
    }
    //使用递归，分别插入左子树和右子树
    node->LChild =createBiTree(lchild_pre,lchild_in,n1);
    node->RChild =createBiTree(rchild_pre,rchild_in,n2);
    return node;
}

BiTNode* Getcestor(BiTNode* root, BiTNode* node1, BiTNode* node2)
{
    if(root == NULL || node1 == NULL ||  node2 == NULL) return NULL;
    if(root->data == node1->data || root->data == node2->data) return root;
    BiTNode *left = Getcestor(root->LChild,node1,node2);
    BiTNode *right = Getcestor(root->RChild,node1,node2);
    //如果左右子树都能找到，那么当前节点就是最近的公共祖先节点
    if(left != NULL && right != NULL) return root;
    //如果左子树上没有，那么返回右子树的查找结果
    if(left == NULL) return right;
        //否则返回左子树的查找结果
    else return left == NULL && right == NULL ? NULL : left;
    }

BiTree findnode(BiTree root,char a){
    if(root == NULL)
        return NULL;
    if(root->data == a)
        return root;
    else {
        BiTree temp;
        temp = findnode(root->LChild,a);
        if(temp==NULL)
            return findnode(root->RChild,a);
        return temp;
    }
}

int main(){
    char pre[1000],in[1000];
    char a1,a2;
    cin>>pre>>in>>a1>>a2;
    int n = strlen(pre);
    if( n == 1) {cout<<"NULL";return 0;}
    else{
        BiTree t = createBiTree(pre,in,n);
        BiTNode fir = *findnode(t,a1);
        BiTNode sen = *findnode(t,a2);
        BiTNode * G = Getcestor(t,&fir,&sen);
        if(G!=NULL)
            cout<<G->data;}

}








