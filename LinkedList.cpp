#include"LinkedList.h"
#include<iostream>
void Init(LinkedList* s)
{
	if (s->iCount != 0)
		return;
	s->iCount = 0;
	s->headNode = nullptr;
}
void PushBack(LinkedList* s, int data)
{
	//�� ��� ����.
	node* newNode = (node*)malloc(sizeof(node));

	//�� ��� �ʱ�ȭ.
	newNode->data = data;
	newNode->next = nullptr;

	//���� ����尡 ����ִٸ� �ٷ� ����.
	if (s->headNode == nullptr)
		s->headNode = newNode;
	else 
	{
		//���� �ִٸ� �������� ���� ����.
		node* p = s->headNode;
		while (p->next)
		{
			//���� ����� ���� �̵��ϱ�.
			p = p->next;
		}
		p->next = newNode;
	}
	//���� ���� ��Ű��.
	s->iCount++;
}
void PushFront(LinkedList* s, int data)
{
	//�� ��� ����.
	node* newNode = (node*)malloc(sizeof(node));

	//�� ��� �ʱ�ȭ.
	newNode->data = data;
	newNode->next = nullptr;

	if (s->headNode)
	{
		newNode->next = s->headNode;
		s->headNode = newNode;
	}
	else
	{
		s->headNode = newNode;
	}

	s->iCount++;
}
void Delete(LinkedList* s, int data)
{
	//������ ��� ã��.
	node* deleteNode = Find(s, data);
	
	//�����Ϸ��� ��尡 ó�� �����.
	if (deleteNode == s->headNode)
	{
		s->headNode = deleteNode->next;
	}
	//������ ��尡 ó���� �ٸ��ٸ�.
	else 
	{
		//������ ��� ���� ��� ã��.
		node* preNode = s->headNode;

		while (preNode->next != deleteNode)
		{
			preNode = preNode->next;
		}

		//���� ��尡 ������尡 ����Ű�� ������ �ٲٱ�.
		preNode->next = deleteNode->next;
	}

	//���� ���̱�.
	s->iCount--;

	//��� �����ϱ�.
	free(deleteNode);
}
//��� ������� �����ϱ�.
void Release(node* n)
{
	if (nullptr == n)
		return;
	Release(n->next);

	free(n);
}
void ReleaseList(LinkedList* s)
{
	//Release(s->headNode);

	node* pDelete = s->headNode;
	//������ ��尡 NULL�̸� �׸��ϱ�.
	while (pDelete)
	{
		//���� ��带 �̸� ����ϱ�.
		node* pNext = pDelete->next;
		//�����ϱ�.
		free(pDelete);
		//������ ��� �������� �ٲٱ�.
		pDelete = pNext;
	}
}
//������ Ž��.
int FindIndex(LinkedList* s, int search)
{ 
	if (s->headNode == nullptr || s->iCount == 0)
	{
		std::cout << "����Ʈ�� ����ֽ��ϴ�." << std::endl;
	}
	node* pnode = s->headNode;
	int i = 0;
	while (pnode->data != search)
	{
		pnode = pnode->next;
		i++;
	}
	return i;
}

node* Find(LinkedList* s, int search)
{
	if (s->headNode == nullptr || s->iCount == 0)
	{
		std::cout << "����Ʈ�� ����ֽ��ϴ�." << std::endl;
	}

	node* pnode = s->headNode;
	
	while (pnode->data != search)
	{
		pnode = pnode->next;
	}

	return pnode;
}