#include"DynamicArray.h"
#include<iostream>
void Init(Iarray* a)
{
	//������ �ִ� �޸� �Ҵ�� �� ��� �����.
	if (a->arr != nullptr)
	{
		free(a->arr);
	}

	//������ ������ ����ϴ� ���� ��� �ʱ�ȭ.
	a->count = 0;
	a->maxCount = 2;

	//�迭 ������ �ʱ�ȭ. (8����Ʈ �Ҵ�)
	a->arr = (int*)malloc(sizeof(int) * a->maxCount);

	if (a->arr == nullptr)
	{
		std::cout << "���� �迭 �ʱ�ȭ�� �����߽��ϴ�." << std::endl;
	}
}

void Push(Iarray* a, int data)
{
	//���� �迭�� ���̰� ���ڶ�ٸ� ���Ҵ� �������� �̵�.
	while (a->count >= a->maxCount)
	{
		std::cout << "�޸� ������ ������ ���Ҵ��� �����մϴ�." << std::endl;
		Rellocate(a);
	}

	//������ �� ����. (���� ����� ������ �� �ø���)
	a->arr[a->count++] = data;
}

void Rellocate(Iarray* a)
{
	//������ �ִ�ġ�� 2�踸ŭ �迭 �÷��� ���.
	int* pNew = (int*)malloc(sizeof(int) * 2 * a->maxCount);

	//����� �Ҵ����� Ȯ���ϱ�.
	if (pNew == nullptr)
	{
		std::cout << "������ �Ҵ翡 �����߽��ϴ�." << std::endl;
		return;
	}

	//������ ���� �ű��.
	for (int i = 0; i < a->count; i++)
	{
		pNew[i] = a->arr[i];
	}

	//������ �Ҵ�� �޸� �����ϱ�.
	free(a->arr);

	//���� ���� �ִ� ���� �������ֱ�.
	a->maxCount *= 2;

	//���Ӱ� �Ҵ�� �޸𸮷� �ּ� �ٲٱ�.
	a->arr = pNew;
}

void Release(Iarray* a)
{
	//��� �޸� ����.
	free(a->arr);
	//������ ���� ��ҵ鵵 �� 0���� �ʱ�ȭ.
	a->count = 0;
	a->maxCount = 0;
}

void BubbleSort(Iarray* a, bool type)	//�����ϰ� ���� ���� �迭 �ּ�, ���� Ÿ�� (true : ��������, false : ��������)
{
	if (a->arr == nullptr)
	{
		std::cout << "�迭�� ����ֽ��ϴ�." << std::endl;
		return;
	}

	//�������� ����.
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
	//�������� ����.
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