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

//˳��������
//�������ƣ�����˵˭���ţ��ศ��ɵ������ṹ
//˳���
//�ŵ�:
// 1.֧��������ʣ���Ҫ������ʽṹ֧���㷨���Ժܺ�����
// //2.cpu���ٻ��������ʸ���
//ȱ��:
//1.ͷ�����в�����ɾ��ʱ��Ч�ʵ͡�O(N)
//2.����������ռ䣬�ռ䲻�����Ժ���Ҫ���ݣ�������һ���̶ȵ����ģ�Ϊ�˱���Ƶ�����ݣ�һ��ᰴ�ձ���ȥ���ݣ��ò�������һ���Ŀռ��˷ѡ�
//����
//�ŵ�:
// 1.����λ�ò���ɾ��Ч�ʸߡ�O(1)
// 2.����������ͷſռ�
//ȱ��:
//1.��֧��������ʣ�������ʾ������±����,��ζ��һЩ���򣬿��ţ����ֲ��ҵ�����Щ�ṹ�ϲ�����
//2.����洢һ��ֵ��ͬʱҪ�洢����ָ�룬Ҳ��һ�������ġ�
//3.cpu���ٻ��������ʸ���