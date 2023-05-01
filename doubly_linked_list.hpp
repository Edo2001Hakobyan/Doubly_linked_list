#include <iostream> 
#include <cassert>

template <typename T>
class Node
{
	public:
		T data;
		Node<T> *next;
		Node<T> *prev;

		//constructor
		Node(T data)
		{
			this->data = data;
			prev = nullptr;
			next = nullptr;
		}

};

template <typename T>
class Doubly_linked_list
{	
	private:
		Node<T> *m_head;
		Node<T> *m_tail;
		int m_size;

	public:
	
		//constructor
		Doubly_linked_list()
		{
			m_head = nullptr;
			m_tail = nullptr;
			m_size = 0;
		}

		//destructor
		~Doubly_linked_list()
		{
			Node<T> *current = m_head;
			Node<T> *next;
			while(current != nullptr)
			{
				next = current->next;
				delete current;
				current = next;
			}
		}

                //Function that return list size 
		T get_size()
		{
			return m_size;
		}
                
	        // adds a new node with the given data to the front of the list	
		void push_front(T data)
		{
			Node<T> *node = new Node<T>(data);
			if(m_head == nullptr)
			{
				m_head = node;
				m_tail = node;
			}
			else
			{
				node->next = m_head;
				m_head->prev = node;
				m_head = node;
			}
			m_size++;
		}
                
		//adds a new node with the given value to the back of the list
		void push_back(T data)
		{
			Node<T> *node = new Node<T>(data);
			if(m_tail == nullptr)
			{
				m_head = node;
				m_tail = node;
			}
			else
			{
				node->prev = m_tail;
				m_tail->next = node;
				m_tail =  node;
			}
			m_size++;
		}
                
		//returns the value stored in the first node of the list
		T front()
		{
			assert(m_head != nullptr);
			return m_head->data;
		}
		
		//returns the value stored in the last node of the list
		T back()
		{
			assert(m_tail != nullptr);
			return m_tail->data;
		}
                
		//print list elements
		void print()
		{
			Node<T> *current = m_head;
			while(current != nullptr)
			{
				std::cout<<current->data<<" ";
				current = current->next;
			}
			std::cout<<std::endl;
		}
                
		//Removes the first node of the list
		void pop_front()
		{
			assert(m_head != nullptr);
			Node<T>* temp = m_head;
			m_head = m_head->next;
			if(m_head != nullptr)
			{
				m_head->prev = nullptr;
			}
			else
			{
				m_tail = nullptr;
			}
			delete temp;
			m_size--;
		}

		//Removes the last node of the list
		void pop_back()
		{	
			assert(m_head != nullptr);
			Node<T>* temp = m_tail;
			m_tail = m_tail->prev;
			if(m_tail != nullptr)
			{
				m_tail->next = nullptr;
			}
			else
			{
				m_head = nullptr;
			}
			delete temp;
			m_size--;
		}

		//inserts a new node with the given value at the specified index
		void insert(int index,T val)
		{
			assert(index >= 0 && index <= m_size);
			Node<T>* node = new Node<T>(val);
			if (index == 0)
			{
				push_front(val);
			}
			else if (index == m_size)
			{
				push_back(val);
			}
			else
			{
				Node<T>* current = m_head;
				for(int i=0; i < index; i++)
				{
					current = current->next;
				}
				node->next = current;
                                node->prev = current->prev;
				current->prev->next = node;
				current->prev = node;
				m_size++;
			}
		}	

		//Returns a reference to the value stored in the node at the specified index
		T& operator[](int index)
		{
			assert(index >= 0 && index < m_size);
			Node<T>* current = m_head;
			for(int i=0; i < index; i++)
			{
				current = current->next;
			}
			return current->data;
		}
                
		//Reverses the order of the nodes in the list
		void reverse()
		{
			Node<T>* current = m_head;
			Node<T>* temp = nullptr;
			while(current != nullptr)
			{
				temp = current->prev;
				current->prev = current->next;
				current->next = temp;
				current = current->prev;
			}

			temp = m_head;
			m_head = m_tail;
			m_tail = temp;
      		}

                //Function that do bubble sort
		void bubble_sort()
		{
			if(m_head == nullptr)
			{
				return;
			}

			Node<T>* i, *j;
			bool swapped;
			for( i = m_head; i->next != nullptr; i = i->next)
			{
				swapped = false;
				for(j = m_head; j->next != nullptr; j = j->next)
				{
					if(j->data > j->next->data)
					{
						T temp = j->data;
						j->data = j->next->data;
						j->next->data = temp;
						swapped = true;
					}
				}
				if(!swapped)
				{
					break;
				}
			}
		}

		void insertion_sort()
		{
			//empty or one-element list is already sorted
			if(!m_head || !m_head->next)
			{
				return;
			}
			Node<T>* i = m_head->next;
			while(i)
			{
				Node<T>* key = i;
				i = i->next;
				//remove key from the list
				key->prev->next = key->next;
				if(key->next)
				{
					key->next->prev = key->prev;
				}
				//insert key into the sorted part of the list
				Node<T>* j = key->prev;
				while(j && j->data > key->data)
				{
					j = j->prev;
				}

				//key should be inserted at the beginning
				if(!j)
				{
					key->next = m_head;
					m_head->prev = key;
					m_head = key;
				}
				//key should be inserted after
				else
				{
					key->next = j->next;
					if(j->next)
					{
						j->next->prev = key;
					}
					j->next = key;
					key->prev = j;
				}	
			}
		}
		
};
