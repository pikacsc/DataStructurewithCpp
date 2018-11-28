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
		Node<T> *m_pNextNode;

	public:
		Node()
			:m_pNextNode(nullptr)
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

		void display_nodeView()
		{
			if (empty())
				assert(false);
			else
			{
				Node<T> *currentNode = m_pHead;
				unsigned int count = 1;
				while (currentNode != nullptr)
				{
					using namespace std;
					cout << "currentNode : " << currentNode << endl;
					cout << "index : "<< count++ << "\t|\tdata : " << currentNode->GetData() << endl;
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
				unsigned int count = 1;
				while (currentNode != nullptr)
				{
					cout << count++ << "\t|\t" << currentNode->GetData() << endl;
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
			Node<T> *pNextNode = get<2>(result);

			delete pCurrentNode;
			pCurrentNode = nullptr;
			
			if (pPrevNode == nullptr) // if deleted node was Head
			{
				m_pHead = pNextNode;
				pNextNode = pNextNode->GetNextNode();
				m_pHead->SetNextNode(pNextNode);
			}
			if (pNextNode == nullptr) // if deleted node was Tail
			{
				m_pTail = pPrevNode;
				m_pTail->SetNextNode(nullptr);
			}
			if(pPrevNode != nullptr && pNextNode != nullptr )
				pPrevNode->SetNextNode(pNextNode);
			m_uiSize--;
		}

		auto SearchNodeByIndex(const unsigned int& uiIndex)
		{
			using namespace std;
			Node<T> *pCurrentNode = m_pHead; //temp Node<T> *
			Node<T> *pPrevNode = nullptr;
			Node<T> *pNextNode = pCurrentNode->GetNextNode();
			for (unsigned int i = 1; i <= uiIndex + 1; i++)
			{
				if (i == (uiIndex - 1)) // prev node 
				{
					pPrevNode = pCurrentNode;
					pCurrentNode = pCurrentNode->GetNextNode();
					continue;
				}
				if (i == uiIndex) // current node
				{
					pNextNode = pCurrentNode->GetNextNode();
					break;
				}
				pPrevNode = pCurrentNode;
				pCurrentNode = pCurrentNode->GetNextNode();
			}
			return tuple<Node<T>*, Node<T>*, Node<T>*>(pPrevNode, pCurrentNode, pNextNode);
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


namespace DoubleLinked
{
	template<typename T>
	class Node
	{
	private:
		T m_Data;
		Node<T> *m_pPrevNode;
		Node<T> *m_pNextNode;

	public:
		Node()
			:m_pPrevNode(nullptr),m_pNextNode(nullptr)
		{

		}

		~Node()
		{
			std::cout << "Node : " << this << " data : " << m_Data << " deleted" << std::endl;
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


		Node<T>* GetPrevNode()
		{
			return m_pPrevNode;
		}

		void SetPrevNode(Node* node)
		{
			m_pPrevNode = node;
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
				Node<T> *pNewNode = new Node<T>;
				Node<T> *pPrevNode = nullptr;
				pNewNode->SetData(data);

				//set front node's nextnode  
				m_pTail->SetNextNode(pNewNode); //set old Tail's next node, new node

				pPrevNode = m_pTail; //save old Tail as a prev node

				//renew tail
				// old Tail(pPrevNode) -> new Tail(m_pTail)
				m_pTail = pNewNode; 
				m_pTail->SetPrevNode(pPrevNode);
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
				unsigned int count = 1;
				while (currentNode != nullptr)
				{
					using namespace std;
					cout << "-----------------NODE------------------" << endl;
					cout << "prevNode : " << currentNode->GetPrevNode() << endl;
					cout << "\tcurrentNode : " << currentNode << endl;
				    cout << "nextNode: " << currentNode->GetNextNode() << endl;
					cout << "index : " << count++ << "\t|\tdata : " << currentNode->GetData() << endl;
					cout << "---------------------------------------" << endl;
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
				unsigned int count = 1;
				while (currentNode != nullptr)
				{
					cout << count++ << "\t|\t" << currentNode->GetData() << endl;
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
			Node<T> *pCurrentNode = SearchNodeByIndex(uiIndex);
			Node<T> *pPrevNode = pCurrentNode->GetPrevNode();
			Node<T> *pNextNode = pCurrentNode->GetNextNode();

			delete pCurrentNode;
			pCurrentNode = nullptr;

			if (pPrevNode == nullptr) // if deleted node was Head
			{
				m_pHead = pNextNode;
				pNextNode = pNextNode->GetNextNode();
				m_pHead->SetNextNode(pNextNode);
				m_pHead->SetPrevNode(nullptr);
			}
			if (pNextNode == nullptr) // if deleted node was Tail
			{
				m_pTail = pPrevNode;
				m_pTail->SetNextNode(nullptr);
			}
			if (pPrevNode != nullptr && pNextNode != nullptr)
			{
				pPrevNode->SetNextNode(pNextNode);
				pNextNode->SetPrevNode(pPrevNode);
			}
			m_uiSize--;

		}

		Node<T>* SearchNodeByIndex(const unsigned int& uiIndex)
		{
			using namespace std;
			Node<T> *pCurrentNode = m_pHead; //temp Node<T> *
			for (unsigned int i = 1; i <= uiIndex + 1; i++)
			{
				if (i == uiIndex)//finding succeed
				{
					break;
				}
				pCurrentNode = pCurrentNode->GetNextNode();
			}
			return pCurrentNode;
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




namespace CircularLinked
{
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
			std::cout << "Node : " << this << " data : " << m_Data << " deleted" << std::endl;
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
				newNode->SetNextNode(m_pHead); //Circular Linked
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
				unsigned int count = 1;
				while (count <= m_uiSize)
				{
					using namespace std;
					cout << "currentNode : " << currentNode << endl;
					cout << "index : " << count++ << "\t|\tdata : " << currentNode->GetData() << endl;
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
				unsigned int count = 1;
				while (count <= m_uiSize)
				{
					cout << count++ << "\t|\t" << currentNode->GetData() << endl;
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
			Node<T> *pNextNode = get<2>(result);

			delete pCurrentNode;
			pCurrentNode = nullptr;

			if (pPrevNode == m_pTail) // if deleted node was Head
			{
				m_pHead = pNextNode;
				pNextNode = pNextNode->GetNextNode();
				m_pHead->SetNextNode(pNextNode);
				m_pTail->SetNextNode(m_pHead);
			}
			if (pNextNode == m_pHead) // if deleted node was Tail
			{
				m_pTail = pPrevNode;
				m_pTail->SetNextNode(m_pHead);
			}
			if (pPrevNode != m_pTail && pNextNode != m_pHead)
				pPrevNode->SetNextNode(pNextNode);
			m_uiSize--;
		}

		auto SearchNodeByIndex(const unsigned int& uiIndex)
		{
			using namespace std;
			Node<T> *pCurrentNode = m_pHead; 
			Node<T> *pPrevNode = m_pTail; // Circular Linked, m_pTail(pPrevNode) -> m_pHead
			Node<T> *pNextNode = pCurrentNode->GetNextNode();
			for (unsigned int i = 1; i <= uiIndex + 1; i++)
			{
				if (i == (uiIndex - 1)) // prev node 
				{
					pPrevNode = pCurrentNode;
					pCurrentNode = pCurrentNode->GetNextNode();
					continue;
				}
				if (i == uiIndex) // current node
				{
					pNextNode = pCurrentNode->GetNextNode();
					break;
				}
				pPrevNode = pCurrentNode;
				pCurrentNode = pCurrentNode->GetNextNode();
			}
			return tuple<Node<T>*, Node<T>*, Node<T>*>(pPrevNode, pCurrentNode, pNextNode);
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
