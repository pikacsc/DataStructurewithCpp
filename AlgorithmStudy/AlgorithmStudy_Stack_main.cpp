/*
Algorithm Study :: Data Structure 

Stack

Stack is literally stacking data like box tower, in that way 
the last one will be first out(LIFO)

Those functions will be member functions

push() 
insert data


pop()
get top data


peek()
not get but peek only


del()
delete top data


isEmpty(),
check stack is empty or not


getSize()
check how many datas in stack


print()
print all data



*/
#include <string>
#include "MyStack.h"
#include "CStackListBased.h"
#include "CStackArray.h"


//Memory Leak Check
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>  

int main()
{
	using namespace std;
	//_CrtSetBreakAlloc(164);


	//CStackArray<string, 10> my_stack;
	MyStack<string, 5> my_stack;
	cout << "box numbers are assigned by first-come." << endl;
	cout << "initial data" << endl;
	my_stack.push("[ 1.box ]");
	my_stack.push("[ 2.box ]");
	my_stack.push("[ 3.box ]");
	my_stack.push("[ 4.box ]");
	my_stack.print();
	cout << endl;
	cout << endl;

	cout << "peek() topdata : ";
	my_stack.peek();
	cout << endl;
	


	//bad coding, memory leak
	//string temp = my_stack.pop();  
	//cout << "pop(), take top data away (Last In First Out) " << temp << endl << endl;

	
	cout << "pop(), take top data away (Last In First Out) "<< my_stack.pop() << endl << endl;

	cout << "stack count : " << my_stack.size() << endl;
	my_stack.print();
	cout << endl;
	cout << endl;

	cout << "pop(), take top data away (Last In First Out) " << my_stack.pop() << endl << endl;

	cout << "stack count : " << my_stack.size() << endl;
	my_stack.print();
	cout << endl;
	cout << endl;



	my_stack.push("[ 5.box ]");
	cout << "push(), add data to top [ 5.box ]" << endl << endl;

	cout << "stack count : " << my_stack.size() << endl;
	my_stack.print();
	cout << endl;
	cout << endl;


	my_stack.push("[ 6.box ]");
	cout << "push(), add data to top [ 6.box ]" << endl << endl;

	cout << "stack count : " << my_stack.size() << endl;
	my_stack.print();
	cout << endl;
	cout << endl;


	my_stack.del();
	cout << "del(), delete top data" << endl << endl;

	cout << "stack count : " << my_stack.size() << endl;
	my_stack.print();
	cout << endl;
	cout << endl;


	my_stack.clear();
	cout << "after delete all" << endl;
	cout << "stack count : " << my_stack.size() << endl;
	my_stack.print();
	cout << endl;
	cout << endl;


	/*CStackListBased<string> stringStack;

	for (int i = 0; i < 10; ++i)
	{
		string box = to_string(i) + ".box";
		stringStack.push(box);
	}

	for(int i = 0; i < 10; ++i)
	{
		cout << stringStack.pop() << endl;
	}*/

	/*CStackArray<string, 10> stringStack;

	for (int i = 0; i < 10; ++i)
	{
		string box = to_string(i) + ".box";
		stringStack.push(box);
	}

	for(int i = 0; i < 10; ++i)
	{
		cout << stringStack.pop() << endl;
	}*/


	my_stack.~MyStack();
	_CrtDumpMemoryLeaks(); //To check memory leak

	return 0;
}

 