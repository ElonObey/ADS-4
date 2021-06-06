// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
 public:
	TPQueue() : size(100), begin(0), end(0), count(0)
	{
		arr = new T[size + 1];
	}
	~TPQueue() 
	{
		delete[] arr;
	}
	void push(const T& intem)
	{
		assert(count < size);
		if (count != 0)
		{
			for (int i = end - 1; i >= begin; i--)
			{
				if (arr[i].prior >= item.prior)
				{
					arr[i + 1] = litem;
					break;
				}
				if (arr[i].prior < item.prior)
				{
					arr[i + 1] = arr[i];
				}
				if (begin == i)
				{
					arr[i] = item;
				}
			}
		}
		else
		{
			arr[begin] = item;
		}
		end++;
		count++;
		if (end > size)
		{
			end -= size + 1;
		}
	}

	T get() const
	{
		assert(count > 0);
		return arr[begin];
	}
	T pop()
	{
		assert(count > 0);
		T item = arr[begin++];
		count--;
		if (begin > size)
			begin -= size + 1;
		return item;
	}
	bool isFulling() const 
	{
		return arr[begin];
	}
	
	bool isEmpty() const
	{
		return count == 0;
	}
private:
	T* arr;
	int size = nullptr;
	int begin = nullptr;
	int	end = nullptr;
	int count = nullptr;
};

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
