#ifndef H_MATRIXNEC
#define H_MATRIXNEC

#include <iostream>
#include <cassert>
#include <memory>
#include <cstddef>

template<class T>
class MatrixNec
{
public:
	MatrixNec() = default;
	MatrixNec(const ptrdiff_t nRow, const ptrdiff_t nCol);
	MatrixNec(const MatrixNec<T>& rhs);
	~MatrixNec();

	MatrixNec& operator= (const MatrixNec<T>& rhs);
	bool operator== (const MatrixNec<T>& rhs) const;
	bool operator!= (const MatrixNec<T>& rhs) const { return !operator== (rhs); };
	T at(const ptrdiff_t nRow, const ptrdiff_t nCol) const;
	T& at(const ptrdiff_t nRow, const ptrdiff_t nCol);
	ptrdiff_t rows() const { return _nRow; };
	ptrdiff_t columns() const { return _nCol; };
	std::ostream& print(std::ostream& ostrim) const;
private:
	ptrdiff_t _nRow{ 0 };
	ptrdiff_t _nCol{ 0 };
	T** _data{ nullptr };
	
	void checkOutOfRange(const ptrdiff_t nRow, const ptrdiff_t nCol) const;
	T& getIndexArray(const ptrdiff_t nRow, const ptrdiff_t nCol) const;
	void checkSizeRange(const MatrixNec<T>& rhs) const;
};

template <class T>
MatrixNec<T>::MatrixNec(const ptrdiff_t nRow, const ptrdiff_t nCol)
	:_nRow{ nRow }, _nCol{ nCol }, _data{ new T*[nRow] }
{
	T* temp{ new T[nRow * nCol]() };
	for (ptrdiff_t i = 0; i < nRow; i++)
	{
		_data[i] = &temp[i * nCol];
	}
}

template <class T>
MatrixNec<T>::MatrixNec(const MatrixNec<T>& rhs)
	: MatrixNec{ rhs._nRow, rhs._nCol }
{
	std::uninitialized_copy(rhs._data[0], rhs._data[0] + (rhs._nRow * rhs._nCol), _data[0]);
}

template <class T>
MatrixNec<T>::~MatrixNec()
{
	delete[] _data;
	_data = nullptr;
}

template <class T>
MatrixNec<T>& MatrixNec<T>::operator=(const MatrixNec<T>& rhs)
{
	checkSizeRange(rhs);
	if (this != &rhs)
	{
		this->_nRow = rhs._nRow;
		this->_nCol = rhs._nCol;
		this->_data = rhs._data;
	}
	return *this;
}

template <class T>
bool MatrixNec<T>::operator==(const MatrixNec<T>& rhs) const
{
	if (_nRow != rhs._nRow || _nCol != rhs._nCol)
	{
		return false;
	}
	for (ptrdiff_t i = 0; i < _nRow * _nCol; i++)
	{
		if (*(_data[0] + i) != *(rhs._data[0] + i))
		{
			return false;
		}
	}
	return true;
}

template <class T>
T MatrixNec<T>::at(const ptrdiff_t nRow, const ptrdiff_t nCol) const
{
	return getIndexArray(nRow, nCol);
}

template <class T>
T& MatrixNec<T>::at(const ptrdiff_t nRow, const ptrdiff_t nCol)
{
	return getIndexArray(nRow, nCol);
}

template <class T>
std::ostream& MatrixNec<T>::print(std::ostream& ostrim) const
{
	T** temp = _data;
	ostrim << "MatrixNec(";
	if (temp == nullptr || _nCol == 0 || _nRow == 0)
	{
		ostrim << "null)";
		return ostrim;
	}
	for (ptrdiff_t i = 0; i < _nRow; i++)
	{
		if (i > 0)
		{
			ostrim << "          ";
		}
		ostrim << getIndexArray(i, 0);
		for (ptrdiff_t j = 1; j < _nCol; j++)
		{
			ostrim << ", " << getIndexArray(i, j);
		}
		if (i != _nRow - 1)
		{
			ostrim << "\n";
		}
	}
	ostrim << ")";
	return ostrim;
}

template <class T>
void MatrixNec<T>::checkOutOfRange(const ptrdiff_t nRow, const ptrdiff_t nCol) const
{
	if (nRow < _nRow - 1 || nRow < 0)
	{
		assert("nRow is out of range");
	}
	if (nCol < _nCol - 1 || nCol < 0)
	{
		assert("nCol is out of range");
	}
}

template <class T>
T& MatrixNec<T>::getIndexArray(const ptrdiff_t nRow, const ptrdiff_t nCol) const
{
	checkOutOfRange(nRow, nCol);
	return *(_data[nRow] + nCol);
}

template <class T>
void MatrixNec<T>::checkSizeRange(const MatrixNec<T>& rhs) const
{
	if (rhs._nRow != _nRow || rhs._nCol != _nCol)
	{
		assert("Different range matrix");
	}
}

template<typename T>
std::ostream& operator<<(std::ostream& ostrim, const MatrixNec<T>& z)
{
	return z.print(ostrim);
}

#endif