#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead, SLTDateType x);
void SListPushFront(SLTNode** ppehad, SLTDateType);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);
SLTNode* SListFind(SLTNode* phead,SLTDateType);
//在pos位置之前去插入一个节点
void SListInsert(SLTNode** pphead,SLTNode*pos,SLTDateType x);
//void SListInsert(SLTNode* phead, int pos, SLTDateType x);
void SListErase(SLTNode** pphead, SLTNode* pos, SLTDateType x);
void SListEraseAfter(SLTNode* po);
void SListDestory(SLTNode** pphead);
void SListInsertAfter(SLTNode* pos, SLTDateType x);