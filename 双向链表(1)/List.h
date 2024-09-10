#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* ListInit();
void ListPrint(LTNode* phead);
void ListPushBack(LTNode* phead, LTDateType x);
void ListPushFront(LTNode* phead);
void ListPopBack(LTNode* phead);
void ListPopFront(LTNode* phead);

LTNode* ListFind(LTNode* phead, LTDateType x);
void InsertList(LTNode* pos, LTDateType x);
void ListErase(LTNode* pos);

void ListDestory(LTNode* phead);