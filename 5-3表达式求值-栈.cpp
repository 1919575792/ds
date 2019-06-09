#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef struct{
    char date[100];
    int top;
}OptrStack;     //操作符结构体
typedef struct{
    double date[100];
    int top;
}OpndStack;     //操作数结构体
OptrStack *Init_OptrStack(){
    OptrStack *s;
    s = (OptrStack *)malloc(sizeof(OptrStack));
    s->top = -1;
    return s;
}
int Empty_OptrStack(OptrStack *s){
    if (s->top != -1)
        return 1;
    else
        return 0;
}
int  Push_OptrStack(OptrStack *s, char x){
    if (s->top == 99)
    {
        return 0;
    }
    else
        s->date[++s->top] = x;
    return 1;

}
char Pop_OptrStack(OptrStack *s, char x){
    if (!Empty_OptrStack(s))
    {
        return 0;
    }
    else
    x = s->date[s->top];
    s->top--;
    return x;
}
char GetTop_OptrStack(OptrStack *s, char x){
    if (!Empty_OptrStack(s))
    {
        return 0;
    }
    else
        x = s->date[s->top];
    return x;
}

OpndStack *Init_OpndStack(){
    OpndStack *t;
    t = (OpndStack*)malloc(sizeof(OpndStack));
    t->top = -1;
    return t;
}
int Empty_OpndStack(OpndStack *t){
    if (t->top != -1)
        return 1;
    else
        return 0;
}
int  Push_OpndStack(OpndStack *t, double y){
    if (t->top == 99)
    {
        return 0;
    }
    else
        t->date[++t->top] = y;
    return 1;
}
double Pop_OpndStack(OpndStack *t, double y){
    if (!Empty_OpndStack(t))
    {
        return 0;
    }
    else
    y = t->date[t->top];
    t->top--;
    return y;
}
double GetTop_OpndStack(OpndStack *t, double y){
    if (!Empty_OpndStack(t))
    {
        return 0;
    }
    y = t->date[t->top];
    return y;
}
int Judge_optr(char top){
	int x=0;
	switch (top)
	{
	case '(':
		x = 0; break;
	case '+':
	case '-':
		x = 1; break;
	case '*':
	case '/':
		x = 2; break;
	case ')':
		x = 3; break;
	}
	return x;
}
double Operate(double b, double a, char top){
	double c = 0;
	switch (top)
	{
	case '+':
		c = b + a;
		break;
	case '-':
		c = b - a;
		break;
	case '*':
		c = b * a;
		break;
	case '/':
		if (a == 0)
		{
			printf("分母为零!\n");
			return 0;
		}
		else
			c = b / a;
		break;
	}
	return c;
}
double get_oper(char str[]){
	OptrStack *optr = Init_OptrStack();
	OpndStack *opnd = Init_OpndStack();
	int i, j;
	double f;
	double a = 0;
	double b = 0;
	double c = 0;
	char d[100];
	char top = 0;
	for (i = 0; str[i]!='#'; i++)
	{
		switch (str[i])
		{
		case '(':
		case '+':
		case '-':
			if ((!Empty_OptrStack(optr)) || (Judge_optr(str[i]) > Judge_optr(GetTop_OptrStack(optr, top)))||(str[i]=='('))  //当操作符栈为空的时候压栈保存
			{
				Push_OptrStack(optr, str[i]);
			}
			else
			{
				a = Pop_OpndStack(opnd, a);
				b = Pop_OpndStack(opnd, b);
				top = Pop_OptrStack(optr, top);
				c = Operate(b, a, top);
				Push_OpndStack(opnd, c);
				Push_OptrStack(optr, str[i]);
			}
			break;
		case '*':
		case '/':
			if ((!Empty_OptrStack(optr)) || (Judge_optr(str[i]) > Judge_optr(GetTop_OptrStack(optr, top))) || (str[i] == '('))
			{
				Push_OptrStack(optr, str[i]);
			}
			else
			{
				a = Pop_OpndStack(opnd, a);
				b = Pop_OpndStack(opnd, b);
				top = Pop_OptrStack(optr, top);
				c = Operate(b, a, top);
				Push_OpndStack(opnd, c);
				Push_OptrStack(optr, str[i]);
			}
			break;
		case ')':
			Push_OptrStack(optr, str[i]);
			break;
		case '\0':
			break;
		default:
			j = 0;
			do
			{
				d[j++] = str[i];
				i++;
			} while (str[i] >= '0' && str[i] <= '9');
			d[j] = '\0';
			i--;
			f = atof(d);
			Push_OpndStack(opnd, f);
			break;
		}
	}
	while (Empty_OptrStack(optr))
	{
		if ((GetTop_OptrStack(optr, top) == ')') || (GetTop_OptrStack(optr, top) == '('))
		{
		top=Pop_OptrStack(optr, top);
		}
		else
		{
			a = Pop_OpndStack(opnd, a);
			b = Pop_OpndStack(opnd, b);
			top = Pop_OptrStack(optr, top);
			c = Operate(b, a, top);
			Push_OpndStack(opnd, c);
		}
	}
	return GetTop_OpndStack(opnd, c) ;
}
int main(){
    int i=0,j=0;double a[3];
    while(i<3){
    char str[100];
    cin >> str;
    a[i] = get_oper(str);i++;}
    while(j<3){
        cout<<a[j]<<endl;j++;}
}
