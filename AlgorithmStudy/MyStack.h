#pragma once
#include <iostream>
#include <cassert>
template <typename T, unsigned int T_SIZE>
class MyStack
{
private:
	T *m_data;
	unsigned int nextIndex;
public:

	MyStack()
	{
		m_data = new T[T_SIZE];
		nextIndex = 0;
	}


	~MyStack()
	{
		delete[] m_data;
		m_data = nullptr;
	}


	//insert data
	void push(const T &data)
	{
		*(m_data+nextIndex) = data;
		nextIndex++;
	}

	//get top data
	T pop()
	{
		T topData = *(m_data + nextIndex - 1);
		nextIndex--;
		return topData;
	}

	//not get but peek only
	void peek()
	{
		std::cout <<"Top:" << *(m_data + nextIndex - 1) << std::endl;
	}

	void peek(const int &index)
	{
		std::cout << *(m_data+index) << std::endl;
	}

	//delete top data
	void del()
	{
		nextIndex--;
	}

	//check stack is empty or not
	bool isEmpty()
	{
		return (nextIndex == 0) ? true : false;
	}

	//check how many datas in stack
	unsigned int getSize()
	{
		return nextIndex;
	}

	//print all data
	void print()
	{
		for (unsigned int i = 0; i < nextIndex; i++)
		{
			std::cout << *(m_data + i) << std::endl;
		}
	}

	T & operator [] (unsigned int index)
	{
		assert(index >= 0 && index < T_SIZE);
		assert(nextIndex > index); // To limit stack
		return m_data[index];
	}
};

