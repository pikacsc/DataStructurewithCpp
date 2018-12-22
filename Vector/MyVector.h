
#pragma once
#include <assert.h>

template<typename T>
class MyVector {
private:
	T *mDataArr;
	unsigned int mCapacity;
	unsigned int mSize;
public:
	MyVector()
	{
		mCapacity = 1;
		mSize = 0;
		mDataArr = new T[mCapacity];
	}

	~MyVector()
	{
		delete[] mDataArr;
		mDataArr = nullptr;
	}


	T& operator [] (const unsigned int index) const
	{
		if (index > mSize)
			assert(false);
		return mDataArr[index];
	}


	//insert data at back of last element;
	void push_back(const T& data)
	{
		if (mSize == mCapacity)
			reserve(mCapacity * 2);
		mDataArr[mSize] = data;
		mSize++;
	}

	//delete last element;
	void pop_back()
	{
		mSize--;
	}

	//extend memory space in vector as much as number
	void reserve(const unsigned int &extendSize)
	{
		T *tempDataArr = new T[extendSize];
		for (unsigned int i = 0; i < mSize; i++)
			tempDataArr[i] = mDataArr[i];
		delete[] mDataArr;
		mDataArr = tempDataArr;
		mCapacity = extendSize;
	}


	void resize(const unsigned int &newSize, const T& data = 0)
	{
		assert(newSize < mCapacity);
		if (newSize < mSize)
			mSize = newSize;
		else
		{
			for (int i = mSize; i < newSize; i++)
				mDataArr[i] = data; //default value initialize 
		}
	}




	unsigned int capacity()
	{
		return mCapacity;
	}



	bool empty() {
		return (mSize == 0);
	}

	unsigned int size() {
		return mSize;
	}



};