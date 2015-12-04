#ifndef _UNORDERED_ARRAY_H_
#define _UNORDERED_ARRAY_H_

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
		assert(temp != 0);
		memcpy(temp, m_array, sizeof(T) * m_maxSize);
		delete[] m_array;
		m_array = temp;
		m_maxSize += m_growSize;
		return true;
	}

	void MergeSort(T *tempArray, int lowerBound, int upperBound)
	{
		if (lowerBound == upperBound)
			return;
		int mid = (lowerBound + upperBound) >> 1;
		MergeSort(tempArray, lowerBound, mid);
		MergeSort(tempArray, mid + 1, upperBound);
		Merge(tempArray, lowerBound, mid + 1, upperBound);
	}

	void Merge(T *tempArray, int low, int mid, int upper)
	{
		int tempLow = low, tempMid = mid - 1;
		int index = 0;
		while (low <= tempMid && mid <= upper)
		{
			if (m_array[low] < m_array[mid])
				tempArray[index++] = m_array[low++];
			else
				tempArray[index++] = m_array[mid++];
		}
		while (low <= tempMid)
			tempArray[index++] = m_array[low++];
		while (mid <= upper)
			tempArray[index++] = m_array[mid++];
		for (int i = 0; i < upper - tempLow + 1; i++)
			m_array[tempLow + i] = tempArray[i];
	}

public:
	UnorderedArray(int size, int growBy = 1) : m_array(0), m_maxSize(0), m_growSize(0), m_numElements(0)
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
		if (m_array != 0)
		{
			delete[] m_array;
			m_array = 0;
		}
	}

	void push(T val)
	{
		assert(m_array != 0);
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
		assert(m_array != 0);
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
		assert(m_array != 0 && index <= m_numElements);
		return m_array[index];
	}

	// Linear Search
	int search(T val)
	{
		assert(m_array != 0);
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
				return i;
		}
		return -1;
	}

	// Sorting
	void BubbleSort()
	{
		assert(m_array != 0);
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

	void SelectionSort()
	{
		assert(m_array != 0);
		T temp;
		int min = 0;
		for (int k = 0; k < m_numElements - 1; k++)
		{
			min = k;
			for (int i = k + 1; i < m_numElements; i++)
				if (m_array[i] < m_array[min])
					min = i;
			if (m_array[k] > m_array[min])
			{
				temp = m_array[k];
				m_array[k] = m_array[min];
				m_array[min] = temp;
			}
		}
	}

	void InsertionSort()
	{
		assert(m_array != 0);
		T temp;
		int i = 0;
		for (int k = 1; k < m_numElements; k++)
		{
			temp = m_array[k];
			i = k;
			while (i > 0 && m_array[i - 1] >= temp)
			{
				m_array[i] = m_array[i - 1];
				i--;
			}
			m_array[i] = temp;
		}
	}

	void MergeSort()
	{
		assert(m_array != 0);
		T *tempArray = new T[m_numElements];
		assert(tempArray != 0);
		MergeSort(tempArray, 0, m_numElements - 1);
		delete[] tempArray;
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

#endif