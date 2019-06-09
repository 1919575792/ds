#include<iostream>
#include<stack>
#include<stdio.h>
#include<malloc.h>
using namespace std;
int leafCount = 0;
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
int leaf(BiTree r){

    if(r!=NULL){
        leaf(r->LChild);
        leaf(r->RChild);
        if(r->LChild == NULL && r->RChild==NULL)
            leafCount++;
    }
    return leafCount;
}
void swap1(BiTree node){
    if(node!=NULL){
        swap1(node->LChild);
        swap1(node->RChild);
        BiTNode *t=node->LChild;
        node->LChild=node->RChild;
        node->RChild=t;
    	}
    }
void postOrder(BiTree r){
    if(r!=NULL){
        postOrder(r->LChild);
        postOrder(r->RChild);
        cout<<r->data;
    }
    else
        cout<<'#';
}
int main(){
    BiTree bt = new BiTNode();
    CreateBiTree(&bt);
    cout<<leaf(bt)<<endl;
    swap1(bt);
    postOrder(bt);



}
