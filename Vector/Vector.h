
//author : http://ehclub.co.kr/1235
#pragma once
namespace EHLIB
{
	template<typename T>
	class Vector
	{
	private:
		T *mBase;
		size_t mbSize;
		size_t mbCapacity;
	public:
		class Iterator
		{
		private:
			T *mPos;
		public:
			Iterator(T *pos = 0)
			{
				this->mPos = pos;
			}

			T operator *()
			{
				return *mPos;
			}

			int operator-(const Iterator &iter)
			{
				return mPos - iter.mPos;
			}

			Iterator &operator++()
			{
				mPos++;
				return(*this);
			}

			const Iterator operator++(int)
			{
				Iterator re(*this);
				mPos++;
				return re;
			}

			bool operator!=(const Iterator& iter)
			{
				return mPos == iter.mPos;
			}

			bool operator==(const Iterator& iter)
			{
				return mPos == iter.mPos;
			}

		};

		Vector(size_t init_cnt = 0, T t = 0)
		{
			mBase = 0;
			mbSize = 0;
			mbCapacity = 0;
			reserve(init_cnt);
			push_backs(init_cnt, t);
		}

		~Vector()
		{
			if (mBase)
				delete[] mBase;
		}

		void push_backs(size_t cnt, T t)
		{
			for (size_t n = 0; n < cnt; n++)
				push_back(t);
		}

		void reserve(size_t nCapacity)
		{
			T *temp = new T[nCapacity];
			if (mbSize)
			{
				for (size_t n = 0; n < mbSize; n++)
					temp[n] = mBase[n];
				delete[] mBase;
			}
			mBase = temp;
			mbCapacity = nCapacity;
		}


		void resize(size_t nSize)
		{
			if (nSize > mbCapacity)
				reserve(nSize);
			for (size_t n = mbSize; n < nSize; n++)
				insert(end(), 0);
		}

		void push_back(T t)
		{
			insert(end(), t);
		}

		void insert(Iterator at, T t)
		{
			size_t index = at - mBase;
			if (mbSize == mbCapacity)
				reserve(mbCapacity + 10);
			for (size_t n = mbSize; n > index; n--)
				mBase[n] = mBase[n - 1];
			mBase[index] = t;
			mbSize++;
		}

		void erase(Iterator at)
		{
			int index = at - mBase;

			for (size_t n = index + 1; n < mbSize; n++)
				mBase[n - 1] = mBase[n];
			mbSize--;
		}

		T& operator[] (size_t index)
		{
			if (index < mbSize)
				return mBase[index];
			throw "Wrong index";
		}

		Iterator begin()
		{
			return mBase;
		}

		Iterator end()
		{
			return mBase + mbSize;
		}

		size_t size()
		{
			return mbSize;
		}

		size_t capacity()
		{
			return mbCapacity;
		}
	};
}