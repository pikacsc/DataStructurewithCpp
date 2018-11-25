
#include <iostream>
#include "LinkedList.h"
#include "MyLinkedList.h"
using namespace std;

int main()
{
	//ARGA::CList list;
	MyLinkedList<int> list;
	for (int i = 0; i < 100; ++i)
	{
		list.push_back(i);
	}


	list.display();
	list.clear();

	cout << list.empty() << endl;

	return 0;
}