#pragma once

typedef struct IARRAY
{
	int* arr = nullptr;
	int count;
	int maxCount;
}Iarray;

void Init(Iarray* a);
void Push(Iarray* a, int data);
//재할당 함수는 필요에 따라서 가릴 수도 있다.
void Rellocate(Iarray* a);
void Release(Iarray* a);
void BubbleSort(Iarray* a, bool type);
void Swap(int* a, int* b);