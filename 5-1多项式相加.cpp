#include<stdio.h>
#include<iostream>
#include <iomanip>
 using namespace std;
 typedef struct Dnode{
    double xi, zhi;
    struct Dnode *next;
 }*Linklist,Node;

 //创建
 void creatlist(Linklist L,int n){
    L ->next = NULL;
    Node *r,*s;
    s = L;
    float x,z;
    while(n-->0){
        r = new Node();
        cin>>x>>z;

        r->xi = x;
        r->zhi = z;
        s->next = r;
        s=r;
    }
    s->next = NULL;
}

Linklist he(Linklist L1,Linklist L2){    //先合并
    Node *p = new Node();
    p = L1->next;
    while(p->next!=NULL)
        p = p->next;
    p->next= L2->next;
    return L1;
}
//排序合并
void bubbleSort(Linklist mylist)
{
    if((mylist -> next == NULL) || (mylist -> next -> next == NULL))
    {
        return;
    }

    Node *head, * pre, * cur, *next, * end, * temp;
    head = mylist;
    end = NULL;
    while(head -> next != end)
    {
        for(pre = head, cur = pre -> next, next = cur -> next; next != end; pre = pre -> next, cur = cur -> next, next = next -> next)
        {
            if(cur -> zhi < next -> zhi)
            {
                cur -> next = next -> next;
                pre -> next = next;
                next -> next = cur;
                temp = next;
                next = cur;
                cur = temp;
            }
        }
        end = cur;
    }
}

void hebing(Linklist L,int n)  //合并重复指数
{   int i=0;
    Node *p,*s,*m;
    p=L;
    s = p->next;
    m = s->next;
    while(m->next!=NULL)
    {   if(s->zhi == m->zhi)
            {if(s->xi+m->xi!=0){
            s->xi = s->xi + m->xi;
            m=m->next;
            s->next = m;
            ;
            }
            else{
                p->next = m->next;s=p->next;m = s->next;i++;}
            }
        else{
           p=p->next; s=s->next;m=m->next;
        }
    }
    if(m->next==NULL){
        if(s->zhi == m->zhi)
            {if(s->xi+m->xi!=0){
            s->xi = s->xi + m->xi;

            s->next = NULL;;
            ;
            }
            else{
                p->next = NULL;
            }
    }
}}
void cha(int n,Linklist L){   //查询
    Node *s;
    s = L;
    for(int i=0;i<n;i++)
    {
        s = s->next;
    }
    cout<< fixed<<setprecision(1)<<s->xi<<' ';
    cout<<fixed<<setprecision(0)<<s->zhi;
}

/*void show(Linklist L){
    while (L->next != NULL){
        cout<<"xishu:"<<L->next->xi<<' '<<"zhishu:"<<L->next->zhi<<endl;
        L = L->next;
    }
}*/

int main(){
    Linklist L1 = new Node(),L2 = new Node();
    int n1,n2;
    cin>>n1;
    creatlist(L1,n1);
    cin>>n2;
    creatlist(L2,n2);
    int n3;
    cin>>n3;
    Linklist L3 = he(L1,L2);
    //cout<<"wei pai xu"<<endl;
    //show(L3);
    bubbleSort(L3);
    //cout<<endl<<"pai xu hou"<<endl;
    //show(L3);
    //cout<<endl<<"qu chong"<<endl;
    hebing(L3,n1+n2);
    //cout<<endl;
    //show(L3);
    cha(n3,L3);
}



