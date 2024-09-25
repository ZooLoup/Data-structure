#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -2
#define OK 1
#define ERROR 4
typedef int SElemType;
typedef int Status;
typedef struct
{
	SElemType * base;
    SElemType* top;
	int stacksize;
}SqStack;
Status InitStack(SqStack& S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}
Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT));
		if (S.base)
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*(S.top++) = e;
	return OK;
}
Status Pop(SqStack& S, SElemType& e)
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
void Conversion(int N)
{
	SqStack S;
	SElemType e;
	InitStack(S);
	while (N)
	{
		Push(S,N % 8);
		N = N / 8;
	}
	while (S.top != S.base)
	{
		Pop(S, e);
		printf("%d",e);
	}
	free(S.base);
}

int main()
{
	int n;
	scanf("%d",&n);
	Conversion(n);
	return 0;
}

