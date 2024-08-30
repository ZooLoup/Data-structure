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
	printf("�����������100��������:");
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
	printf("˳���Ϊ:");
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
		printf("����Ƿ�����˳�������\n");
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
		printf("ɾ���Ƿ�");
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

	printf("������Ҫ���ҵ�Ԫ��");
	scanf("%d",&elem);
	position=FindElement(L, elem);
	if (position != -1)
		printf("Ԫ��%d�ڱ��еĵ�%d��λ��\n", elem, position);
	else
		printf("�޴�Ԫ��");

	printf("������Ҫ�����λ�ú�Ԫ��:");
	scanf("%d %d",&position,&elem);
	if (InsertElement(&L, position, elem))
		PrintList(L);

	printf("������Ҫɾ��Ԫ�ص�λ��:");
	scanf("%d",&position);
	elem = FindElement(L, position);
	printf("Ҫɾ����%dλ�õ�Ԫ����%d",position,elem);
	if (DeleteElement(&L, position))
		PrintList(L);
	return 0;
}