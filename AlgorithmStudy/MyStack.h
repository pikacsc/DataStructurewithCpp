#pragma once
#include <iostream>
#include <cassert>
template <typename T, unsigned int T_SIZE>
class MyStack
{
private:
	T *m_dataArr;
	unsigned int nextIndex;
public:

	MyStack()
	{
		m_dataArr = new T[T_SIZE];
		nextIndex = 0;
	}


	~MyStack()
	{
		clear();
	}


	//insert data
	void push(const T &data)
	{
		if (nextIndex == T_SIZE)
			assert(false);
		m_dataArr[nextIndex] = data;
		nextIndex++;
	}

	//get top data
	T pop()
	{
		if (isEmpty())
			assert(false);
		T topData = m_dataArr[nextIndex - 1];
		nextIndex--;
		return topData;
	}

	//not get but peek only
	void peek()
	{
		std::cout <<"Top:" << m_dataArr[nextIndex-1] << std::endl;
	}

	void peek(const unsigned int &index)
	{
		std::cout << m_dataArr[index] << std::endl;
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
	unsigned int size()
	{
		return nextIndex;
	}

	//print all data
	void print()
	{
		if (isEmpty())
			std::cout << "no data in Stack" << std::endl;
		for (unsigned int i = 0; i < nextIndex; i++)
		{
			std::cout << m_dataArr[i] << std::endl;
		}
	}

	T & operator [] (unsigned int index)
	{
		assert(index >= 0 && index < T_SIZE);
		assert(nextIndex > index); // To limit stack
		return m_dataArr[index];
	}

	void clear()
	{
		nextIndex = 0;
		delete[] m_dataArr;
		m_dataArr = nullptr;
	}
};

