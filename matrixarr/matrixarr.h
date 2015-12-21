#ifndef H_MATRIXARR
#define H_MATRIXARR

#include <iostream>
#include <cassert>
#include <memory>
#include <cstddef>

template<class T>
class MatrixArr
{
public:
	MatrixArr() = default;
	MatrixArr(const ptrdiff_t nRow, const ptrdiff_t nCol);
	MatrixArr(const MatrixArr<T>& rhs);
	~MatrixArr();

	MatrixArr& operator= (const MatrixArr<T>& rhs);
	bool operator== (const MatrixArr<T>& rhs) const;
	bool operator!= (const MatrixArr<T>& rhs) const { return !operator== (rhs); };
	T at(const ptrdiff_t nRow, const ptrdiff_t nCol) const;
	T& at(const ptrdiff_t nRow, const ptrdiff_t nCol);
	ptrdiff_t rows() const { return _nRow; };
	ptrdiff_t columns() const { return _nCol; };
	std::ostream& print(std::ostream& ostrim) const;
private:
	ptrdiff_t _nRow{ 0 };
	ptrdiff_t _nCol{ 0 };
	T* _data{ nullptr };

	void checkOutOfRange(const ptrdiff_t nRow, const ptrdiff_t nCol) const;
	ptrdiff_t getIndexArray(const ptrdiff_t nRow, const ptrdiff_t nCol) const;
	void checkSizeRange(const MatrixArr<T>& rhs) const;
};

template <class T>
MatrixArr<T>::MatrixArr(const ptrdiff_t nRow, const ptrdiff_t nCol)
	:_nRow{ nRow }, _nCol{ nCol }, _data{ new T[nRow * nCol]() }{}

template <class T>
MatrixArr<T>::MatrixArr(const MatrixArr<T>& rhs)
	:_nRow{ rhs._nRow }, _nCol{ rhs._nCol }, _data{ new T[_nRow * _nCol] }
{
	std::uninitialized_copy(rhs._data, rhs._data + (rhs._nRow * rhs._nCol), _data);
}

template <class T>
MatrixArr<T>::~MatrixArr()
{
	delete[] _data;
	_data = nullptr;
}

template <class T>
MatrixArr<T>& MatrixArr<T>::operator=(const MatrixArr<T>& rhs)
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
bool MatrixArr<T>::operator==(const MatrixArr<T>& rhs) const
{
	if (_nRow != rhs._nRow || _nCol != rhs._nCol)
	{
		return false;
	}
	for (ptrdiff_t i = 0; i < _nRow * _nCol; i++)
	{
		if (_data[i] != rhs._data[i])
		{
			return false;
		}
	}
	return true;
}

template <class T>
T MatrixArr<T>::at(const ptrdiff_t nRow, const ptrdiff_t nCol) const
{
	return _data[getIndexArray(nRow, nCol)];
}

template <class T>
T& MatrixArr<T>::at(const ptrdiff_t nRow, const ptrdiff_t nCol)
{
	return _data[getIndexArray(nRow, nCol)];
}

template <class T>
std::ostream& MatrixArr<T>::print(std::ostream& ostrim) const
{
	T *temp = _data;
	ostrim << "MatrixArr(";
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
		ostrim << _data[getIndexArray(i, 0)];
		for (ptrdiff_t j = 1; j < _nCol; j++)
		{
			ostrim << ", " << _data[getIndexArray(i, j)];
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
void MatrixArr<T>::checkOutOfRange(const ptrdiff_t nRow, const ptrdiff_t nCol) const
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
ptrdiff_t MatrixArr<T>::getIndexArray(const ptrdiff_t nRow, const ptrdiff_t nCol) const
{
	checkOutOfRange(nRow, nCol);
	return _nCol * nRow + nCol;
}

template <class T>
void MatrixArr<T>::checkSizeRange(const MatrixArr<T>& rhs) const
{
	if (rhs._nRow != _nRow || rhs._nCol != _nCol)
	{
		assert("Different range matrix");
	}
}

template<typename T>
std::ostream& operator<<(std::ostream& ostrim, const MatrixArr<T>& z)
{
	return z.print(ostrim);
}

#endif