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
#include "Deque.h"
#include <string>


//Memory Leak Check
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>  

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


	////linked list based Deque example
	////http://wondy1128.tistory.com/179
	//{
	//	exam_1::Deque * DQ = new exam_1::Deque;
	//	for (int i = 1; i < 5; i++) {
	//		DQ->push_front(i);
	//	}
	//	while (!DQ->empty()) {
	//		printf("%d\n", DQ->front());
	//		DQ->pop_front();
	//	}
	//	for (int i = 1; i < 5; i++) {
	//		DQ->push_back(-i);
	//	}

	//	while (!DQ->empty()) {
	//		printf("%d\n", DQ->back());
	//		DQ->pop_back();
	//	}
	//	for (int i = 1; i < 10; i++) {
	//		DQ->push_back(-i);
	//	}
	//	delete DQ;
	//}
	//

	deque.~Deque();
	_CrtDumpMemoryLeaks();

	return 0;
}