#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
LTNode* ListInit(LTNode*phead)
{
	//哨兵位头节点
	phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

LTNode* BuyListNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d",cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void ListPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);

	LTNode* tail = phead -> prev;
	LTNode* newnode = BuyListNode(x);
	newnode->data = x;

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->prev;
	LTNode* tailprev = phead->prev;

	free(tail);
	tailprev->next = phead;
	phead->prev = tailprev;

}

//头插
void ListPushFront(LTNode* phead,LTDateType x)
{
	assert(phead);
	LTNode* newnode = BuyListNode(x);
	LTNode* next = phead->next;

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = next;
	next->prev = newnode;
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	LTNode* next = phead->next;
	LTNode* nextNext = next->next;
	phead->next = nextNext;
	nextNext->prev = phead;
	free(next);
}

LTNode* ListFind(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void InsertList(LTNode* pos, LTDateType x)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* newnode = BuyListNode(x);

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListErase(LTNode* pos)
{
	assert(pos);

	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
}

void ListDestory(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = cur->next;
	}
	free(phead);
	phead = NULL;
}