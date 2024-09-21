#define _CRT_SECURE_NO_WARNINGS
//如果用尾做栈顶，尾插尾删，要设计成双向链表，否则删除数据效率低
//如果用头做栈顶，头插头删，就可以设计成单链表
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