#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ok 1;
#define error 0;

typedef struct
{
    char name[100];
}ElemType;

typedef struct
{
    ElemType * elem;
	int length;
    int listsize;
}List;

int InitList(List &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)
        return error;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return ok;
}//初始化

int ListInsert(List &L,int i,ElemType e)
{
    ElemType *p;
    if(i<1||i>L.length+1)
        return error;
    if(L.length>=L.listsize)
    {
        ElemType *newbase;
        newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)
            return error;
		L.elem=newbase;
		L.listsize+=LISTINCREMENT;
    }
    ElemType *q = &(L.elem[i-1]);
    for(p = &(L.elem[L.length-1]);p>=q;--p)
        *(p+1)=*p;

    *q=e;
    ++L.length;
    return ok;
}//插入

int ListDlete (List &L,int i,ElemType e)
{
    ElemType *p,*q;
    if(i<1||i>L.length)
        return 0;

    p=&(L.elem[i-1]);
    e=*p;
    q=L.elem+L.length-1;
    for(++p;p<=q;++p)
    {
        *(p-1)=*p;
    }
    --L.length;
    return ok;
}
int LocateElem(List L,ElemType e,int(*compare)(ElemType,ElemType)) //compare 是啥
{
    int i;
    ElemType *p;
    i=1;
    p=L.elem;
    while(i<=L.length&&!(*compare)(*p++,e))
        ++i;
    if(i<=L.length)
        return i;
    else
        return error;
}


void listshow(List L)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(i)
            cout<<' ';
        cout<<L.elem[i].name;
    }
    cout<<endl;
}
int cmp(ElemType e1, ElemType e2)
{
       return (int)!strcmp(e1.name, e2.name);
}
int main ()
{

    List nameList;
    InitList(nameList);
    char mingling[10];
    int number;
    ElemType e;
    
    while(scanf("%s",mingling)!=EOF)
    {

        if(strcmp(mingling,"insert")==0)
        {
            cin>>number>>e.name;
            ListInsert(nameList,number,e);
        }
        else if(strcmp(mingling,"show")==0)
            listshow(nameList);
        else if(strcmp(mingling,"delete")==0)
        {
            cin>>e.name;
            number=LocateElem(nameList,e,cmp);
            ListDlete(nameList,number,e);
        }
        else if(strcmp(mingling,"search")==0)
        {
            cin>>e.name;
            cout<<LocateElem(nameList,e,cmp)<<endl;
        }
    }
    return 0;
}

