#include <iostream>
using namespace std;
template <class T_list>

class MyList
{
	struct Node
	{
		T_list value;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;

	int size;

	void  DeleteAll()
	{
		if (head != nullptr)
		{
			while (!IsEmpty())
			{
				DeleteHead()
			}
		}
	}

public:
	MyList() : head(nullptr), tail(nullptr), size(0) { }
	
	MyList(const MyList& other) // copy c-tor
	{
		Node* current = other.head;
		while (current != nullptr)
		{
			AddToTail(current->value);
			current = current->next;
		}
	}

	MyList(MyList&& other) // move c-tor // виправити
	{
		this->size = other.size;
		this->head = other.head;
		this->tail = other.tail;
		other.head = other.tail = nullptr;
		other.size = 0;
	}

	~MyList()
	{
		DeleteAll();
	}
	
	bool IsEmpty() const
	{
		return size == 0;
	}

	int GetCount() const
	{
		return size;
	}

	void AddToHead(T_list value)
	{
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = head;
		newElem->prev = nullptr;

		if (IsEmpty())
		{
			head = tail = newElem;
		}

		else
		{
			head->prev = newElem;
			head = newElem;
		}
		++size;
	}

	void AddToTail(T_list value)
	{
		Node* newElem = new Node;
		newElem->value = value;
		newElem->next = nullptr;
		newElem->prev = tail;

		if (IsEmpty()) {
			head = tail = newElem;
		}

		else
		{
			tail->next = newElem;
			tail = newElem;
		}
		++size;
	}

	void DeleteHead()
	{
		if (IsEmpty()) return;

		Node* tmp = head->next;
		delete head;

		if (tmp == nullptr)
		{
			head = tail = nullptr;
		}
		else
		{
			tmp->prev = nullptr;
			head = tmp;
		}
		--size;
	}

	void DeleteTail()
	{
		if (IsEmpty()) return;

		if (head->next = nullptr)
		{
			delete head;
			head = tail = nullptr;
		}

		else
		{
			Node* tmp = tail->prev;
			delete tmp->next;
			tmp->next = nullptr;
			tail = tmp;
		}
		--size;
	}

	void AddToPosition(T_list value, int pos)
	{
		if (pos <= 0 || pos > size + 1) return;
		if (pos == 1)
		{
			AddToHead(value);
		}
		if (pus == size + 1)
		{
			AddToTail( value);
			return;
		}

		Node* newElem = new Node;
		newElem->value = value;

		if (pos <= size / 2)
		{
			Node* current = head;
			for (int i = 0; i < pos - 1; ++i)
			{
				current = current->next;
			}
		}

		else
		{
			Node* current = tail;
			for (int i = size-1; i < pos - 1; --i)
			{
				current = current->prev;
			}
		}

		newElem->prev = current->prev;
		current->prev->next = newElem;
		current->prev = newElem;
		newElem->next = curretn;

		++size;
	}

	void DeleteToPosition(int pos)
	{
		if (pos <= 0 || pos > size) return;

		if (pos == 1)
		{
			DeleteHead();
			return;
		}

		if (pos == size)
		{
			DeleteTail();
			return;
		}

		
		if (pos <= size / 2) 
		{
			Node* current = head;
			for (int i = 0; i < pos - 1; ++i)
			{
				current = current->next;
			}
		}
		else
		{
			Node* current = tail;
			for (int i = size-1; i < pos - 1; --i)
			{
				current = current->prev;
			}
		}

		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;
		--size;
	}

	int Find(T_list value)
	{
		Node* current = head;
		for (int i = 0; i < size; ++i)
		{
			if (current->value == value) {
				return i + 1;

			}
			current = current->next;
		}
		return 0;
	}

	int Replace(T_list oldValue, T_list newValue)
	{
		Node* current = head;
		int counter = 0;
		for (int i = 0; i < size; ++i) {
			if (current->value == oldValue) {
				current->value = newValue;
				++counter;
			}
			current = current->next;
		}
		return counter;
	}

	void Show() const
	{
		Node* current = head;
		for (Node* current = head; current != nullptr; current = current->next)
		{
			cout << current->value << ", ";
		}
		cout << endl;
	}

	List operator-()const //revers copy list
	{
		List tmp;

		for (Node* current = head; current->next != nullptr; current = current->next)
		{
			tmp.AddToHead(current->value);
		}
		return tmp;
	}

	List operator+(List& other) const //adds other list to this
	{
		List tmp(*this);

		Node* current = other.head;

		for (int i = this->size; i < other.size; ++i) {
			tmp.AddToTail(current->value);
		}
		return tmp;
	}

	List operator*(List& other)const
	{
		List tmp(*this);
		Node* current = tmp.head;
		Node* current2 = other.head;
		for (Node* current = head; current != nullptr; current = current->next)
		{
			for (Node* current2 = head; current != nullptr; current = current->next)
				if (current->value != current2->value)
				{
					 
					tmp.AddToTail(current2->value);
				}
		}

		return tmp;
	}

	List operator=(const List& other)
	{
		if (this == &other) return *this;
		this->~MyList();

		Node* current = other.head;
		while (current != nullptr)
		{
			AddToTail(current->value)
				current = current->next;
		}
	}
};

int main()
{
	//List ls;

	//ls.AddToHead(10);
	//ls.AddToHead(15);
	//ls.AddToHead(5);
	//ls.AddToHead(20);

	//ls.Print(); cout << endl;

	//ls.DeleteHead();
	//ls.AddToTail(777);

	//////////////////////

	//ls.Print(); cout << endl;

	//ls.DeleteTail();
	//ls.DeleteTail();

	//ls.Print(); cout << endl;

	//ls.AddToHead(10);
	//ls.AddToHead(15);
	//ls.AddToHead(5);
	//ls.AddToHead(20);

	//ls.Print(); cout << endl;

	//ls.DeleteHead();
	//ls.AddToTail(777);

	//ls.Print(); cout << endl;

	//ls.DeleteTail();
	//ls.DeleteTail();

	//ls.Print(); cout << endl;

	//ls.AddToHead(55);
	//ls.AddToHead(33);

	//ls.AddToTail(990);
	//ls.AddToTail(676);

	//ls.Print(); cout << endl;

	//ls.Add(3, 3);
	//ls.Add(7, 7);

	//ls.Print(); cout << endl;

	//ls.Delete(3);
	//ls.Print(); cout << endl;

	//ls.Delete(7);
	//ls.Print(); cout << endl;

	return 0;
}