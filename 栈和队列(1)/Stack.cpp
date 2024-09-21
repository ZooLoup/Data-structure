#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
void StackInit(ST* ps)
{
	//初始化时，top给的是0，意味着top指向栈顶数据的下一个
	assert(ps);
	ps->a=NULL;
	ps->top = 0;
	ps->capacity = 0;

}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType)*newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}
	}
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps)
{
	assert(ps);
	//if (ps->top == 0)
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
	return ps->top == 0;
}