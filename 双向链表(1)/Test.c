#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

void TestList1()
{
	LTNode * plist = ListInit();
	ListInit(plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	LTNode* pos = ListFind(plist, 2);
	if (pos)
	{
		ListErase(pos);
	}
	ListPrint(plist);


	ListDestory(plist);
	plist = NULL;
}
int main()
{
	TestList1();
	return 0;
}

//顺序表和链表
//各有优势，很难说谁更优，相辅相成的两个结构
//顺序表
//优点:
// 1.支持随机访问，需要随机访问结构支持算法可以很好适用
// //2.cpu高速缓存命中率更高
//缺点:
//1.头部和中部插入删除时间效率低。O(N)
//2.连续的物理空间，空间不够了以后需要增容，增容有一定程度的消耗，为了避免频繁增容，一般会按照倍数去增容，用不完会存在一定的空间浪费。
//链表
//优点:
// 1.任意位置插入删除效率高。O(1)
// 2.按需申请和释放空间
//缺点:
//1.不支持随机访问，随机访问就是用下标访问,意味着一些排序，快排，二分查找等在这些结构上不适用
//2.链表存储一个值，同时要存储链接指针，也有一定的消耗。
//3.cpu高速缓存命中率更低