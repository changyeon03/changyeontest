// Vector 구현
/*
기본 생성자 / 복사 생성자 / 복사 대입 연산자 / 소멸자
at() / operator[] / front() / back()
begin() / end() / cbegin() / cend()
empty() / size() / capacity()
push_back() / pop_back() / insert() / erase() / reserve() / clear() / swap()
*/
#include <iostream>
#include <string>

template <typename T>
class Vector 
{
	T* data;
	int capacity;
	int length;

public:
	Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {} // 기본생성자
	Vector(int n, int x)
	{
		data(new T[n]);
		capacity(n); 
		lenth(n);

		for (int i = 0; i < n; i++)
		{
			data[i] = x;
		}

	} //n개를 x로 초기화
	Vector(Vector &rhs)
	{
		length = rhs.length;
		data(new T[length]);
		for (int i = 0; i < length; i++)
		{
			data[i] = rhs.data[i];
		}
	} //복사 생성자

	// 맨 뒤에 새로운 원소를 추가한다.
	void push_back(T s) 
	{
		if (capacity <= length) 
		{
			T* temp = new T[capacity * 2];
			for (int i = 0; i < length; i++) 
			{	
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
			capacity *= 2;
		}

		data[length] = s;
		length++;
	}
	// 맨 뒤에 원소를 제거한다
	void pop_back()
	{
		length--;
	}

	// 임의의 위치의 원소에 접근한다.
	T operator[](int i) { return data[i]; }

	// i번째 원소를 참조한다
	T at(int i) { return data[i]; }
	T front() { return data[0]; }
	T back() { return data[length]; }


	// x 번째 위치한 원소를 제거한다.
	void erase(int x) 
	{
		for (int i = x + 1; i < length; i++) 
		{
			data[i - 1] = data[i];
		}
		length--;
	}

	// 현재 벡터의 크기를 구한다.
	int size() { return length; }
	// 백터의 수용가능 공간을 구한다.
	int capacity() { return capacity; }

	bool empty()
	{
		if (length == 0)
			return true;
		else
			return false;
	}

	void clear()
	{
		length = 0;
	}

	//두 백터를 서로 바꿔준다
	void swap(Vector rhs)
	{
		T* ndata = new T[length];
		int nlength = length;
		int ncpacity = capacity;

		length = rhs.length;
		capacity = rhs.capacity;
		for (int i = 0; i < length; i++)
		{
			data[i] = rhs.data[i];
		}

		rhs.length = nlength;
		rhs.capacity = ncpacity;
		for (int i = 0; i < rhs.length; i++)
		{
			rhs.data[i] = ndata[i];
		}
		delete[] ndata;
	}
	//소멸자
	~Vector() 
	{
		if (data) 
		{
			delete[] data;
		}
	}
};
