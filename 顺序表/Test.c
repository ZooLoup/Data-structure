#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"
void TestSeqList1()
{
	SL s1;
	SeqListInit(&s1);//传递结构体的地址，形参是形参的一份临时拷贝
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);

	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPrint(&s1);

	SeqListDestory(&s1);
}
void TestSeqList2()
{
	SL s1;
	SeqListInit(&s1);//传递结构体的地址，形参是形参的一份临时拷贝
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);

	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPrint(&s1);

	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);

	SeqListFind(&s1,30);
	SeqListDestory(&s1);
}
int main()
{
	//TestSeqList1();
	TestSeqList2();
	return 0;
}