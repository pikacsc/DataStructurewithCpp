/*
Data Structure::Queue

queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out),
where elements are inserted into one end of the container and extracted from the other.
//http://www.cplusplus.com/reference/queue/queue/

empty
Returns whether the queue is empty.

size
Returns the number of elements in the queue.

front
Returns the "oldest" element in the queue.

back
Returns the "newest" element in the queue.

push
Inserts a new element at the end of the queue(back of the queue),

pop
Removes the "oldest" element then next first come element will be "oldest"


*/

#include <iostream>
#include "MyQueue.h"
#include <string>
using namespace std;

int main()
{
	MyQueue<string, 10> queue;
	queue.push("[ 1.box ]");
	queue.push("[ 2.box ]");
	queue.push("[ 3.box ]");
	queue.push("[ 4.box ]");
	queue.push("[ 5.box ]");
	queue.push("[ 6.box ]");
	cout << "data count : " << queue.size() << endl;
	cout << "front(oldest one) : " << queue.front() << endl;
	cout << "back(newest one)  : "<< queue.back() << endl;
	cout << endl;
	cout << endl;
	cout << endl;



	queue.pop();
	cout << "pop(), remove oldest(most first) one" << endl;
	cout << "data count : " << queue.size() << endl;
	cout << "front(oldest one) : " << queue.front() << endl;
	cout << "back(newest one)  : " << queue.back() << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	queue.pop();
	cout << "pop(), remove oldest(most first) one" << endl;
	cout << "data count : " << queue.size() << endl;
	cout << "front(oldest one) : " << queue.front() << endl;
	cout << "back(newest one)  : " << queue.back() << endl;
	cout << endl;
	cout << endl;
	cout << endl;



	queue.pop();
	cout << "pop(), remove oldest(most front) one" << endl;
	cout << "data count : " << queue.size() << endl;
	cout << "front(oldest one) : " << queue.front() << endl;
	cout << "back(newest one)  : " << queue.back() << endl;
	cout << endl;
	cout << endl;
	cout << endl;



	queue.push("[ 7.box ]");
	cout << "push(), add [ 7.box ] to back" << endl;
	cout << "data count : " << queue.size() << endl;
	cout << "front(oldest one) : " << queue.front() << endl;
	cout << "back(newest one)  : " << queue.back() << endl;
	cout << endl;
	cout << endl;
	cout << endl;



	queue.pop();
	cout << "pop(), remove oldest(front) one" << endl;
	cout << "data count : " << queue.size() << endl;
	cout << "front(oldest one) : " << queue.front() << endl;
	cout << "back(newest one)  : " << queue.back() << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	queue.push("[ 8.box ]");
	cout << "push(), add [ 8.box ] to back" << endl;
	cout << "data count : " << queue.size() << endl;
	cout << "front(oldest one) : " << queue.front() << endl;
	cout << "back(newest one)  : " << queue.back() << endl;
	cout << endl;
	cout << endl;
	cout << endl;



	queue.pop();
	cout << "pop(), remove oldest(front) one" << endl;
	cout << "data count : " << queue.size() << endl;
	cout << "front(oldest one) : " << queue.front() << endl;
	cout << "back(newest one)  : " << queue.back() << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	return 0;
}