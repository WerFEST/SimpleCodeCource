#pragma once
#ifndef _LIST_H_
#define _LIST_H_


template<typename T>
class List
{
public:
	List();
	~List();

	void pop_front();
	void push_back(T data);
	void push_front(T data);
	void clear();
	void insert(T value, int index);
	void removeAt(int index);
	void pop_back();
	int GetSize() { return Size; }
	void PrintList(const List<T>& lst);
	T& operator[] (const int index);

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;
};


template<typename T>
inline List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
inline List<T>::~List()
{
	clear();
}

template<typename T>
inline void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;

	delete temp;
	
	Size--;
}

template<typename T>
inline void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}
	
	Size++;
}

template<typename T>
inline void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);			//Изначально создается объект, куда передаётся текущий head
	Size++;
}

template<typename T>
inline void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
inline void List<T>::insert(T value, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;								//Временная переменная в которую записываем значение предыдущего элемента, после которого вставляем данные

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;								//Полученный адрес следующего элемента в предыдущем помещаем во временную переменную
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);		//Помещаем адрес следующего элемента в новый элемент
		previous->pNext = newNode;									//Помещаем адрес нового элемента в предыдущий элемент

		Size++;
	}
}

template<typename T>
inline void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;				//Временная переменная в которую записываем значение предыдущего элемента, после которого вставляем данные

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;				//Полученный адрес следующего элемента в предыдущем помещаем во временную переменную
		}

		Node<T>* toDelete = previous->pNext;		//Запоминаем адрес того элемента, который собираемся удалить.
		previous->pNext = toDelete->pNext;			//Перемещаем адрес из удаляемого элемента в предыдущий, чтобы предыдущий указывал на следующий

		delete toDelete;
		Size--;
	}
}

template<typename T>
inline void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
inline void List<T>::PrintList(const List<T>& lst)
{
	for (auto it = lst.cbegin(); it != lst.cend(); ++it)
	{
		cout << *it << endl;
	}
}

template<typename T>
inline T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


#endif // !_LIST_H_