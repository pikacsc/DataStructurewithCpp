#pragma once
#include <assert.h>

template<typename T>
class Node
{
private:
	T m_Data;
	Node<T> *m_pNextNode;

public:
	Node()
		:m_pNextNode(nullptr)
	{

	}

	~Node()
	{
		std::cout << "Node : " << this << " deleted" << std::endl;
	}

	T GetData()
	{
		return m_Data;
	}

	void SetData(const T& data)
	{
		m_Data = data;
	}

	Node<T>* GetNextNode()
	{
		return m_pNextNode;
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
		clear();
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
				cout << "currentNode : " << currentNode << endl;
				cout << "data : " << currentNode->GetData() << endl;
				cout << "nextNode : " << currentNode->GetNextNode() << endl;
				cout << endl;
				cout << endl;
				currentNode = currentNode->GetNextNode();
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


	void clear()
	{
		using namespace std;
		if (empty())
			cout << "no data left" << endl;
		else
		{
			cout << "delete process begin..." << endl;
			Node<T> *pCurrentNode = m_pHead; //temp Node<T> *
			while (pCurrentNode != m_pTail)
			{
				cout << "delete currentNode : " << pCurrentNode << endl;
				cout << "data : " << pCurrentNode->GetData() << endl;
				
				//main logic to delete all
				Node<T> *pNextNode = pCurrentNode->GetNextNode();
				delete pCurrentNode;
				pCurrentNode = pNextNode;
				
				
				cout << "list size : " << --m_uiSize << endl;
				cout << "change currentNode to next node " << pCurrentNode << endl;
				cout << endl;
				cout << endl;
				if (pCurrentNode == m_pTail)//when last one
				{
					cout << "delete tail Node : " << pCurrentNode << endl;
					cout << "data : " << pCurrentNode->GetData() << endl;
					delete pCurrentNode;
					cout << "list size : " << --m_uiSize << endl;
					pCurrentNode = nullptr;
					break;
				}
			}
			m_uiSize = 0;
		}
		
	}

};