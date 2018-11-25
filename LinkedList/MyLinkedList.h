#pragma once
#include <assert.h>

template<typename T>
class Node
{
private:
	T m_Data;
	Node *m_pNextNode;

public:
	Node()
		:m_pNextNode(nullptr)
	{

	}

	~Node()
	{

	}

	T GetData()
	{
		return m_Data;
	}

	void SetData(const T& data)
	{
		m_Data = data;
	}

	Node GetNextNode()
	{
		return *m_pNextNode;
	}

	void SetNextNode(Node* node)
	{
		m_pNextNode = node;
	}


};

template<typename T>
class MyLinkedList
{
private:
	Node<T> *m_pHead;
	Node<T> *m_pTail;
	unsigned int m_uiSize;

public:
	MyLinkedList()
		:m_pHead(nullptr), m_pTail(nullptr), m_uiSize(0)
	{
	}

	~MyLinkedList()
	{
		delete m_pHead;
		m_pHead = nullptr;

		delete m_pTail;
		m_pTail = nullptr;
	}

	void push_back(const T& data)
	{
		if (empty())
		{
			Node<T> *newNode = new Node<T>;
			newNode->SetData(data);
			m_pHead = m_pTail = newNode;
			m_uiSize++;
		}
		else
		{
			// create new node
			Node<T> *newNode = new Node<T>; 
			newNode->SetData(data); 

			//set front node's nextnode  
			m_pTail->SetNextNode(newNode);
			
			//renew tail
			m_pTail = newNode;
			m_uiSize++;
		}
	}

	void display()
	{
		if (empty())
			assert(false);
		else
		{
			Node<T> *currentNode = m_pHead;
			while (currentNode != nullptr)
			{
				using namespace std;
				cout << currentNode->GetData() << endl;
				*currentNode = currentNode->GetNextNode();
			}
		}
	}

	T pop()
	{

	}

	bool empty()
	{
		return m_uiSize == 0;
	}


	void clear()//in progress...
	{
		if (empty())
			assert(false);
		Node<T> *pCurrentNode = m_pHead;
		Node<T> *pNextNode = &(m_pHead->GetNextNode());
		while (!empty())
		{
		*pNextNode = pCurrentNode->GetNextNode();
			if (pNextNode == nullptr)
			{
				delete pCurrentNode;
				m_uiSize--;
				break;
			}
		delete pCurrentNode;	
		m_uiSize--;
		pCurrentNode = pNextNode;
		}
	}

};