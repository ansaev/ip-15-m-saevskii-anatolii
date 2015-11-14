#include "nvector.h"

template<typename T>
void testOpPlus(const nVector<T>& lhs, const nVector<T>& rhs)
{
	cout << lhs << " + " << rhs << " = ";
	cout << (lhs + rhs) << endl;
}

template<typename T>
void testOpMinus(const nVector<T>& lhs, const nVector<T>& rhs)
{
	cout << lhs << " - " << rhs << " = " << (lhs - rhs) << endl;
}

template<typename T>
void testOpMult(const nVector<T>& lhs, const int32_t rhs)
{
	cout << lhs << " * " << rhs << " = " << (lhs * rhs) << endl;
}

template<typename T>
void testOpDiv(const nVector<T>& lhs, const int32_t rhs)
{
	cout << lhs << " / " << rhs << " = " << (lhs / rhs) << endl;
}

template<typename T>
void testOpCmpEq(const nVector<T>& lhs, const nVector<T>& rhs)
{
	cout << boolalpha << lhs << " == " << rhs << " = " << (lhs == rhs) << endl;
}

template<typename T>
void testOpCmpNotEq(const nVector<T>& lhs, const nVector<T>& rhs)
{
	cout << boolalpha << lhs << " != " << rhs << " = " << (lhs != rhs) << endl;
}

template<typename T>
void testEq(nVector<T>& lhs, nVector<T>& rhs)
{
	cout << lhs << " = " << rhs << " after left = ";
	lhs = rhs;
	cout << lhs << endl;
}

int main()
{
	nVector<double> r01{ -1, 5, 3 };
	nVector<double> r02{ 2, -3, 4 };
	nVector<double> r03{ 2, -10, 8 };
	nVector<double> r04{ 20, -10, 20 };

	cout << "Test operator+" << endl;
	testOpPlus(r01, -r01);
	testOpPlus(r01, r02);

	cout << "\nTest operator-" << endl;
	testOpMinus(r01, r01);
	testOpMinus(r01, r02);

	cout << "\nTest operator*" << endl;
	testOpMult(r01, 5);

	cout << "\nTest operator/" << endl;
	testOpDiv(r01, 5);

	cout << "\nTest operator==" << endl;
	testOpCmpEq(r01, r01);
	testOpCmpEq(r01, -r01);
	testOpCmpEq(r01, r03);

	cout << "\nTest operator!=" << endl;
	testOpCmpNotEq(r01, r01);
	testOpCmpNotEq(r01, -r01);
	testOpCmpNotEq(r01, r02);

	cout << "\nTest operator =" << endl;
	testEq(r04,r01);
	testEq(r01,r02);
	testEq(r01,r04);

	return (0);
}
