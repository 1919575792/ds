#include<iostream>
#include<stack>
#include<stdio.h>
#include<malloc.h>
using namespace std;

//创建二叉树节点类型
typedef struct Node{
    char data;
    Node *LChild;
    Node *RChild;
} BiTNode,*BiTree;


//二叉树的创建
void CreateBiTree(BiTree *bt)
{
    char ch;
    ch = getchar();
    if(ch == '#') *bt = NULL;
    else{
        *bt = (BiTree)malloc(sizeof(BiTNode));
        (*bt)->data = ch;
        CreateBiTree(&((*bt)->LChild));
        CreateBiTree(&((*bt)->RChild));
    }
}



//先序遍历
void PreOrder(BiTree r)
{
    stack<BiTNode*> S;
    BiTNode* cur = r;
    while(cur!=NULL)
    {
        cout<<cur->data<<' ';
        S.push(cur);
        if (cur->LChild!=NULL)
            cur = cur->LChild;

        else if(!S.empty()){
            while(!S.empty()){
                cur = S.top();
                S.pop();
                cur = cur->RChild;
                if(cur!=NULL) break;
        }}
        else cur=NULL;
    }
    cout<<endl;
}
//中序遍历
void InOrder(BiTree r)
{
    stack<BiTNode*> S;
    BiTNode *cur = r;
    do
    {
        while(cur!=NULL)
        {
            S.push(cur);
            cur = cur->LChild;
        }
        if (!S.empty())
        {
            cur=S.top();
            S.pop();
            cout<<cur->data<<' ';
            cur=cur->RChild;
        }
    } while (cur!=NULL||!S.empty());
    cout<<endl;
}
//后序遍历
void postOrder(BiTree r){
    if(r!=NULL){
        postOrder(r->LChild);
        postOrder(r->RChild);
        cout<<r->data<<' ';
    }
}

int main(){
    BiTree bt = new BiTNode();
    CreateBiTree(&bt);
    PreOrder(bt);
    InOrder(bt);
    postOrder(bt);
}
