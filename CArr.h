#pragma once
#include<iostream>
#include<cassert>
//class버전 가변 배열. 템플릿 적용.
//template를 사용할 경우 얼마나 큰 데이터가 들어올지 모른다. 따라서 수정 안되고 참조만 되도록 하기.
template<typename T>
class CArr
{
private:
	T* m_arr;	//배열이 저장될 변수.
	int m_Count;	//배열에 저장된 변수의 개수.
	int m_MaxCount;	//배열에 저장할 수 있는 최대 저장 공간.

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
	//동적 할당을 하는데 사용하는 키워드 new. ~!
	m_arr = new int[2];
}
template<typename T>
CArr<T>::~CArr()
{
	//동적할당 메모리 해제하는 방법.
	//new int 로 받았으면 delete key로 가능. 하지만 여러개이면 new int[] 이면 delete[]로 지운다.
	if (m_arr != nullptr)
		delete[] m_arr;
	m_arr = nullptr;
}
template<typename T>
void CArr<T>::PushBack(const T& data)
{
	//너무 클 경우 재할당 후 다시 진행.
	if (m_Count >= m_MaxCount)
	{
		//재할당.
		Resize(m_MaxCount * 2);
	}

	//다음 주소에 저장.	
	m_arr[m_Count++] = data;
}

template<typename T>
void CArr<T>::Resize(int size)
{
	//만약 사이즈가 더 작게 입력되면 말이 안됨. 예외처리 진행.
	if (size <= m_MaxCount)
	{
		assert(nullptr);
	}

	//최대수치 늘리기.
	int* newPtr = new int[size];

	//기존의 배열 데이터 옮기기.
	for (int i = 0; i < m_Count; i++)
	{
		newPtr[i] = m_arr[i];
	}

	//기존 배열 지우기,
	delete[] m_arr;

	//새 배열 주소로 바꾸기.
	m_arr = newPtr;

	//최대 수치 올려주기.
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
	//만약 인덱스가 넘어가면 오류임.
	if (idx >= m_Count)
	{
		assert(nullptr);
	}

	//해당 위치의 값 반환.
	return m_arr[idx];
}