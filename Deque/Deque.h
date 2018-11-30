#pragma once
#include <cstdio>

//Linked list based
//http://wondy1128.tistory.com/179
namespace exam_1
{
	class Deque 
	{
	private:
		struct node 
		{
			int data;
			node* prev;
			node* after;

			node()
			{
				prev = after = nullptr;
			}

			node(const int &input)
				:data(input)
			{
				prev = after = nullptr;
			}
		};
		node* pFront;
		node* pEnd;
		int element;
	
	public:
		Deque()
		{
			pFront = pEnd = nullptr;
		}

		~Deque()
		{
			while (!empty())
			{
				printf("Destructor : %d \n", back());
				pop_back();
			}
		}

		void push_front(const int& input)
		{
			node* new_node = new node(input);
			if (empty())
			{
				pFront = pEnd = new_node;
			}
			else
			{
				pFront->prev = new_node;
				new_node->after = pFront;
				pFront = pFront->prev;
			}
		}

		void push_back(const int& input)
		{
			node* new_node = new node(input);
			if (empty())
			{
				pFront = pEnd = new_node;
			}
			else
			{
				pFront->after = new_node;
				new_node->prev = pEnd;
				pEnd = pEnd->after;
			}
		}

		bool pop_front()
		{
			if (empty())
				return false;
			node* del_node = pFront;
			pFront = pFront->after;
			delete del_node;
			if (pFront == nullptr) pEnd = nullptr;
			return true;
		}

		bool pop_back()
		{
			if (empty())
				return false;
			node* del_node = pEnd;
			pEnd = pEnd->prev;
			delete del_node;
			if (pEnd == nullptr) pFront = nullptr;
			return true;
		}

		int front()
		{
			if (empty()) return -1;
			return pFront->data;
		}

		int back()
		{
			if (empty()) return -1;
			return pEnd->data;
		}

		bool empty()
		{
			if (pFront == nullptr && pEnd == nullptr)
				return true;
			return false;
		}
	};
}