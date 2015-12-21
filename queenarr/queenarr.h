#ifndef H_QUEENARR
#define H_QUEENARR

#include <iostream>
#include <cassert>
#include <memory>
#include <initializer_list>
#include <cstddef>

template<class T>
class QueenArr
{
public:
	QueenArr();
	QueenArr(const ptrdiff_t rhs);
	QueenArr(std::initializer_list<T> rhs);
	QueenArr(const QueenArr<T>& rhs);
	~QueenArr();

	QueenArr & operator= (const QueenArr<T>& rhs);
	void push(const T rhs);
	bool isEmpty() const { return tail_ == head_ && tail_ == 0; };
	void pop();
	T getFirst();
	ptrdiff_t dims(){ return dims_; };
	std::ostream& print(std::ostream& ostrim) const;
private:
	T* data_{ nullptr };
	ptrdiff_t head_{ 0 };
	ptrdiff_t tail_{ 0 };
	ptrdiff_t dims_{ 0 };
};

template <class T>
QueenArr<T>::QueenArr()
	: QueenArr{ ptrdiff_t { 0 } }{}

template <class T>
QueenArr<T>::QueenArr(const ptrdiff_t rhs)
	: data_{ new T[rhs] }, head_{ 0 }, tail_{ 0 }, dims_{ rhs }{}

template <class T>
QueenArr<T>::QueenArr(std::initializer_list<T> rhs)
	: data_{ new T[rhs.size()] }, head_{ 0 }, tail_{ rhs.size() }, dims_{ rhs.size() }
{
	std::uninitialized_copy(rhs.begin(), rhs.end(), data_);
}

template <class T>
QueenArr<T>::QueenArr(const QueenArr<T>& rhs)
	: data_{ new T[rhs.dims_] }, head_{ rhs.head_ }, tail_{ rhs.tail_ }, dims_{ rhs.dims_ }
{
	std::uninitialized_copy(rhs.data_, rhs.data_ + rhs.dims_, data_);
}

template <class T>
QueenArr<T>::~QueenArr()
{
	delete[] data_;
	data_ = nullptr;
}

template <class T>
QueenArr<T>& QueenArr<T>::operator=(const QueenArr<T>& rhs)
{
	if (this != &rhs)
	{
		this->data_ = rhs.data_;
		this->head_ = rhs.head_;
		this->dims_ = rhs.dims_;
		this->tail_ = rhs.tail_;
	}
	return *this;
}

template <class T>
void QueenArr<T>::push(const T rhs)
{
	if (!isEmpty())
	{
		if (dims_ == tail_ && head_ == 0)
		{
			T* newData_{ new T[dims_ * 2] };
			std::uninitialized_copy(data_, data_ + dims_, newData_);
			delete[] data_;
			data_ = newData_;
			dims_ *= 2;
		}
		else if (dims_ == tail_ && head_ > 0)
		{
			tail_ = 0;
		}
		else if (head_ == tail_)
		{
			T* newData_{ new T[dims_ * 2] };
			std::uninitialized_copy(data_ + head_, data_ + dims_, newData_);//������
			std::uninitialized_copy(data_, data_ + tail_, newData_ + dims_ - head_);//�����
			delete[] data_;
			data_ = newData_;
			tail_ = dims_ - head_ + tail_;
			head_ = 0;
			dims_ *= 2;
		}
	}
	data_[tail_] = rhs;
	tail_++;
}

template <class T>
void QueenArr<T>::pop()
{
	if (!isEmpty())
	{
		head_++;
	}
}

template <class T>
T QueenArr<T>::getFirst()
{
	if (isEmpty())
	{
		throw ("Queue is empty");
	}
	return data_[head_];
}

template <class T>
std::ostream& QueenArr<T>::print(std::ostream& ostrim) const
{
	ostrim << "QueenArr(";
	
	if (isEmpty())
	{
		ostrim << "null)";
		return ostrim;
	}

	ostrim << data_[head_];
	for (ptrdiff_t i = head_ + 1; i < tail_; i++)
	{
		ostrim << ", " << data_[i];
	}

	if (tail_ <= head_)
	{
		for (ptrdiff_t i = 0; i < tail_; i++)
		{
			ostrim << ", " << data_[i];
		}
	}
	ostrim << ")";
	return ostrim;
}

template<typename T>
std::ostream& operator<< (std::ostream& ostrim, const QueenArr<T>& z)
{
	return z.print(ostrim);
}
#endif
