#pragma once
#include<iostream>
#include<cassert>
//class���� ���� �迭. ���ø� ����.
//template�� ����� ��� �󸶳� ū �����Ͱ� ������ �𸥴�. ���� ���� �ȵǰ� ������ �ǵ��� �ϱ�.
template<typename T>
class CArr
{
private:
	T* m_arr;	//�迭�� ����� ����.
	int m_Count;	//�迭�� ����� ������ ����.
	int m_MaxCount;	//�迭�� ������ �� �ִ� �ִ� ���� ����.

public:
	CArr();
	~CArr();
public:
	void PushBack(const T& data);
	void Resize(int size);
	void Print();
	T& operator[](int idx);
};
template<typename T>
CArr<T>::CArr()
	: m_arr(nullptr)
	, m_Count(0)
	, m_MaxCount(2)
{
	//���� �Ҵ��� �ϴµ� ����ϴ� Ű���� new. ~!
	m_arr = new int[2];
}
template<typename T>
CArr<T>::~CArr()
{
	//�����Ҵ� �޸� �����ϴ� ���.
	//new int �� �޾����� delete key�� ����. ������ �������̸� new int[] �̸� delete[]�� �����.
	if (m_arr != nullptr)
		delete[] m_arr;
	m_arr = nullptr;
}
template<typename T>
void CArr<T>::PushBack(const T& data)
{
	//�ʹ� Ŭ ��� ���Ҵ� �� �ٽ� ����.
	if (m_Count >= m_MaxCount)
	{
		//���Ҵ�.
		Resize(m_MaxCount * 2);
	}

	//���� �ּҿ� ����.	
	m_arr[m_Count++] = data;
}

template<typename T>
void CArr<T>::Resize(int size)
{
	//���� ����� �� �۰� �ԷµǸ� ���� �ȵ�. ����ó�� ����.
	if (size <= m_MaxCount)
	{
		assert(nullptr);
	}

	//�ִ��ġ �ø���.
	int* newPtr = new int[size];

	//������ �迭 ������ �ű��.
	for (int i = 0; i < m_Count; i++)
	{
		newPtr[i] = m_arr[i];
	}

	//���� �迭 �����,
	delete[] m_arr;

	//�� �迭 �ּҷ� �ٲٱ�.
	m_arr = newPtr;

	//�ִ� ��ġ �÷��ֱ�.
	m_MaxCount = size;
}

template<typename T>
void CArr<T>::Print()
{
	for (int i = 0; i < m_Count; i++)
	{
		std::cout << i << ": " << m_arr[i] << std::endl;
	}
}

template<typename T>
T& CArr<T>::operator[](int idx)
{
	//���� �ε����� �Ѿ�� ������.
	if (idx >= m_Count)
	{
		assert(nullptr);
	}

	//�ش� ��ġ�� �� ��ȯ.
	return m_arr[idx];
}