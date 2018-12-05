/*
Data Structure::Queue

queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out),
where elements are inserted into one end of the container and extracted from the other.
//http://www.cplusplus.com/reference/queue/queue/

empty
Returns whether the queue is empty.

size
Returns the number of elements in the queue.

front
Returns the "oldest" element in the queue.

back
Returns the "newest" element in the queue.

push
Inserts a new element at the end of the queue(back of the queue),

pop
take the "oldest" element then next first come element will be "oldest"


*/

#pragma once


template<typename T,unsigned int uiSIZE>
class MyQueue
{
public:
	MyQueue()
	{
		m_uiCapacity = uiSIZE;
		m_uiFrontIndex = m_uiCapacity - 1;
		m_uiBackIndex = m_uiFrontIndex;
		m_uiNextElementIndex = m_uiBackIndex;
		m_tDataArr = new T[m_uiCapacity];
	}

	~MyQueue()
	{
		clear();
	}

private:
	T*					m_tDataArr;
	unsigned int		m_uiCapacity;
	unsigned int		m_uiFrontIndex;
	unsigned int		m_uiBackIndex;
	unsigned int		m_uiNextElementIndex;
public:
	//Returns whether the queue is empty.
	bool empty() const
	{
		return (m_uiFrontIndex == m_uiNextElementIndex);
	}

	//Returns the number of elements in the queue.
	unsigned int size() const
	{
		return m_uiFrontIndex - m_uiNextElementIndex;
	}

	//Returns the "oldest" element in the queue.
	T front() const
	{
		return m_tDataArr[m_uiFrontIndex];
	}

	//Returns the "newest" element in the queue.
	T back() const
	{
		return m_tDataArr[m_uiBackIndex];
	}

	//Inserts a new element at the end of the queue(back of the queue),
	void push(const T& data)
	{
		m_tDataArr[m_uiNextElementIndex] = data;
		m_uiBackIndex = m_uiNextElementIndex;
		m_uiNextElementIndex--;
	}

	//take the "oldest" element then next first come element will be "oldest"
	T pop()
	{
		T returnData = m_tDataArr[m_uiFrontIndex];
		if (size() == 1) // in case, only one data
		{
			m_uiNextElementIndex = m_uiFrontIndex;
		}
		else
		{
			for (unsigned int i = m_uiFrontIndex; i >= m_uiBackIndex; i--)
			{
				if (i == m_uiBackIndex) break;
				m_tDataArr[i] = m_tDataArr[i - 1];
			}
		}
		m_uiNextElementIndex++;
		return returnData;
	}

	void clear()
	{
		delete[] m_tDataArr;
		m_tDataArr = nullptr;
	}

};