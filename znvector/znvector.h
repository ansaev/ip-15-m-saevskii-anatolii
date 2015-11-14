//
// Created by ansaev on 26.10.15.
//

#ifndef ZNVECTOR_ZNVECTOR_H
#define ZNVECTOR_ZNVECTOR_H
#include <iostream>
#include <sstream>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <memory>
using namespace std;

template<class T>
class znVector
{
public:
    znVector() = default;
    znVector(const ptrdiff_t dims);
    znVector(initializer_list<T> vals);
    znVector(const znVector<T>& vec);
    ~znVector();

    znVector<T>& operator=(const znVector<T>& arr);
    T& operator[] (const ptrdiff_t i);
    const double& operator[] (const ptrdiff_t i) const;
    znVector<T> operator-();
    znVector<T>& operator+=(const znVector<T>& rhs);
    znVector<T>& operator-=(const znVector<T>& rhs);
    znVector & operator*= (const int32_t rhs);
    znVector & operator/= (const int32_t rhs);
    bool operator== (const znVector & rhs) const;
    bool operator!= (const znVector & rhs) const { return !operator== (rhs); }

    ostream& print(ostream& ostrim) const;
private:
    //IndexType
    ptrdiff_t dims_{ 0 };
    //ValueType
    T* data_{ nullptr };

    void resizeRange(const ptrdiff_t rhs);
    void checkOutOfRange(const ptrdiff_t i) const;
};

template<typename T>
znVector<T>::znVector(const ptrdiff_t dims)
        : dims_{ dims }
{
    data_ = new T[dims_];
}

template<typename T>
znVector<T>::znVector(initializer_list<T> vals)
        : dims_{ static_cast<ptrdiff_t>(vals.size()) }
        , data_{ new T[dims_] }
{

    uninitialized_copy(vals.begin(), vals.end(), data_);
}

template<typename T>
znVector<T>::znVector(const znVector<T>& vec)
        : dims_{ vec.dims_ }
        , data_{ new T[dims_] }
{
    uninitialized_copy(vec.data_, vec.data_ + vec.dims_, data_);
}

template<typename T>
znVector<T>::~znVector()
{
    delete[] data_;
    data_ = nullptr;
}

template<typename T>
znVector<T>& znVector<T>::operator=(const znVector<T>& arr)
{
    if (this != &arr)
    {
        this->dims_ = arr.dims_;
        this->data_ = arr.data_;
    }
    return *this;
}

template<typename T>
T& znVector<T>::operator[] (const ptrdiff_t i)
{
    checkOutOfRange(i);
    return data_[i];
}

template<typename T>
const double& znVector<T>::operator[] (const ptrdiff_t i) const
{
    checkOutOfRange(i);
    return data_[i];
}

template<typename T>
znVector<T> znVector<T>::operator-()
{
    znVector<T> res(dims_);
    for (ptrdiff_t i = 0; i < dims_; i++)
    {
        res.data_[i] = -data_[i];
    }
    return res;
}

template<typename T>
znVector<T>& znVector<T>::operator+=(const znVector<T>& rhs)
{
    if (dims_ < rhs.dims_)
    {
        resizeRange(rhs.dims_);
    }
    for (ptrdiff_t i = 0; i < rhs.dims_; i++)
    {
        data_[i] += rhs.data_[i];
    }
    return *this;
}

template<typename T>
znVector<T>& znVector<T>::operator-=(const znVector<T>& rhs)
{
    if (dims_ < rhs.dims_)
    {
        resizeRange(rhs.dims_);
    }
    for (ptrdiff_t i = 0; i < rhs.dims_; i++)
    {
        data_[i] -= rhs.data_[i];
    }
    return *this;
}

template<typename T>
znVector<T>& znVector<T>::operator*= (const int32_t rhs)
{
    for (ptrdiff_t i = 0; i < dims_; i++)
    {
        data_[i] *= rhs;
    }
    return *this;
}

template<typename T>
znVector<T>& znVector<T>::operator/= (const int32_t rhs)
{
    for (ptrdiff_t i = 0; i < dims_; i++)
    {
        data_[i] /= rhs;
    }
    return *this;
}

template<typename T>
bool znVector<T>::operator== (const znVector & rhs) const
{
    if (dims_ != rhs.dims_)
    {
        return false;
    }
    for (ptrdiff_t i = 0; i < dims_; i++)
    {
        if (!(data_[i] == rhs.data_[i]))
        {
            return false;
        }
    }
    return true;
}

template<typename T>
ostream& znVector<T>::print(ostream& ostrim) const
{
    ostrim << "znVector(" << data_[0];
    if (dims_ > 0)
    {
        for (ptrdiff_t i = 1; i < dims_; i++)
        {
            ostrim << ", " << data_[i];
        }
    }
    ostrim << ")";
    return ostrim;
}

template<typename T>
void znVector<T>::resizeRange(const ptrdiff_t rhs)
{
    if (dims_ < rhs)
    {
        T* newData_{ new double[rhs] };
        for (ptrdiff_t i = 0; i < rhs; i++)
        {
            newData_[i] = data_[i];
        }
        delete[] data_;
        data_ = newData_;
        dims_ = rhs;
    }
}

template<typename T>
void znVector<T>::checkOutOfRange(const ptrdiff_t i) const
{
    if (!((i <= dims_) && (i >= 0)))
    {
        throw "Out of range";
    }
}

template<typename T>
ostream& operator<< (ostream& ostrim, const znVector<T>& z)
{
    return z.print(ostrim);
}

template<typename T>
znVector<T> operator+ (const znVector<T>& lhs, const znVector<T>& rhs)
{
    return znVector<T>(lhs) += znVector<T>(rhs);
}

template<typename T>
znVector<T> operator- (const znVector<T>& lhs, const znVector<T>& rhs)
{
    return znVector<T>(lhs) -= znVector<T>(rhs);
}

template<typename T>
znVector<T> operator* (const znVector<T>& lhs, const int32_t rhs)
{
    return znVector<T>(lhs) *= rhs;
}

template<typename T>
znVector<T> operator/ (const znVector<T>& lhs, const int32_t rhs)
{
    return znVector<T>(lhs) /= rhs;
}
#endif //ZNVECTOR_ZNVECTOR_H
