#pragma once

template <class T>
struct List
{
private:
	T data;
	List* next;
public:

	void init(List*& head, T elem);
	bool isEmpty(List* head);

	void addToHead(List*& head, T elem);
	void addAfterNode(List*& pNode, T elem);
	void addToTail(List*& head, T elem);

	void deleteHead(List*& head);
	void deleteAfterNode(List*& pNode);
	void deleteTail(List*& head);

	bool isElemInList(List* head, T elem);
	List* FindPlaceInList(List* head, T elem);

	void clearList(List*& head);

	void print(List* head);

	void GroupAddIterative(List*& head, int i, int j, T arr[]);
	void GroupDeleteIterative(List*& head, int i, int j);
	void GroupChageIterative(List*& head, int i, int j, T arr[]);
	bool FindGroupElementIterative(List*& head, T arr[], int n);
};

template<class T>
void inline List<T>::init(List*& head, T elem)
{
	*head = new List;
	head->next = nullptr;
	head->data = elem;
}

template<class T>
inline bool List<T>::isEmpty(List* head)
{
	return head == nullptr;
}



template<class T>
inline void List<T>::addToHead(List*& head, T elem)
{
	List* p = new List;
	p->data = elem;
	p->next = head;
	head = p;
}

template<class T>
inline void List<T>::addAfterNode(List*& pNode, T elem)
{
	List* p = new List;
	p->data = elem;
	p->next = pNode->next;
	pNode->next = p;
}

template<class T>
inline void List<T>::addToTail(List*& head, T elem)
{
	List* p = head;
	if (isEmpty(head))
	{
		addToHead(head, elem);
	}
	else
	{
		while (p->next != nullptr)
		{
			p = p->next;
		}
		addAfterNode(p, elem);
	}
}



template<class T>
inline void List<T>::deleteHead(List*& head)
{
	if (isEmpty(head))
	{
		std::cout << "!" << '\n';
	}
	else
	{
		List* p = head;
		head = head->next;
		p->next = nullptr;
		delete p;
		p = nullptr;
	}
}

template<class T>
inline void List<T>::deleteAfterNode(List*& pNode)
{
	if (isEmpty(pNode))
	{
		std::cout << "!" << '\n';
	}
	else
	{
		List* p = pNode->next;
		if (p != nullptr)
		{
			pNode->next = p->next;
			p->next = nullptr;
			delete p;
			p = nullptr;
		}
	}
}

template<class T>
inline void List<T>::deleteTail(List*& head)
{
	if (isEmpty(head))
	{
		std::cout << "!" << '\n';
	}
	else
	{
		List* p = head;
		while (p->next->next != nullptr)
			p = p->next;
		deleteAfterNode(p);
	}
}



template<class T>
inline bool List<T>::isElemInList(List* head, T elem)
{
	bool find = false;

	while ((head != nullptr) && (!find))
	{
		if (head->data == elem) find = true;
		else head = head->next;
	}
	return find;
}

template<class T>
inline List<T>* List<T>::FindPlaceInList(List* head, T elem)
{
	List* p = head;
	while ((p->next != nullptr) && (p->data != elem))
	{
		p = p->next;
	}
	return p;
}

template<class T>
inline void List<T>::clearList(List*& head)
{
	if (isEmpty(head))
	{
		std::cout << "!" << '\n';
	}
	else
	{
		while (!isEmpty(head->next))
			deleteAfterNode(head);
		delete head;
		head = nullptr;
	}
}



template<class T>
inline void List<T>::print(List* head)
{
	if (isEmpty(head))
	{
		std::cout << "!" << '\n';
	}
	else
	{
		List* p = head;
		while (p != nullptr)
		{
			std::cout << p->data << ' ';
			p = p->next;
		}
		std::cout << '\n';
	}
}

template<class T>
inline void List<T>::GroupAddIterative(List*& head, int i, int j, T arr[])
{
	List* p = head;
	int tmp = 0, tm1=0;

	while (p != nullptr && tmp != j)
	{
		if (tmp + 1 >= i)
		{
			addAfterNode(p, arr[tm1++]);
		}
		tmp++;
		p = p->next;
	}
}

template<class T>
inline void List<T>::GroupDeleteIterative(List*& head, int i, int j)
{
	List* p = head;
	int tmp = 1;
	while (p != nullptr && tmp != j+i-2)
	{
		if (tmp+1 >= i)
		{
			deleteAfterNode(p);
		}
		else
		{
			p = p->next;
		}
		tmp++;
	}
}

template<class T>
inline void List<T>::GroupChageIterative(List*& head, int i, int j, T arr[])
{
	List* p = head;
	int tmp = 0, tm1 = 0;

	while (p != nullptr && tmp != j)
	{
		if (tmp + 1 >= i)
		{
			p->data = arr[tm1++];
		}
		tmp++;
		p = p->next;
	}
}

template<class T>
inline bool List<T>::FindGroupElementIterative(List*& head, T arr[], int n)
{
	List* p = head;
	bool find = false;
	bool answer = false;
	int tmp = 0;
	while (p != nullptr && !answer)
	{
		if (p->data == arr[tmp])
		{
			tmp++;
			find = true;
			if (arr[tmp] == arr[n] && tmp == n)
				answer = true;
		}
		else
		{
			find = false;
		}
		p = p->next;
	}
	std::cout << tmp << '\n';
	if (find && n == tmp)
		return true;
	else
		return false;
}

