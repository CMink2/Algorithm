#pragma once
#include <stdio.h>
/// <summary>
/// ����� cin. cout ������ �����ϴ� Ŭ���� ������.
/// >>, << �����ε��ؼ� ����ϰ� �����ϵ��� �����.
/// endl�� �Լ� �����ؼ� �� ������ �̸����� �ٲ㺸��.
/// �� �ٿ� ���� ���� �����ϵ��� �����ϱ�. << ���� << ���� ó�� �����ϵ��� ����.
/// </summary>
class MyIO
{
public:
	//cout ���� ��Ű��.
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
	//Ư�� �Լ��� �������ֱ�.
	MyIO& operator << (void(*_pFunc)(void))
	{
		_pFunc();
		return *this;
	}

	//cin ���� ��Ű��.
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

//�ٹٲ� �Լ�.
void nl()
{
	printf("\n");
}

