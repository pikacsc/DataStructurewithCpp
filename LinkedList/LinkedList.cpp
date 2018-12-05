
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "MyLinkedList.h"


//Memory Leak Check
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>  


using namespace std;

int main()
{
	//ARGA::CList list;
	//SingleLinked::MyLinkedList<int> list;
	/*for (int i = 0; i < 100; ++i)
	{
		list.push_back(i);
	}
*/
	//SingleLinked::MyLinkedList<string> list;
	//DoubleLinked::MyLinkedList<string> list;
	CircularLinked::MyLinkedList<string> list;
	list.push_back("Apple");
	list.push_back("Cherry");
	list.push_back("Banana");
	list.push_back("Strawberry");
	list.push_back("Grape");


	list.display_nodeView();
	//list.display_dataTable();
	cout << endl;
	cout << endl;
	list.del(1);
	cout << endl;
	cout << endl;
	list.display_nodeView();
	//list.display_dataTable();
	
	list.~MyLinkedList();

	_CrtDumpMemoryLeaks();
	
	return 0;
}