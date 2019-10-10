// Vector ����
/*
�⺻ ������ / ���� ������ / ���� ���� ������ / �Ҹ���
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
	Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {} // �⺻������
	Vector(int n, int x)
	{
		data(new T[n]);
		capacity(n); 
		lenth(n);

		for (int i = 0; i < n; i++)
		{
			data[i] = x;
		}

	} //n���� x�� �ʱ�ȭ
	Vector(Vector &rhs)
	{
		length = rhs.length;
		data(new T[length]);
		for (int i = 0; i < length; i++)
		{
			data[i] = rhs.data[i];
		}
	} //���� ������

	// �� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
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
	// �� �ڿ� ���Ҹ� �����Ѵ�
	void pop_back()
	{
		length--;
	}

	// ������ ��ġ�� ���ҿ� �����Ѵ�.
	T operator[](int i) { return data[i]; }

	// i��° ���Ҹ� �����Ѵ�
	T at(int i) { return data[i]; }
	T front() { return data[0]; }
	T back() { return data[length]; }


	// x ��° ��ġ�� ���Ҹ� �����Ѵ�.
	void erase(int x) 
	{
		for (int i = x + 1; i < length; i++) 
		{
			data[i - 1] = data[i];
		}
		length--;
	}

	// ���� ������ ũ�⸦ ���Ѵ�.
	int size() { return length; }
	// ������ ���밡�� ������ ���Ѵ�.
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

	//�� ���͸� ���� �ٲ��ش�
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
	//�Ҹ���
	~Vector() 
	{
		if (data) 
		{
			delete[] data;
		}
	}
};
