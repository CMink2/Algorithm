#pragma once
typedef struct NODE
{
	//데이터.
	int data;
	//다음 노드. (자기참조 구조체)
	NODE* next;
}node;


typedef struct LINKEDLIST
{
	//데이터의 수.
	int iCount = 0;

	//다음 노드.
	node* headNode = nullptr;
}LinkedList;

//리스트 세팅.
void Init(LinkedList* s);
//리스트 뒤에 추가
void PushBack(LinkedList* s, int data);
//리스트 앞에 추가
void PushFront(LinkedList* s, int data);
//삭제
void Delete(LinkedList* s, int data);
//리스트 해제.
void ReleaseList(LinkedList* s);
//리스트 원소의 인덱스 찾기.
int FindIndex(LinkedList* s, int search);
//리스트 원소의 주소 찾기.
node* Find(LinkedList* s, int search);