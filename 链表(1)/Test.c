#define _CRT_SECURE_NO_WARNINGS
//顺序表缺陷：
//1.空间不够了需要增容，增容都是有浪费的
//2.避免频繁扩容，我们满了基本都是要扩2倍，可能就会导致一定的空间浪费
//3.顺序表要求数据从开始位置连续存储，那么我们在头部或者中间位置插入删除数据就需要挪动数据，效率不高
//链表优点:
//1.按需申请空间，不用了就释放空间（合理利用空间）
//2.插入数据，不需要移动数据
//3.不存在空间浪费

//不支持随机访问
#include "SList.h"

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPushFront(&plist,1);
	SListPushFront(&plist,2);
	SListPushFront(&plist,3);
	SListPushFront(&plist,4);
	SListPrint(plist);
}

void TestSList2()
{
	SLTNode* plist = NULL;

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
}
int main()
{
	//TestSList1();
	TestSList2();
	return 0;
}