#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
};//链表

Node * hebing(Node *head1 , Node *head2)
{
  if ( head1 == NULL )
    return head2 ;
  if ( head2 == NULL)
    return head1 ;
  Node *p = new Node() ;
  if ( head1->data < head2->data )
  {
    p = head1 ;
    p->next = hebing(head1->next,head2);
  }

  else if(head1->data > head2->data)
  {
    p = head2;
    p->next = hebing(head2->next,head1);

  }

  else if(head1->data == head2->data)
  {
    p = hebing(head2->next,head1);
  }

  return p ;
}
Node *creatLink(int a[],int n)
{
        Node *p=new Node();
        p->data=a[0];
        Node *tail=p;
        p->next=NULL;
        for(int i=1;i<n;++i)
        {
               Node *temp=new Node();
               temp->data=a[i];
               temp->next=NULL;
               tail->next=temp;
               tail=tail->next;
        }
        return p;
}
int main()
{
        int a[50],b[50],i=0,len1=0,len2=0;
        cin>>len1;
        for(i=0;i<len1;i++){
        cin>>a[i];}
        cin>>len2;
        for(i=0;i<len2;i++){
        cin>>b[i];}
       
		Node *headA=creatLink(a,len1);
        Node *headB=creatLink(b,len2);
        Node *h= hebing(headA,headB);
        while(h)
        {
               cout<<h->data<<" ";
               h=h->next;
        }
}
