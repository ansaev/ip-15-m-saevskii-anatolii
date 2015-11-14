//
// Created by ansaev on 26.10.15.
//
#ifndef NVECTOR_NVECTOR_H
#define NVECTOR_NVECTOR_H

#include <iostream>
#include <cstdint>
#include <initializer_list>
#include <memory>
using namespace std;

template<class T>
class nVector
{
public:
    nVector() = default;
    nVector(const ptrdiff_t dims);
    nVector(initializer_list<T> vals);
    nVector(const nVector<T>& vec);
    ~nVector();
    nVector<T>& operator=(const nVector<T>& arr);
    T& operator[] (const ptrdiff_t i);
    const double& operator[] (const ptrdiff_t i) const;

    nVector<T> operator-();
    nVector<T>& operator+=(const nVector<T>& rhs);
    nVector<T>& operator-=(const nVector<T>& rhs);
    nVector & operator*= (const int32_t rhs);
    nVector & operator/= (const int32_t rhs);
    bool operator== (const nVector & rhs) const;
    bool operator!= (const nVector & rhs) const { return !operator== (rhs); }

    ostream& print(ostream& ostrim) const;
private:
    //IndexType
    ptrdiff_t dims_{ 0 };
    //ValueType
    T* data_{ nullptr };

    void checkSizeRange(const ptrdiff_t lhs, const ptrdiff_t rhs) const;

    void checkOutOfRange(const ptrdiff_t i) const;
};

template<typename T>
nVector<T>::nVector(const ptrdiff_t dims)
        : dims_{ dims }
{
    data_ = new T[dims_];
}

template<typename T>
nVector<T>::nVector(initializer_list<T> vals)
        : dims_{ static_cast<ptrdiff_t>(vals.size()) }
        , data_{ new T[dims_] }
{

    uninitialized_copy(vals.begin(), vals.end(), data_);
}

template<typename T>
nVector<T>::nVector(const nVector<T>& vec)
        : dims_{ vec.dims_ }
        , data_{ new T[dims_] }
{
    checkSizeRange(vec.dims_, dims_);
    uninitialized_copy(vec.data_, vec.data_ + vec.dims_, data_);
}

template<typename T>
nVector<T>::~nVector()
{
    delete[] data_;
    data_ = nullptr;
}

template<typename T>
nVector<T>& nVector<T>::operator=(const nVector<T>& arr)
{
    checkSizeRange(arr.dims_, dims_);
    if (this != &arr)
    {
        this->data_ = arr.data_;
        this->dims_ = arr.dims_;
    }
    return *this;
}

template<typename T>
T& nVector<T>::operator[] (const ptrdiff_t i)
{
    checkOutOfRange(i);
    return data_[i];
}

template<typename T>
const double& nVector<T>::operator[] (const ptrdiff_t i) const
{
    checkOutOfRange(i);
    return data_[i];
}

template<typename T>
nVector<T> nVector<T>::operator-()
{
    nVector<T> res(dims_);
    for (ptrdiff_t i = 0; i < dims_; i++)
    {
        res.data_[i] = -data_[i];
    }
    return res;
}

template<typename T>
nVector<T>& nVector<T>::operator+=(const nVector<T>& rhs)
{
    checkSizeRange(rhs.dims_, dims_);
    for (ptrdiff_t i = 0; i < dims_; i++)
    {
        data_[i] += rhs.data_[i];
    }
    return *this;
}

template<typename T>
nVector<T>& nVector<T>::operator-=(const nVector<T>& rhs)
{
    checkSizeRange(rhs.dims_, dims_);
    for (ptrdiff_t i = 0; i < dims_; i++)
    {
        data_[i] -= rhs.data_[i];
    }
    return *this;
}

template<typename T>
nVector<T>& nVector<T>::operator*= (const int32_t rhs)
{
    for (ptrdiff_t i = 0; i < dims_; i++)
    {
        data_[i] *= rhs;
    }
    return *this;
}

template<typename T>
nVector<T>& nVector<T>::operator/= (const int32_t rhs)
{
    for (ptrdiff_t i = 0; i < dims_; i++)
    {
        data_[i] /= rhs;
    }
    return *this;
}

template<typename T>
bool nVector<T>::operator== (const nVector & rhs) const
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
ostream& nVector<T>::print(ostream& ostrim) const
{
    ostrim << "nVector(" << data_[0];
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
void nVector<T>::checkSizeRange(const ptrdiff_t lhs, const ptrdiff_t rhs) const
{
    if (lhs != rhs)
    {
        throw std::invalid_argument( "Different range vectors" );
    }
}

template<typename T>
void nVector<T>::checkOutOfRange(const ptrdiff_t i) const
{
    if (!((i <= dims_) && (i >= 0)))
    {
        throw std::invalid_argument("Out of range");
    }
}


template<typename T>
ostream& operator<< (ostream& ostrim, const nVector<T>& z)
{
    return z.print(ostrim);
}

template<typename T>
nVector<T> operator+ (const nVector<T>& lhs, const nVector<T>& rhs)
{
    return nVector<T>(lhs) += nVector<T>(rhs);
}

template<typename T>
nVector<T> operator- (const nVector<T>& lhs, const nVector<T>& rhs)
{
    return nVector<T>(lhs) -= nVector<T>(rhs);
}

template<typename T>
nVector<T> operator* (const nVector<T>& lhs, const int32_t rhs)
{
    return nVector<T>(lhs) *= rhs;
}

template<typename T>
nVector<T> operator/ (const nVector<T>& lhs, const int32_t rhs)
{
    return nVector<T>(lhs) /= rhs;
}


#endif //NVECTOR_NVECTOR_H
