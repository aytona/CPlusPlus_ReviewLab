#ifndef _SINGLY_LINKED_LIST_H_
#define _SINGLY_LINKED_LIST_H_

template<typename T> class LinkIterator;
template<typename T> class LinkList;

template<typename T>
class LinkNode
{
	friend class LinkIterator < T > ;
	friend class LinkList < T > ;

private:
	T m_data;
	LinkNode *m_next;
};

template<typename T>
class LinkIterator
{
private:
	LinkNode<T> *m_node;

public:
	LinkIterator()
	{
		m_node = 0;
	}
	~LinkIterator() {}

	void operator= (LinkNode<T> *node)
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

	bool operator!= (LinkNode<T> *node)
	{
		return (m_node != node);
	}

	bool operator== (LinkNode<T> *node)
	{
		return (m_node == node);
	}
};

template<typename T>
class LinkList
{
private:
	int m_size;
	LinkNode<T> *m_root;
	LinkNode<T> *m_lastNode;

public:
	LinkList() : m_size(0), m_root(0), m_lastNode(0)
	{

	}
	~LinkList()
	{
		while (m_root != 0)
			Pop();
	}

	LinkNode<T> *Begin()
	{
		assert(m_root != 0);
		return m_root;
	}

	LinkNode<T> *End()
	{
		return 0;
	}

	void Push(T newData)
	{
		LinkNode<T> *node = new LinkNode < T > ;
		assert(node != 0);
		node->m_data = newData;
		node->m_next = 0;
		if (m_lastNode != 0)
		{
			m_lastNode->m_next = node;
			m_lastNode = node;
		}
		else
		{
			m_root = node;
			m_lastNode = node;
		}
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
			LinkNode<T> *prevNode = m_root;
			while (prevNode->m_next != 0 && prevNode->m_next != m_lastNode)
				prevNode = prevNode->m_next;
			delete m_lastNode;
			prevNode->m_next = 0;
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