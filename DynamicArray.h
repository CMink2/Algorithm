#pragma once

typedef struct IARRAY
{
	int* arr = nullptr;
	int count;
	int maxCount;
}Iarray;

void Init(Iarray* a);
void Push(Iarray* a, int data);
//���Ҵ� �Լ��� �ʿ信 ���� ���� ���� �ִ�.
void Rellocate(Iarray* a);
void Release(Iarray* a);
void BubbleSort(Iarray* a, bool type);
void Swap(int* a, int* b);