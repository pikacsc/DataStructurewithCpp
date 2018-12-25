/*
Data Structure::Vector

Vectors are sequence containers representing arrays that can change in size.

Just like arrays, vectors use contiguous storage locations for their elements, 
which means that their elements can also be accessed using offsets on regular pointers to its elements, 
and just as efficiently as in arrays. But unlike arrays, their size can change dynamically, 
with their storage being handled automatically by the container.

Internally, vectors use a dynamically allocated array to store their elements. 
This array may need to be reallocated in order to grow in size when new elements are inserted, 
which implies allocating a new array and moving all elements to it. 
This is a relatively expensive task in terms of processing time, 
and thus, vectors do not reallocate each time an element is added to the container.

http://www.cplusplus.com/reference/vector/vector/

*/

#include <iostream>
#include "MyVector.h"
#include "Vector.h"
#include <vector>

//Memory Leak Check
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>  


using namespace std;

int main()
{
	//vector<int> vector;
	MyVector<int> vector;
	//EHLIB::Vector<int> vector;
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);
	vector.push_back(6);
	vector.push_back(7);
	vector.push_back(8);
	vector.push_back(9);
	vector.push_back(10);
	vector.push_back(11);
	vector.clear();

	vector.push_back(11);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(5);

	for (unsigned int i = 0; i < vector.size(); i++)
		cout << vector[i] << endl;



	_CrtDumpMemoryLeaks(); //To check memory leak
	return 0;
}