#define _CRT_SECURE_NO_WARNINGS
//˳���ȱ�ݣ�
//1.�ռ䲻������Ҫ���ݣ����ݶ������˷ѵ�
//2.����Ƶ�����ݣ��������˻�������Ҫ��2�������ܾͻᵼ��һ���Ŀռ��˷�
//3.˳���Ҫ�����ݴӿ�ʼλ�������洢����ô������ͷ�������м�λ�ò���ɾ�����ݾ���ҪŲ�����ݣ�Ч�ʲ���
//�����ŵ�:
//1.��������ռ䣬�����˾��ͷſռ䣨�������ÿռ䣩
//2.�������ݣ�����Ҫ�ƶ�����
//3.�����ڿռ��˷�

//��֧���������
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