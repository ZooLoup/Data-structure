#define _CRT_SECURE_NO_WARNINGS
//�����β��ջ����β��βɾ��Ҫ��Ƴ�˫����������ɾ������Ч�ʵ�
//�����ͷ��ջ����ͷ��ͷɾ���Ϳ�����Ƴɵ�����
#include "Stack.h"
void TestStack1()
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
}

void TestStack2()
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	printf("%d",StackTop(&st));
	StackPop(&st);


}

int main()
{
	TestStack1();
	TestStack2();
	return 0;
}