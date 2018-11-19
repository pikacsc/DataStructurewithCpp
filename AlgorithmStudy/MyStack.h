#pragma once
#include <iostream>
#include <cassert>
template <typename T, unsigned int T_SIZE>
class MyStack
{
private:
	T *m_data;
	unsigned int currentIndex;
public:

	MyStack()
	{
		m_data = new T[T_SIZE];
		currentIndex = 0;
	}


	~MyStack()
	{
		delete[] m_data;
		m_data = nullptr;
	}


	//insert data
	void push(const T &data)
	{
		*(m_data+currentIndex) = data;
		currentIndex++;
	}

	//get top data
	const T& pop()
	{

	}

	//not get but peek only
	void peek()
	{

	}

	void peek(const int &index)
	{

	}

	//delete top data
	void del()
	{

	}

	//check stack is empty or not
	bool isEmpty()
	{

	}

	//check how many datas in stack
	unsigned int getSize()
	{

	}

	//print all data
	void print()
	{
		using namespace std;
		for (unsigned int i = 0; i < currentIndex; i++)
		{
			cout << *(m_data + i) << endl;
		}
	}

	T & operator [] (int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}
};

