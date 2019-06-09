#include<stdio.h>
#include<iostream>
 using namespace std;
 typedef struct {
    char a[1000];
    int top;
 }SeqStack;

 void InitStack(SeqStack *s){
    s->top = -1;
}
 void push(char b[],SeqStack *S){

    int i =0;
    while(b[i]!='&' && S->top <= 1000){
        S->top++;
        S->a[S->top] = b[i];i++;}

        int n = S->top+1;
        int t = 1;
        i++;
    while(S->top>-1){
            if(b[i++] == S->a[S->top]) S->top--;
            else{
                t=0;
                cout<<"no";
                break;
            }}
     if(t==1) cout<<n;
    }
int main(){
    SeqStack *s;
    s=new SeqStack();
    char a[2000];char b=' ';
    int i = 0;
    while(b!='@')
    {
        cin>>b;
        a[i++]=b;
    }
    InitStack(s);
    push(a,s);
}


