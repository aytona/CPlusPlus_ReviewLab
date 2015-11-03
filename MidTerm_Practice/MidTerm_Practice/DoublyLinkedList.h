#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

template<typename T> class DoublyLinkIterator;
template<typename T> class DoublyLinkList;

template<typename T>
class DoublyLinkNode
{
	friend class DoublyLinkIterator < T >;
	friend class DoublyLinkList < T >;

private:
	DoublyLinkNode() : m_next(0), m_previous(0) {}
	T m_data;
	DoublyLinkNode *m_next;
	DoublyLinkNode *m_previous;
};

template<typename T>
class DoublyLinkIterator
{
private:
	DoublyLinkNode<T> *m_node;

public:
	DoublyLinkIterator()
	{
		m_node = 0;
	}
	~DoublyLinkIterator() {}

	void operator= (DoublyLinkNode<T> *node)
	{
		m_node = node;
	}

	T &operator*()
	{
		assert(m_node != 0);
		return m_node->m_data;
	}

	void operator++()
	{
		assert(m_node != 0);
		m_node = m_node->m_next;
	}

	void operator++(int)
	{
		assert(m_node != 0);
		m_node = m_node->m_next;
	}

	void operator--()
	{
		assert(m_node != 0);
		m_node = m_node->m_previous;
	}

	void operator--(int)
	{
		assert(m_node != 0);
		m_node = m_node->m_previous;
	}

	bool operator!= (DoublyLinkNode<T> *node)
	{
		return (m_node != node);
	}

	bool operator== (DoublyLinkNode<T> *node)
	{
		return (m_node == node);
	}
};

template<typename T>
class DoublyLinkList
{
private:
	int m_size;
	DoublyLinkNode<T> *m_root;
	DoublyLinkNode<T> *m_lastNode;

public:
	DoublyLinkList() : m_size(0), m_root(0), m_lastNode(0)
	{

	}
	~DoublyLinkList()
	{
		while (m_root != 0)
			Pop();
	}

	DoublyLinkNode<T> *Begin()
	{
		assert(m_root != 0);
		return m_root;
	}

	DoublyLinkNode<T> *End()
	{
		return 0;
	}

	void PushFront(T newData)
	{
		DoublyLinkNode<T> *node = new DoublyLinkNode < T > ;
		assert(node != 0);
		node->m_data = newData;
		node->m_next = 0;
		node->m_previous = 0;
		if (m_root != 0)
		{
			node->m_next = m_root;
			m_root->m_previous = node;
			m_root = node;
		}
		else
		{
			m_root = node;
			m_lastNode = node;
		}
		m_size++;
	}

	void PopFront(T newData)
	{
		DoublyLinkNode<T> *node = new DoublyLinkNode < T > ;
		assert(node != 0);
		node->m_data = newData;
		node->m_next = 0;
		node->m_previous = 0;
		if (m_lastNode != 0)
		{
			m_lastNode->m_next = node;
			node->m_previous = m_lastNode;
		}
		else
			m_root = node;
		m_lastNode = node;
		m_size++;
	}

	void Push(T newData)
	{
		DoublyLinkNode<T> *node = new DoublyLinkNode < T >;
		assert(node != 0);
		node->m_data = newData;
		node->m_next = 0;
		node->m_previous = 0;
		if (m_lastNode != 0)
		{
			m_lastNode->m_next = node;
			node->m_previous = m_lastNode;
		}
		else
			m_root = node;
		m_lastNode = node;
		m_size++;
	}

	void Pop()
	{
		assert(m_root != 0);
		if (m_root->m_next == 0)
		{
			delete m_root;
			m_root = 0;
		}
		else
		{
			DoublyLinkNode<T> *prevNode = m_lastNode->m_previous;
			prevNode->m_next = 0;
			delete m_lastNode;
			m_lastNode = prevNode;
		}
		m_size = (m_size == 0 ? m_size : m_size - 1);
	}

	int GetSize()
	{
		return m_size;
	}
};

#endif