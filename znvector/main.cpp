#include "znvector.h"

template<typename T>
void testOpPlus(const znVector<T>& lhs, const znVector<T>& rhs)
{
    cout << lhs << " + " << rhs << " = ";
    cout << (lhs + rhs) << endl;
}

template<typename T>
void testOpMinus(const znVector<T>& lhs, const znVector<T>& rhs)
{
    cout << lhs << " - " << rhs << " = " << (lhs - rhs) << endl;
}

template<typename T>
void testOpMult(const znVector<T>& lhs, const int32_t rhs)
{
    cout << lhs << " * " << rhs << " = " << (lhs * rhs) << endl;
}

template<typename T>
void testOpDiv(const znVector<T>& lhs, const int32_t rhs)
{
    cout << lhs << " / " << rhs << " = " << (lhs / rhs) << endl;
}

template<typename T>
void testOpCmpEq(znVector<T>& lhs, const znVector<T>& rhs)
{
    cout << boolalpha << lhs << " == " << rhs << " = " << (lhs == rhs) << endl;
}

template<typename T>
void testOpCmpNotEq(const znVector<T>& lhs, const znVector<T>& rhs)
{
    cout << boolalpha << lhs << " != " << rhs << " = " << (lhs != rhs) << endl;
}

int main()
{
    znVector<double> r01{ -1, 5, 3 };
    znVector<double> r02{ 2, -3, 4 };
    znVector<double> r03{ 2, -10, 8 };
    znVector<double> r04{ 20, -10, 20 };
    znVector<double> r05{ -1, 5, 3, 4 };

    cout << "Test operator+" << endl;
    testOpPlus(r01, -r01);
    testOpPlus(r01, r02);
    testOpPlus(r01, r05);

    cout << "\nTest operator-" << endl;
    testOpMinus(r01, r01);
    testOpMinus(r01, r02);
    testOpMinus(r01, r05);

    cout << "\nTest operator*" << endl;
    testOpMult(r01, 5);

    cout << "\nTest operator/" << endl;
    testOpDiv(r01, 5);

    cout << "\nTest operator==" << endl;
    testOpCmpEq(r01, r01);
    testOpCmpEq(r01, -r01);
    testOpCmpEq(r01, r03);
    testOpCmpEq(r01, r05);

    cout << "\nTest operator!=" << endl;
    testOpCmpNotEq(r01, r01);
    testOpCmpNotEq(r01, -r01);
    testOpCmpNotEq(r01, r02);
    testOpCmpNotEq(r01, r05);

    cout << "\nTest operator=" << endl;
    znVector<double> r06{ -1, 5, 3, 4, 7 };
    cout << r01 << " = " << r06 << " operator= ";
    cout << (r01 = r06) << endl;

    return 0;
}