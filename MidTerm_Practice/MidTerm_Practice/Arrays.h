#ifndef _ARRAYS_H_
#define _ARRAYS_H_

#include <assert.h>

template<typename T>
class UnorderedArray
{
private:
	T *m_array;
	int m_maxSize;
	int m_growSize;
	int m_numElements;

private:
	bool Expand()
	{
		if (m_growSize <= 0)
			return false;

		T *temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);
		memcpy(temp, m_array, sizeof(T) * m_maxSize);
		delete[] m_array;
		m_array = temp;
		m_maxSize += m_growSize;
		return true;
	}

public:
	UnorderedArray(int size, int growBy = 1) : m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);
			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	~UnorderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}

	void push(T val)
	{
		assert(m_array != NULL);
		if (m_numElements >= m_maxSize)
			Expand();
		m_array[m_numElements] = val;
		m_numElements++;
	}
	void pop()
	{
		if (m_numElements > 0)
			m_numElements--;
	}
	void remove(int index)
	{
		assert(m_array != NULL);
		if (index >= m_maxSize)
			return;
		for (int k = index; k < m_maxSize - 1; k++)
			m_array[k] = m_array[k + 1];
		m_maxSize--;
		if (m_numElements >= m_maxSize)
			m_numElements = m_maxSize - 1;
	}

	T& operator[](int index)
	{
		assert(m_array != NULL && index <= m_numElements);
		return m_array[index];
	}

	int search(T val)
	{
		assert(m_array != NULL);
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
				return i;
		}
		return -1;
	}

	void BubbleSort()
	{
		assert(m_array != NULL);
		for (int k = m_numElements - 1; k > 0; k--)
		{
			bool sorted;
			for (int i = 0; i < k; i++)
			{
				if (m_array[i] > m_array[i + 1])
				{
					T temp = m_array[i];
					m_array[i] = m_array[i + 1];
					m_array[i + 1] = temp;
					sorted = false;
				}
			}
			if (sorted)
				break;
		}
	}

	void clear() { m_numElements = 0; }
	int GetSize() { return m_numElements; }
	int GetMaxSize() { return m_maxSize; }
	int GetGrowSize() { return m_growSize; }

	void SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}
};

template <typename T>
class OrderedArray
{
private:
	T *m_array;
	int m_maxSize;
	int m_growSize;
	int m_numElements;

private:
	bool Expand()
	{
		if (m_growSize <= 0)
			return false;

		T *temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);
		memcpy(temp, m_array, sizeof(T) * m_maxSize);
		delete[] m_array;
		m_array = temp;
		m_maxSize += m_growSize;
		return true;
	}

public:
	OrderedArray(int size, int growBy = 1) : m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);
			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	~OrderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}

	int push(T val)
	{
		assert(m_array != NULL);
		if (m_numElements >= m_maxSize)
			Expand();
		int i, k;
		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;
		while (lowerBound <= upperBound)
		{
			current = (lowerBound + upperBound) >> 1;
			if (m_array[current] == val)
			{
				upperBound = current - 1;
				break;
			}
			else
			{
				if (m_array[current] < val)
					lowerBound = current + 1;
				else
					upperBound = current - 1;
			}
		}
		i = upperBound + 1;
		for (k = m_numElements; k > i; k--)
		{
			m_array[k] = m_array[k - 1];
		}
		m_array[i] = val;
		m_numElements++;
		return i;
	}
	void pop()
	{
		if (m_numElements > 0)
			m_numElements--;
	}
	void remove(int index)
	{
		assert(m_array != NULL);
		if (index >= m_maxSize)
			return;
		for (int k = index; k < m_maxSize; k++)
			m_array[k] = m_array[k + 1];
		m_maxSize--;
		if (m_numElements >= m_maxSize)
			m_numElements = m_maxSize - 1;
	}

	const T& operator[] (int index)
	{
		asset(m_array != NULL && index <= m_numElements);
		return m_array[index];
	}

	int search(T searchKey)
	{
		assert(m_array != NULL);
		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;

		while (1)
		{
			current = (lowerBound + upperBound) >> 1;
			if (m_array[current] == searchKey)
				return current;
			else if (lowerBound > upperBound)
				return -1;
			else
			{
				if (m_array[current] < searchKey)
					lowerBound = current + 1;
				else
					upperBound = current - 1;
			}
			return -1;
		}
	}

	void clear() { m_numElements = 0; }
	int GetSize() { return m_numElements; }
	int GetMaxSize() { return m_maxSize; }
	int GetGrowSize() { return m_growSize; }

	void SetGrowSize(int val)
	{
		asset(val >= 0);
		m_growSize = val;
	}
};

#endif