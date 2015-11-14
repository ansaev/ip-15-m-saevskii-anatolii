//
// Created by ansaev on 26.10.15.
//

#ifndef STACKLST_STACK_LIST_H
#define STACKLST_STACK_LIST_H

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

template<class T>
class StackLst
{
public:
    StackLst() = default;
    StackLst(initializer_list<T> v);
    StackLst(const StackLst<T>& v);
    ~StackLst();

    StackLst& operator= (const StackLst<T>& v);
    void push(const T v);
    bool isEmpty() const
    {
        return nullptr == head_;
    }
    void pop();

    T getTop();
    ostream& print(ostream& ostrim) const;
private:
    struct Element
    {
        T data_ { T{} };
        Element* next_{ nullptr };
    };
    Element* head_{ nullptr };

    void copy(const StackLst<T>& rhs);
};

template <class T>
StackLst<T>::StackLst(initializer_list<T> v)
{
    vector <T> temp;
    temp.insert(temp.end(), v.begin(), v.end());
    for (size_t i = 0; i < temp.size(); i++)
    {
        push(temp[i]);
    }
}

template<typename T>
StackLst<T>::StackLst(const StackLst<T>& rhs)
{
    copy(rhs);
}

template<typename T>
StackLst<T>::~StackLst()
{
    while (!isEmpty())
    {
        pop();
    }
}

template <class T>
StackLst<T>& StackLst<T>::operator=(const StackLst<T>& rhs)
{
    if (this != &rhs)
    {
        head_ = nullptr;
        copy(rhs);
    }
    return *this;
}

template<typename T>
void StackLst<T>::push(const T v)
{
    Element* temp{ new Element };
    temp->data_ = v;
    temp->next_ = head_;
    head_ = temp;
}

template<typename T>
void StackLst<T>::pop()
{
    if (!isEmpty())
    {
        Element *temp{ head_->next_ };
        delete head_;
        head_ = temp;
    }
}

template<typename T>
T StackLst<T>::getTop()
{
    if (isEmpty())
    {
        assert("StackLst is Empty");
    }
    return head_->data_;
}

template<typename T>
ostream& StackLst<T>::print(ostream& ostrim) const
{
    Element *temp = head_;
    ostrim << "StackLst(";
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
void StackLst<T>::copy(const StackLst<T>& rhs)
{
    Element* tempRhs{ rhs.head_ };
    while (tempRhs != nullptr)
    {
        if (isEmpty())
        {
            push(tempRhs->data_);
        }
        else
        {
            Element* tempLhs{ head_ };
            while (tempLhs->next_ != nullptr)
            {
                tempLhs = tempLhs->next_;
            }
            Element* nE{ new Element };
            nE->data_ = tempRhs->data_;
            tempLhs->next_ = nE;
        }
        tempRhs = tempRhs->next_;
    }
}

template<typename T>
ostream& operator<<(ostream& ostrim, const StackLst<T>& z)
{
    return z.print(ostrim);
}

#endif //STACKLST_STACK_LIST_H
