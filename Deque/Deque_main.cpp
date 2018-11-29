/*
Data Structure::Deque(Double Ended Queue

Deque (double-ended queue,usually pronounced like "deck") is an indexed sequence container 
that allows fast insertion and deletion at both its beginning and its end.
//https://en.cppreference.com/w/cpp/container/deque

push_back 
Insert element at the end

push_front
Insert element at beginning

pop_back
Delete last element

pop_front
Delete first element
*/


#include <iostream>
#include "MyDeque.h"
#include <string>

using namespace std;

int main()
{
	MyDeque::Deque<string, 5> deque;

	deque.push_front("Alpha");
	cout << "push_front() " << deque.peek_front() << endl;
	deque.display();
	cout << endl;


	deque.push_front("Bravo");
	cout << "push_front() " << deque.peek_front() << endl;
	deque.display();
	cout << endl;

	deque.push_front("Charlie");
	cout << "push_front() " << deque.peek_front() << endl;
	deque.display();
	cout << endl;

	deque.push_front("Delta");
	cout << "push_front() " << deque.peek_front() << endl;
	deque.display();
	cout << endl;

	deque.push_front("Echo");
	cout << "push_front() " << deque.peek_front() << endl;
	deque.display();
	cout << endl;

	cout << "pop_back(), take back data "<< deque.pop_back() << endl;
	deque.display();
	cout << endl;

	cout <<"pop_front(), take front data " << deque.pop_front() << endl;
	deque.display();
	cout << endl;

	deque.push_back("Echo");
	cout << "push_back() " << deque.peek_back() << endl;
	deque.display();
	cout << endl;

	deque.push_back("Alpha");
	cout << "push_back() " << deque.peek_back() << endl;
	deque.display();
	cout << endl;


	return 0;
}