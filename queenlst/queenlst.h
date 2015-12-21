#ifndef H_QUEUELST
#define H_QUEUELST

#include <iostream>
#include <cassert>
#include <initializer_list>
#include <memory>
#include <cstddef>

template<class T>
class QueueLst
{
public:
	QueueLst() = default;
	QueueLst(std::initializer_list<T> rhs);
	QueueLst(const QueueLst<T>& rhs);
	~QueueLst();
	QueueLst& operator=(const QueueLst<T>& rhs);
	void push(const T rhs);
	bool isEmpty() const { return head_ == nullptr; };
	void pop();
	T getFirst();
	std::ostream& print(std::ostream& ostrim) const;
private:
	struct Element
	{
		T data_{ T{} };
		Element* next_{ nullptr };
	};

	Element* head_{ nullptr };
	Element* tail_{ nullptr };

	void copy(const QueueLst<T>& rhs );
	void clear();
};

template <class T>
QueueLst<T>::QueueLst(std::initializer_list<T> rhs)
{
	T* data_{ new T[rhs.size()] };
	std::uninitialized_copy(rhs.begin(), rhs.end(), data_);
	for (size_t i = 0; i < rhs.size(); i++)
	{
		push(data_[i]);
	}
}

template <class T>
QueueLst<T>::QueueLst(const QueueLst<T>& rhs)
{
	copy(rhs);
}

template <class T>
QueueLst<T>::~QueueLst()
{
	clear();
}

template <class T>
QueueLst<T>& QueueLst<T>::operator=(const QueueLst<T>& rhs)
{
	if (this != &rhs)
	{
		copy(rhs);
	}
	return *this;
}

template <class T>
void QueueLst<T>::push(const T rhs)
{
	Element* temp{ new Element };
	temp->data_ = rhs;
	if (tail_ != nullptr)
	{
		tail_->next_ = temp;
	}
	tail_ = temp;
	if (isEmpty())
	{
		head_ = temp;
	}
}

template <class T>
void QueueLst<T>::pop()
{
	if (!isEmpty())
	{
		Element *temp{ head_->next_ };
		delete head_;
		head_ = temp;
	}
}

template <class T>
T QueueLst<T>::getFirst()
{
	if (isEmpty())
	{
		assert("StackLst is Empty");
	}
	return head_->data_;
}

template <class T>
std::ostream& QueueLst<T>::print(std::ostream& ostrim) const
{
	Element *temp = head_;
	ostrim << "QueueLst(";
	if (temp == nullptr)
	{
		ostrim << "null)";
		return ostrim;
	}
	ostrim << temp->data_;
	temp = temp->next_;
	while (temp != nullptr)
	{
		ostrim << ", " << temp->data_;
		temp = temp->next_;
	}
	ostrim << ")";
	return ostrim;
}

template <class T>
void QueueLst<T>::copy(const QueueLst<T>& rhs)
{
	clear();
	if (!rhs.isEmpty())
	{
		push(rhs.head_->data_);
		Element* last{ head_ };
		Element* tempRhs{ rhs.head_->next_ };
		while (tempRhs != nullptr)
		{
			//push back
			Element* temp{ new Element };
			temp->data_ = tempRhs->data_;
			temp->next_ = last->next_;
			last->next_ = temp;
			last = temp;
			tempRhs = tempRhs->next_;
		}
	}
}

template <class T>
void QueueLst<T>::clear()
{
	while (!isEmpty())
	{
		pop();
	}
	tail_ = nullptr;
}

template<typename T>
std::ostream& operator<<(std::ostream& ostrim, const QueueLst<T>& z)
{
	return z.print(ostrim);
}

#endif
