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


int main()
{
	using namespace std;
	MyStack<int, 5> my_stack;
	my_stack.push(1);
	my_stack.push(2);
	/*cout << my_stack[0] << endl;
	cout << my_stack[1] << endl;
	*/
	my_stack.print();
	cout << my_stack.pop() << endl; 
	return 0;
}

