#define _CRT_SECURE_NO_WARNINGS
#define LIST_INT_SIZE 100
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int data[LIST_INT_SIZE];
	int length;
}SeqList;

void CreateList(SeqList* L)
{
	int i;
	L->length = 0;
	printf("输入的数超过100结束输入:");
	while (L->length < LIST_INT_SIZE)
	{
		scanf("%d",&i);
		if (i > 100)
			break;
		L->data[L->length++] = i;
	}
}

int PrintList(SeqList L)
{
	printf("顺序表为:");
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	printf("\n");
}

int FindElement(SeqList L, int elem)
{
	for (int i = 0; i < L.length; i++)
	{
		if (elem == L.data[i])
		{
			return i;
		}
	}
	return -1;
}

int InsertElement(SeqList *L, int position, int elem)
{
	if (position<0 || position>L->length || L->length == LIST_INT_SIZE)
	{
		printf("插入非法或者顺序表已满\n");
		return 0;
	}
	for (int i = L->length; i > position; i--)
	{
		L->data[i] = L->data[i - 1];
	}
	L->data[position] = elem;
	L->length++;
	return 1;
}

int DeleteElement(SeqList* L, int position)
{
	if (position < 0 || position >= L->length)
	{
		printf("删除非法");
		return 0;
	}
	for (int i = position; i < L->length; i++)
	{
		L->data[i] = L->data[i + 1];
	}
	L->length--;
	return 1;
}

int main()
{
	SeqList L;
	int elem, position;

	CreateList(&L);
	PrintList(L);

	printf("请输入要查找的元素");
	scanf("%d",&elem);
	position=FindElement(L, elem);
	if (position != -1)
		printf("元素%d在表中的第%d个位置\n", elem, position);
	else
		printf("无此元素");

	printf("请输入要插入的位置和元素:");
	scanf("%d %d",&position,&elem);
	if (InsertElement(&L, position, elem))
		PrintList(L);

	printf("请输入要删除元素的位置:");
	scanf("%d",&position);
	elem = FindElement(L, position);
	printf("要删除第%d位置的元素是%d",position,elem);
	if (DeleteElement(&L, position))
		PrintList(L);
	return 0;
}