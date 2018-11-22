#pragma once
/*
AssortRockGameAcademy

*/
#include <assert.h>
namespace ARGA
{
	template<typename T, unsigned int SIZE>
	class CircleQueue
	{
	private:
		T				m_Array[SIZE + 1];
		unsigned int	m_uiSize;
		unsigned int	m_uiHead;
		unsigned int	m_uiTail;
	public:
		CircleQueue()
			:m_uiSize(0), m_uiHead(0), m_uiTail(0)
		{

		}

		~CircleQueue()
		{
		}

		void push(const T& data)
		{
			if (full())
				assert(false);

			unsigned int uiHead = static_cast<unsigned int>((m_uiHead + 1) % (SIZE + 1));
			m_Array[uiHead] = data;
			m_uiHead = uiHead;
			++m_uiSize;
		}

		T front() const
		{
			if (empty())
				assert(false);
			unsigned int uiTail = static_cast<unsigned int>((m_uiTail + 1) % (SIZE + 1));
			return m_Array[uiTail];
		}

		T back() const
		{
			if (empty())
				assert(false);
			unsigned int uiHead = static_cast<unsigned int>((m_uiHead) % (SIZE + 1));
			return m_Array[uiHead];
		}

		T pop()
		{
			if (empty())
				assert(false);

			int uiTail = static_cast<unsigned int>((m_uiTail + 1) % (SIZE + 1));
			T data = m_Array[uiTail];
			m_uiTail = uiTail;
			--m_uiSize;
			return data;
		}

		bool full() const
		{
			return m_uiSize == SIZE;
		}

		bool empty() const
		{
			return m_uiSize == 0;
		}

		unsigned int size() const
		{
			return m_uiSize;
		}

		void clear()
		{
			m_uiSize = 0;
			m_uiHead = 0;
			m_uiTail = 0;
		}

	};
}



/*
PROGRAMIZ
//https://www.programiz.com/dsa/circular-queue
*/
namespace PROGRAMIZ
{
	using namespace std;
	
	template<typename T, unsigned int SIZE>
	class CircleQueue
	{
	private:
		T items[SIZE];
		int frontIndex, rearIndex;
	public:
		CircleQueue()
			: frontIndex(-1), rearIndex(-1)
		{
		}

		//check whether queue is full or not
		bool isFull()
		{
			if (frontIndex == 0 && rearIndex == SIZE - 1) return true;
			if (frontIndex == rearIndex + 1) return true;
			return false;
		}

		//check whether queue is empty or not
		bool isEmpty()
		{
			if (frontIndex == -1) return true;
			else return false;
		}

		//insert element to rear
		void enQueue(const T &element)
		{
			if (isFull())
			{
				cout << "Queue is full" << endl;
			} 
			else
			{
				if (frontIndex == -1) frontIndex = 0;
				rearIndex = (rearIndex + 1) % SIZE;
				items[rearIndex] = element;
				cout << endl << "Inserted " << element << endl;
			}
		}


		// take front element
		T deQueueFront()
		{
			T element;
			if (isEmpty())
			{
				cout << "Queue is empty" << endl;
				return(false);
			}
			else
			{
				element = items[frontIndex];
				if (frontIndex == rearIndex) // Queue has only one element, so we reset the queue after deleting it
				{
					frontIndex = -1;
					rearIndex = -1;
				} 
				else
				{
					frontIndex = (frontIndex + 1) % SIZE;
				}
				return(element);
			}
		}


		//take rear element
		T deQueueRear()
		{
			T element;
			if (isEmpty())
			{
				cout << "Queue is empty" << endl;
				return(false);
			}
			else
			{
				element = items[rearIndex];
				if (frontIndex == rearIndex) // Queue has only one element, so we reset the queue after deleting it
				{
					frontIndex = -1;
					rearIndex = -1;
				}
				else
				{
					rearIndex = (rearIndex == 0) ? SIZE - 1 : rearIndex - 1;
				}
				return(element);
			}
		}

		//display status of Circular Queue
		void display() 
		{
			if (isEmpty())
				cout << endl << "Empty Queue" << endl;
			else
			{
				cout << "Items -> ";
				int i;
				for (i = frontIndex; i != rearIndex; i = (i + 1) % SIZE)
					cout << items[i] << " ";
				cout << items[i] << endl;
				cout << "front index -> " << frontIndex << " value -> " << items[frontIndex] << endl;
				cout << "rear index -> " << rearIndex << " value -> " << items[rearIndex] << endl;
				cout << endl;
			}
		}

	};
}
