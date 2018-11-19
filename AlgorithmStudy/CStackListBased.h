/*
AssortRockGameAcademy

CStackListBased : Stack based on Linkedlist  

*/

#pragma once
#include <assert.h>
template <typename T>
class CStackNode
{
private:
	template<typename T>
	friend class   CStackListBased;
	
	
	CStackNode<T>* m_pNext;
	T			   m_Data;

public:
	CStackNode()
		:m_pNext(nullptr)
	{

	}

	~CStackNode()
	{
	}

};


template<typename T>
class CStackListBased
{
private:
	typedef CStackNode<T>	NODE;
	typedef CStackNode<T>*	PNODE;
	PNODE					m_pNode;
	unsigned int			m_iSize;
public:
	CStackListBased()
		:m_pNode(nullptr), m_iSize(0)
	{

	}

	~CStackListBased()
	{
		clear();
	}

	//add data
	void push(const T& data)
	{
		PNODE pNode = new NODE;// To add data, construct NODE
		pNode->m_Data = data;

		//next NODE wil be m_pNode
		//m_pNode is always last NODE
		//however, in first construct case, there is no next node
		//so m_pNode is nullptr
		pNode->m_pNext = m_pNode;


		//new NODE is always last NODE
		m_pNode = pNode;

		++m_iSize;
	}

	T top() const
	{
		if (empty())
			assert(false);
		return m_pNode->m_Data;
	}

	//Remove top element
	T pop()
	{
		if (empty())
			assert(false);
		//get last NODE's m_pNext 
		PNODE pNext = m_pNode->m_pNext;
		T	  data = m_pNode->m_Data;

		//delete last node
		delete m_pNode;
		m_pNode = pNext;
		--m_iSize;

		return data;
	}


	void clear()
	{
		PNODE	pNode = m_pNode;

		while (pNode)
		{
			//get next node
			PNODE pNext = pNode->m_pNext;

			delete pNode;

			pNode = pNext;
		}

		m_iSize = 0;
	}


	bool empty() const
	{
		return m_iSize == 0;
	}

	int size() const
	{
		return m_iSize;
	}
};