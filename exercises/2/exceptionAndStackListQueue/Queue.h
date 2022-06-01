#pragma once

template<typename T>
struct QNode {
	T data;
	QNode* next;
	QNode(T d)
	{
		data = d;
		next = nullptr;
	}
};

template<typename T>
class Queue {
private:
	QNode<T>* front, * rear;
	void destroy();
	void copy(const Queue<T>& other);
public:
	Queue()
	{
		front = rear = nullptr;
	}
	Queue(const Queue<T>& other)
	{
		copy(other);
	}
	Queue<T>& operator=(const Queue<T>& other)
	{
		if (this != &other)
		{
			destroy();
			copy(other);
		}
		return *this;
	}
	~Queue() {
		destroy();
	}

	void enQueue(T x)
	{
		QNode<T>* temp = new QNode<T>(x);

		if (rear == nullptr) {
			front = rear = temp;
			return;
		}

		rear->next = temp;
		rear = temp;
	}

	void deQueue()
	{
		if (front == nullptr)
			return;

		QNode<T>* temp = front;
		front = front->next;

		if (front == nullptr)
			rear = nullptr;

		delete temp;
	}
};

template<typename T>
inline void Queue<T>::destroy()
{
	while (front)
	{
		QNode<T>* temp = front;
		front = front->next;
		delete temp;
	}
}

template<typename T>
inline void Queue<T>::copy(const Queue& other)
{
	if (other.front == nullptr)
	{
		return;
	}
	front = new Queue<T>(other.front->data);
	rear = front;
	Queue<T>* current = other.front->next;
	while (current)
	{
		enQueue(current->data);
		current = current->next;
	}
}
