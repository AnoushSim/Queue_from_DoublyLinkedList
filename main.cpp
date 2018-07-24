#include <iostream>
#include <Queue.h>

int main() {
		Queue<int> queue;
		queue.enqueue(1);
		queue.enqueue(2);
		queue.enqueue(3);
		queue.enqueue(4);
		queue.dequeue();
		queue.enqueue(5);
		queue.dequeue();
		queue.show();
}
