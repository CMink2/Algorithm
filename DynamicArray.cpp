#include"DynamicArray.h"
#include<iostream>
void Init(Iarray* a)
{
	//기존에 있던 메모리 할당된 것 모두 지우기.
	if (a->arr != nullptr)
	{
		free(a->arr);
	}

	//데이터 관리에 사용하는 인자 모두 초기화.
	a->count = 0;
	a->maxCount = 2;

	//배열 데이터 초기화. (8바이트 할당)
	a->arr = (int*)malloc(sizeof(int) * a->maxCount);

	if (a->arr == nullptr)
	{
		std::cout << "가변 배열 초기화에 실패했습니다." << std::endl;
	}
}

void Push(Iarray* a, int data)
{
	//만약 배열의 길이가 모자라다면 재할당 영역으로 이동.
	while (a->count >= a->maxCount)
	{
		std::cout << "메모리 공간이 부족해 재할당을 시작합니다." << std::endl;
		Rellocate(a);
	}

	//데이터 값 저장. (현재 저장된 데이터 양 늘리기)
	a->arr[a->count++] = data;
}

void Rellocate(Iarray* a)
{
	//기존의 최대치의 2배만큼 배열 늘려서 잡기.
	int* pNew = (int*)malloc(sizeof(int) * 2 * a->maxCount);

	//제대로 할당됬는지 확인하기.
	if (pNew == nullptr)
	{
		std::cout << "데이터 할당에 실패했습니다." << std::endl;
		return;
	}

	//기존의 값들 옮기기.
	for (int i = 0; i < a->count; i++)
	{
		pNew[i] = a->arr[i];
	}

	//기존의 할당된 메모리 해제하기.
	free(a->arr);

	//저장 가능 최대 공간 수정해주기.
	a->maxCount *= 2;

	//새롭게 할당된 메모리로 주소 바꾸기.
	a->arr = pNew;
}

void Release(Iarray* a)
{
	//모든 메모리 해제.
	free(a->arr);
	//데이터 관리 요소들도 다 0으로 초기화.
	a->count = 0;
	a->maxCount = 0;
}

void BubbleSort(Iarray* a, bool type)	//정렬하고 싶은 가변 배열 주소, 정렬 타입 (true : 오름차순, false : 내림차순)
{
	if (a->arr == nullptr)
	{
		std::cout << "배열이 비어있습니다." << std::endl;
		return;
	}

	//오름차순 정렬.
	if (type)
	{
		for (int i = a->count-1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (a->arr[j] > a->arr[j + 1])
				{
					Swap(&(a->arr[j]), &(a->arr[j + 1]));
				}
			}
		}
	}
	//내림차순 정렬.
	else
	{
		for (int i = a->count - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (a->arr[j] < a->arr[j + 1])
				{
					Swap(&(a->arr[j]), &(a->arr[j + 1]));
				}
			}
		}
	}
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}