#define _CRT_SECURE_NO_WARNINGS
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#include <stdio.h>
#include <stdlib.h>
typedef int QElemType;
typedef int Status;
typedef struct Qnode
{
	QElemType data;
	struct Qnode* next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
Status InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}
Status EnQueue(LinkQueue &Q, QElemType e)
{
	QNode* p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue& Q,QElemType &e)
{
	QNode* p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}
void output(LinkQueue Q)
{
	QNode* p;
	if (Q.front == Q.rear)
	{
		printf("©у╤сап\n");
		return;
	}
	p = Q.front->next;
	while (p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
void DestroyQueue(LinkQueue& Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}
int main()
{
	LinkQueue Q;
	QElemType n,e;
	InitQueue(Q);
	scanf("%d",&n);
	while (n)
	{
		if (n % 2)
			EnQueue(Q, n);
		else
			DeQueue(Q, e);
		output(Q);
		scanf("%d", &n);
	}
	DestroyQueue(Q);
	return 0;
}