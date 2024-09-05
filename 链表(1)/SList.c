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
	SLTNode* newnode = BuyListNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead, SLTDateType x)
{
	//����Ĵ���ʽ
	/*if (*pphead == NULL)
	{
		return;
	}*/
	//�����Ĵ���ʽ
	//1.һ���ڵ�
	//2.���������Ͻڵ�
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

}