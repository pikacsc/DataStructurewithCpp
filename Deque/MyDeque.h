/*
Data Structure::Deque(Double Ended Queue

deque (usually pronounced like "deck") is an irregular acronym of double-ended queue.
Double-ended queues are sequence containers with dynamic sizes that can be expanded or contracted on both ends (either its front or its back).
//http://www.cplusplus.com/reference/deque/deque/

push_back
Insert element at the end

push_front
Insert element at beginning

pop_back
Delete last element

pop_front
Delete first element
*/

#pragma once
#include <assert.h>

namespace MyDeque
{
	using namespace std;
	template<typename T, unsigned int SIZE>
	class Deque
	{
	private:
		T				*m_DataArr;
		unsigned int	 m_uiSize;
		unsigned int	 m_uiCapacity;
	public:
		Deque()
			:m_DataArr(nullptr), m_uiSize(0), m_uiCapacity(SIZE)
		{
			m_DataArr = new T[m_uiCapacity];
		}

		~Deque()
		{
			clear();
		}

		//Clear content
		void clear()
		{
			delete[] m_DataArr;
			m_DataArr = nullptr;
		}

		//Test whether container is empty
		bool empty()
		{
			return m_uiSize == 0;
		}

		//Insert element at the end
		void push_back(const T& data)
		{
			m_DataArr[m_uiSize] = data;
			m_uiSize++;
		}

		//Insert element at beginning
		void push_front(const T& data)
		{
			if (empty())
				m_DataArr[m_uiSize] = data;
			else
			{
				//moving each array's element to back
				for (unsigned int i = m_uiSize; i > 0; i--)
				{
					m_DataArr[i] = m_DataArr[i - 1]; 
				}
				m_DataArr[0] = data;
			}
			m_uiSize++;	
		}


		//show all elements from front to back
		void display()
		{
			if (empty())
				assert(false);
			cout << "front";
			unsigned int count = 0;
			while (count < m_uiSize)
			{
				if (m_uiSize == 1)
				{
					cout << "==";
					break;
				}
				cout << "\t";
				count++;
			}
			cout << "back";
			cout << endl;


			count = 0;
			while (count < m_uiSize)
			{
				cout << "[" << m_DataArr[count] << "]";
				cout << "  ";
				count++;
			}
			cout << endl;
		}

		//Delete last element
		T pop_back()
		{
			if (empty())
				assert(false);
			return m_DataArr[--m_uiSize];
		}

		//Delete first element
		T pop_front()
		{
			T frontData = m_DataArr[0];
			if (empty())
				assert(false);
			else
			{
				//moving each array's element to front
				for (unsigned int i = 0; i < m_uiSize; i++)
				{
					m_DataArr[i] = m_DataArr[i+1];
				}
			}
			m_uiSize--;
			return frontData;
		}

		//peek end element
		T peek_back()
		{
			if (empty())
				assert(false);
			return m_DataArr[m_uiSize - 1];
		}

		//peek front element
		T peek_front()
		{
			if (empty())
				assert(false);
			return m_DataArr[0];
		}
	};
}