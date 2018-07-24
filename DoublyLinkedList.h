#ifndef DLLIST
#define DLLIST

#include <iostream>

template <typename T>
class DoublyLinkedList
{
    struct Node
    {
        T m_item;
        Node* prev;
        Node* next;
        
        Node ( T item) 
        {
            m_item = item;
            prev = next = nullptr;
        }
    };
    
    Node* m_head;
    
public:

    DoublyLinkedList();
    virtual ~DoublyLinkedList();
    
    virtual void insert_head (const T& element);
    virtual void insert_tail (const T& element);
    
    virtual void delete_head ();
    virtual void delete_tail ();
    
    virtual int get_size ();
    virtual void showList () const;
    
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    m_head = nullptr;
    
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() 
{
  m_head = nullptr;
  std::cout << "Destructor is invoked!" << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::insert_head (const T&  element)
{
    Node* tmp = new Node (element);
    tmp->next = m_head;
    tmp->prev = nullptr;
    if (m_head != nullptr) {
       m_head->prev = tmp;
    }
    m_head = tmp;
}

template <typename T>
void DoublyLinkedList<T>::insert_tail (const T& element)
{
    Node* tmp = new Node (element);
    Node* cur = m_head;
    if( m_head != nullptr ) {
      while(cur->next) {
		cur = cur->next;
	  }
	  cur->next = tmp;
      tmp->prev = cur;
      tmp->next = nullptr;
    } 
    else insert_head(element);
}

template <typename T>
void DoublyLinkedList<T>::delete_head ()
{
    if (m_head != nullptr) {
        Node* tmp = m_head;
        m_head = m_head->next;
        delete tmp;
        m_head->prev = nullptr;
    }
    else {
        std::cout << "List is empty" <<std::endl;
        return;
    }
}

template <typename T>
void DoublyLinkedList<T>::delete_tail () 
{
        if (m_head != nullptr) {
           Node* cur = m_head;
           while(cur->next) {
			  cur = cur->next;
	       } 
           cur->prev->next = nullptr;
           delete cur;
        }
        else {
            std::cout << "List is empty" <<std::endl;
            return;
        }
}


template <typename T>
int DoublyLinkedList<T>::get_size() {
  Node* cur = m_head;
  if (m_head == nullptr) {
    std::cout << "List is empty!" <<std::endl;
    return -1;
  }
  int count = 0;
  for(int ix = 0; cur != nullptr; ++ix) {
    count++;
    cur = cur->next;
  }
  return count;
}

template <typename T>
void DoublyLinkedList<T>::showList() const {
	Node* cur = m_head;
	for(int ix = 1; cur != nullptr; ++ix) {
		std::cout << ix  <<" : " << cur->m_item << std::endl;
		cur = cur->next;
	}	
}

#endif
