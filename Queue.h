#ifndef QUEUE
#define QUEUE

#include "List.h"

template <typename T>
class Queue : private DoublyList<T> 
{
public:
		Queue();

		virtual void enqueue(T value);
		virtual void dequeue();
		virtual void showQueue();

};

template <typename T>
Queue<T>::Queue() : DoublyList<T>() {  }

template <typename T>
void Queue<T>::enqueue(T value) 
{
		DoublyList<T>::insertTail(value);
}

template <typename T>
void Queue<T>::dequeue() 
{
		DoublyList<T>::removeHead();
}

template <typename T>
void Queue<T>::showQueue() 
{
		DoublyList<T>::showList();
}

#endif
