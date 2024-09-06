#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

SLTNode* BuyListNode(SLTDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;
}
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void SListPushBack(SLTNode** pphead, SLTDateType x)
{
	assert(pphead);
	SLTNode *newnode = BuyListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDateType x)
{
	assert(pphead);
	SLTNode* newnode = BuyListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead, SLTDateType x)
{
	//温柔的处理方式
	/*if (*pphead == NULL)
	{
		return;
	}*/
	//暴力的处理方式
	//1.一个节点
	//2.两个及以上节点
	assert(*pphead != NULL);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		//while(tail->next!=NULL)
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

//void SListPopBack(SLTNode** pphead)
//{
//	SLTNode* tail = *pphead;
//	//while(tail->next!=NULL)
//	while (tail->next->next)
//	{
//		tail = tail->next;
//	}
//	free(tail->next);
//	tail->next = NULL;
//}

void SListPopFront(SLTNode** pphead)
{
	//if (*pphead == NULL)
	//	return;
	assert(*pphead != NULL);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SListFind(SLTNode* pphead, SLTDateType x)
{
	assert(pphead);
	SLTNode* cur = pphead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SListInsertAfter(SLTNode* pos, SLTDateType x)
{
	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	assert(pphead);
	SLTNode* newnode = BuyListNode(x);
	//找到Pos的钱一个位置
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = pos->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;
	}
}

void SListErase(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	assert(pphead);
	if (*pphead == pos)
	{
		/**pphead = pos->next;
		free(pos);*/
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev -> next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos->next);
	SLTNode* next = pos;
	pos->next = next->next;
	free(next);
	next = NULL;
}


void SListDestory(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while(cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}