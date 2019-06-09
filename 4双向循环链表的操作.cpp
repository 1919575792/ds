#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct Dnode {
    int n;
    struct Dnode *primer,*next;
}Node,*LinkList;
void creatlist(LinkList L,int n){
    L ->next = L;
    L ->primer = L;
    Node *s,*r;
    s=L;  //s永远指向最后一个
    for(int i=1;i<=n;i++)
    {
        r = new Node();
        cin>>r->n;
        s->next = r;
        r->primer = s;
        r ->next = L;
        L ->primer = r;
        s = r;
    }
}
void shancha(LinkList L,int n){
    Node *temp;
//删除头节
    temp = L->next;
    L->next = L->next->next;
    L->next->next->primer = L;

//插入
    Node *T;
    T = L->next;
    T->primer = L;
    //L->n = 100;
    int i ;
    for(i = 1;i<n-1;i++){
        if(T->n < temp->n)
        {
            T = T->next;
        }
        if(T->n >= temp->n){
            T->primer->next = temp;
            temp->primer = T->primer;
            temp->next = T;
            T->primer = temp;
            return;}
        }
    if (i==n-1){
        temp->next = L;
        L->primer=temp;
        T->next= temp;
        temp->primer = T;
        }return;
}
int main(){
    int n;
    LinkList L  = new Node();
    cin>>n;
    creatlist(L,n);
    shancha(L,n);
    int i=0;
    Node *s = L->next;
    while(s!=L){
        cout<<s->n<<' ';
        s=s->next;i++;
    }
}

