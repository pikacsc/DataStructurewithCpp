/*
AssortRockGameAcademy

CStackArray : Stack based on Array

*/
#pragma once
template <typename T, unsigned int SIZE>
class CStackArray
{

public:
	CStackArray()
	{
		m_uiCapacity = SIZE;
		m_uiSize = 0;

		m_pArray = new T[m_uiCapacity];
	}

	~CStackArray()
	{
		delete[] m_pArray;
	}

private:
	T*				m_pArray;
	unsigned int	m_uiSize;
	unsigned int	m_uiCapacity;

public:
	void push(const T& data)
	{
		if (full())
		{
			m_uiCapacity *= 2;
			T*	pArray = new T[m_uiCapacity];

			//memcpy : Memory copy function, copy (second argument)m_pArray datas to (first argument)pArray, as much as (third argument)m_uiSize
			memcpy(pArray, m_pArray, sizeof(T) * m_uiSize);

			//delete original
			delete[] m_pArray;
			m_pArray = pArray;
		}
		//To add data in last order
		m_pArray[m_uiSize] = data;
		++m_uiSize;
	}

	T top() const
	{
		if (empty())
			assert(false);
		return m_pArray[m_uiSize - 1];
	}

	T pop()
	{
		if (empty())
			assert(false);
		--m_uiSize;
		T	data = m_pArray[m_uiSize];
		return data;
	}

	void peek()
	{
		std::cout << m_pArray[m_uiSize - 1] << std::endl;
	}

	void clear()
	{
		m_uiSize = 0; //if uiSize is 0 then index will be 0 , so paste to original data, don't have to delete original data
	}


	bool empty() const
	{
		return m_uiSize == 0;
	}

	
	bool full() const
	{
		return m_uiSize == m_uiCapacity;
	}


	unsigned int size() const
	{
		return m_uiSize;
	}

	unsigned int capacity() const
	{
		return m_uiCapacity;
	}

	void print() const
	{
		if (empty())
			assert(false);
		for (unsigned int i = 0; i <= m_uiSize - 1; i++)
		{
			std::cout << m_pArray[i] << std::endl;
		}
	}

	void del()
	{
		m_uiSize--;
	}

};
