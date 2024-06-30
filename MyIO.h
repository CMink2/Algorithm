#pragma once
#include <stdio.h>
/// <summary>
/// 입출력 cin. cout 역할을 수행하는 클래스 만들어보기.
/// >>, << 오버로딩해서 비슷하게 수행하도록 만들기.
/// endl은 함수 구현해서 더 간단한 이름으로 바꿔보기.
/// 한 줄에 여러 연산 가능하도록 구성하기. << 숫자 << 문자 처리 가능하도록 수정.
/// </summary>
class MyIO
{
public:
	//cout 연산 시키기.
	MyIO& operator << (const int& data)
	{
		printf("%d", data);
		return *this;
	}
	MyIO& operator << (const float& data)
	{
		printf("%f", data);
		return *this;
	}
	MyIO& operator << (const double& data)
	{
		printf("%f", data);
		return *this;
	}
	MyIO& operator << (const char& data)
	{
		printf("%c", data);
		return *this;
	}
	MyIO& operator << (const char* data)
	{
		printf("%s", data);
		return *this;
	}
	//특정 함수도 실행해주기.
	MyIO& operator << (void(*_pFunc)(void))
	{
		_pFunc();
		return *this;
	}

	//cin 연산 시키기.
	MyIO& operator >> (int& data)
	{
		scanf_s("%d", &data);
		return *this;
	}
	MyIO& operator >> (float& data)
	{
		scanf_s("%f", &data);
		return *this;
	}
	MyIO& operator >> (double& data)
	{
		scanf_s("%f", &data);
		return *this;
	}
	MyIO& operator >> (char& data)
	{
		scanf_s("%c", &data);
		return *this;
	}
};

//줄바꿈 함수.
void nl()
{
	printf("\n");
}

