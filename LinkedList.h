#pragma once
typedef struct NODE
{
	//������.
	int data;
	//���� ���. (�ڱ����� ����ü)
	NODE* next;
}node;


typedef struct LINKEDLIST
{
	//�������� ��.
	int iCount = 0;

	//���� ���.
	node* headNode = nullptr;
}LinkedList;

//����Ʈ ����.
void Init(LinkedList* s);
//����Ʈ �ڿ� �߰�
void PushBack(LinkedList* s, int data);
//����Ʈ �տ� �߰�
void PushFront(LinkedList* s, int data);
//����
void Delete(LinkedList* s, int data);
//����Ʈ ����.
void ReleaseList(LinkedList* s);
//����Ʈ ������ �ε��� ã��.
int FindIndex(LinkedList* s, int search);
//����Ʈ ������ �ּ� ã��.
node* Find(LinkedList* s, int search);