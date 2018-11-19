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
#include "MyStack.h"
#include <string>

int main()
{
	using namespace std;
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
	
	string popData = my_stack.pop();
	cout << "pop(), take top data away (Last In First Out) "<< popData << endl << endl;

	cout << "stack count : " << my_stack.getSize() << endl;
	my_stack.print();
	cout << endl;
	cout << endl;


	my_stack.push("[ 5.box ]");
	cout << "push(), add data to top [ 5.box ]" << endl << endl;

	cout << "stack count : " << my_stack.getSize() << endl;
	my_stack.print();
	cout << endl;
	cout << endl;


	my_stack.push("[ 6.box ]");
	cout << "push(), add data to top [ 6.box ]" << endl << endl;

	cout << "stack count : " << my_stack.getSize() << endl;
	my_stack.print();
	cout << endl;
	cout << endl;


	my_stack.del();
	cout << "del(), delete top data" << endl << endl;

	cout << "stack count : " << my_stack.getSize() << endl;
	my_stack.print();
	cout << endl;
	cout << endl;


	my_stack.del();
	my_stack.del();
	my_stack.del();
	my_stack.del();
	cout << "after delete all" << endl;
	cout << "stack count : " << my_stack.getSize() << endl;
	my_stack.print();
	cout << endl;
	cout << endl;

	return 0;
}

