#include <iostream>
using namespace std;

template <class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		pAddress = new T[this->m_Capacity];
	}

	MyArray(const MyArray &arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		/* Note：pAddress是个指针，指向堆区，不能直接赋值，不然就是浅拷贝了，后面可能导致堆区重复释放
		普通类型可以直接= 但是指针类型需要深拷贝，必须需要重载 = 操作符*/
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			// T的拷贝问题不归我们管，我们只是使用封装好的T
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	/* 顺便还要支持链式，a=b=c */
	MyArray &operator=(const MyArray &myarray)
	{
		// 先判断原来的堆区是否有数据，有的话先清理
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		// 深拷贝
		this->m_Capacity = myarray.m_Capacity;
		this->m_Size = myarray.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = myarray[i];
		}
		return *this;
	}

	T &operator[](int index)
	{
		/* 不用考虑越界，由用户自己管理 */
		return this->pAddress[index];
	}

	void Push_back(const T &val)
	{
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	void Pop_back()
	{
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	int getCapacity()
	{
		return this->m_Capacity;
	}

	int getSize()
	{
		return this->m_Size;
	}

	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}

private:
	T *pAddress; // 指向一个堆空间，用来存放数据
	int m_Capacity;
	int m_Size;
};
