#include<iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

//尾插元素
void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode;
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if(*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while(pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode ** pHead, int value)
{
	if(pHead == NULL || *pHead == NULL)
		return;

	ListNode *pNode = *pHead;
	ListNode *pDel = NULL;
	if(pNode->m_nValue == value)
	{
		*pHead = pNode->m_pNext;
		pDel = pNode;
	}
	else
	{
		while(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;
		
		if(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
		{
			pDel = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if(pDel != NULL)
	{
		delete pDel;
		pDel = NULL;
	}
}

//逆序打印链表
void ReversPrint(ListNode **pHead)
{
	stack<ListNode*> sk;
	ListNode* pNode = *pHead;
	while(pNode != NULL)
	{
		sk.push(pNode);
		pNode = pNode->m_pNext;
	}
	cout<< "ReversPrint :" << endl;
	//打印并且出栈
	while(!sk.empty())
	{
		cout << (sk.top())->m_nValue << endl;
		sk.pop();
	}
	cout<<endl;
}

void Recur(ListNode **pHead)
{
	if(*pHead != NULL)
	{
		if((*pHead)->m_pNext != NULL)
			Recur(&((*pHead)->m_pNext));
		cout<< (*pHead)->m_nValue << endl;
	}
}

int main()
{	
	ListNode* lt = NULL;
	AddToTail(&lt, 10);
	AddToTail(&lt, 20);
	AddToTail(&lt, 11);
	AddToTail(&lt, 41);
	ReversPrint(&lt);
	
	cout<< "Recur" << endl;
	Recur(&lt);
	RemoveNode(&lt, 20);
	ReversPrint(&lt);

	return 0;
}

