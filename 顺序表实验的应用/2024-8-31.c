#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 

typedef struct {

	int data[MAX_SIZE]; 

	int Length; 

} SqList;

void CreateList(SqList* List);
void DispLayList(SqList List);
int  SearchInList(SqList List, int eLement);
void UnionList(SqList* List1a, SqList List1b);
int main() 
{
	SqList List1a, List1b;
	List1a.Length = 0;
	List1b.Length = 0;

	CreateList(&List1a);

	CreateList(&List1b);

	printf("\n");
	UnionList(&List1a, List1b);
	printf("合并的顺序表为：");
	DispLayList(List1a);
	return 0;
}

void static CreateList(SqList* List) 
{
	int num;
	printf("输入的数超过100结束输入:");
	while (scanf("%d", &num) && num <= 100) 
	{

		if (List->Length < MAX_SIZE) 
		{
			List->data[List->Length++] = num;
		}
		else 
		{
			break;
		}

	}
	printf("顺序表为：");
	DispLayList(*List);
}

void static DispLayList(SqList List) 
{
	for (int i = 0; i < List.Length; i++) 
	{
		printf("%d ", List.data[i]);
	}
	printf("\n");
}

int static SearchInList(SqList List, int eLement) 
{

	for (int i = 0; i < List.Length; i++)
	{
		if (List.data[i] == eLement) 
		{
			return 1; 
		}
	}
	return 0; 
}

void static UnionList(SqList* List1a, SqList List1b) 
{
	for (int i = 0; i < List1b.Length; i++) 
	{
		if (!SearchInList(*List1a, List1b.data[i])) 
		{
			if (List1a->Length < MAX_SIZE) 
			{
				List1a->data[List1a->Length++] = List1b.data[i]; 
			}
			else
			{
				break;
			}
		}
	}
}