#pragma once
#include <assert.h>
#include <tuple>
namespace SingleLinked
{
	template<typename T>
	class Node
	{
	private:
		T m_Data;
		unsigned int m_uiIndex;
		Node<T> *m_pNextNode;

	public:
		Node()
			:m_pNextNode(nullptr), m_uiIndex(NULL)
		{

		}

		~Node()
		{
			std::cout << "Node : " << this << " data : "<< m_Data <<  " deleted" << std::endl;
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


		unsigned int GetNodeIndex()
		{
			return m_uiIndex;
		}

		void SetNodeIndex(const unsigned int& new_uiIndex)
		{
			m_uiIndex = new_uiIndex;
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
				newNode->SetNodeIndex(m_uiSize + 1);
				m_pHead = m_pTail = newNode;
				m_uiSize++;
			}
			else
			{
				// create new node
				Node<T> *newNode = new Node<T>;
				newNode->SetData(data);
				newNode->SetNodeIndex(m_uiSize + 1);
				//set front node's nextnode  
				m_pTail->SetNextNode(newNode);

				//renew tail
				m_pTail = newNode;
				m_uiSize++;
			}
		}

		void display_nodeView()
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
					cout << "index : "<< currentNode->GetNodeIndex() << "\t|\tdata : " << currentNode->GetData() << endl;
					cout << "nextNode : " << currentNode->GetNextNode() << endl;
					cout << endl;
					cout << endl;
					currentNode = currentNode->GetNextNode();
				}
			}
		}

		void display_dataTable()
		{
			if (empty())
				assert(false);
			else
			{
				using namespace std;
				Node<T> *currentNode = m_pHead;
				cout << "index\t|\tdata" << endl;
				cout << "===============================" << endl;
				while (currentNode != nullptr)
				{
					cout << currentNode->GetNodeIndex() << "\t|\t" << currentNode->GetData() << endl;
					cout << "===============================" << endl;
					currentNode = currentNode->GetNextNode();
				}
			}
		}

		//take tail data
		T pop()
		{
			return *m_pTail;
		}

		//delete data by index, index renewal
		void del(const unsigned int& uiIndex)
		{
			using namespace std;
			auto result = SearchNodeByIndex(uiIndex);
			Node<T> *pPrevNode = get<0>(result);
			Node<T> *pCurrentNode = get<1>(result);
			unsigned int uiCurrentIndex = uiIndex;
			Node<T> *pNextNode = get<2>(result);

			delete pCurrentNode;
			pCurrentNode = nullptr;
			pNextNode->SetNodeIndex(uiIndex);
			pPrevNode->SetNextNode(pNextNode);
			pCurrentNode = pNextNode;
			unsigned int count = 0;
			
			//index renewal
			while (pCurrentNode != nullptr)
			{
				pNextNode = pCurrentNode->GetNextNode();
				pCurrentNode->SetNodeIndex(uiIndex + count++);
				pCurrentNode = pNextNode;
			}
		}

		auto SearchNodeByIndex(const unsigned int& uiIndex)
		{
			using namespace std;
			Node<T> *pCurrentNode = m_pHead; //temp Node<T> *
			Node<T> *pPrevNode = m_pHead;
			while (pCurrentNode != m_pTail)
			{
				
				Node<T> *pNextNode = pCurrentNode->GetNextNode();
				if (pCurrentNode->GetNodeIndex() == uiIndex)
					return tuple<Node<T>*, Node<T>*, Node<T>*>(pPrevNode, pCurrentNode, pNextNode);//finding succeed
				else
				{
					pPrevNode = pCurrentNode;
					pCurrentNode = pNextNode;
					if (pCurrentNode == nullptr)//when last one
					{
						return tuple<Node<T>*, Node<T>*, Node<T>*>(nullptr, nullptr, nullptr);
					}
				}
			}
			return tuple<Node<T>*, Node<T>*, Node<T>*>(nullptr, nullptr, nullptr);
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
					cout << "delete currentNode : " << pCurrentNode << " data : " << pCurrentNode->GetData() << endl;
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
						cout << "delete tail Node : " << pCurrentNode << " data : " << pCurrentNode->GetData() << endl;
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
}
