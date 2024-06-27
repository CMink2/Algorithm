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
	//새 노드 생성.
	node* newNode = (node*)malloc(sizeof(node));

	//새 노드 초기화.
	newNode->data = data;
	newNode->next = nullptr;

	//만약 헤드노드가 비어있다면 바로 연결.
	if (s->headNode == nullptr)
		s->headNode = newNode;
	else 
	{
		//무언가 있다면 끝에까지 가서 연결.
		node* p = s->headNode;
		while (p->next)
		{
			//다음 연결된 노드로 이동하기.
			p = p->next;
		}
		p->next = newNode;
	}
	//개수 증가 시키기.
	s->iCount++;
}
void PushFront(LinkedList* s, int data)
{
	//새 노드 생성.
	node* newNode = (node*)malloc(sizeof(node));

	//새 노드 초기화.
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
	//삭제할 노드 찾기.
	node* deleteNode = Find(s, data);
	
	//삭제하려는 노드가 처음 노드라면.
	if (deleteNode == s->headNode)
	{
		s->headNode = deleteNode->next;
	}
	//삭제할 노드가 처음과 다르다면.
	else 
	{
		//삭제할 노드 이전 노드 찾기.
		node* preNode = s->headNode;

		while (preNode->next != deleteNode)
		{
			preNode = preNode->next;
		}

		//이전 노드가 삭제노드가 가르키는 곳으로 바꾸기.
		preNode->next = deleteNode->next;
	}

	//개수 줄이기.
	s->iCount--;

	//노드 해제하기.
	free(deleteNode);
}
//재귀 방식으로 해제하기.
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
	//삭제할 노드가 NULL이면 그만하기.
	while (pDelete)
	{
		//다음 노드를 미리 기억하기.
		node* pNext = pDelete->next;
		//삭제하기.
		free(pDelete);
		//삭제할 노드 다음으로 바꾸기.
		pDelete = pNext;
	}
}
//데이터 탐색.
int FindIndex(LinkedList* s, int search)
{ 
	if (s->headNode == nullptr || s->iCount == 0)
	{
		std::cout << "리스트가 비어있습니다." << std::endl;
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
		std::cout << "리스트가 비어있습니다." << std::endl;
	}

	node* pnode = s->headNode;
	
	while (pnode->data != search)
	{
		pnode = pnode->next;
	}

	return pnode;
}