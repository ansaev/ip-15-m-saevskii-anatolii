#include "matrixarr.h"

using namespace std;

int main()
{
	cout << "Test constructors" << endl;
	MatrixArr<int> s01;
	cout << "MatrixArr() = " << s01 << endl;
	MatrixArr<int> s02{ 1, 1 };
	cout << "MatrixArr(1, 1) = " << s02 << endl;
	MatrixArr<int> s03{ s02 };
	cout << "MatrixArr(MatrixArr(1, 1)) = " << s03 << endl;

	cout << "\nTest MatrixArr at" << endl;
	MatrixArr<int> s04{ 3, 4 };
	cout << s04 << endl;
	int x{ 1 };
	for (ptrdiff_t i = 0; i < 3; i++)
	{
		for (ptrdiff_t j = 0; j < 4; j++)
		{
			cout << "s04.at(" << i << ", " << j << ") = " << x << ";  ";
			s04.at(i, j) = x;
			x++;
		}
		cout << "\n";
	}
	cout << s04 << endl;

	cout << "\nTest MatrixArr operator=" << endl;
	MatrixArr<int> s05{ 3, 4 };
	cout << s05 << endl;
	cout << "s05 = s04\n" << (s05 = s04) << endl;

	cout << "\nTest MatrixArr operator== and operator!=" << endl;
	cout << "s05 == s04 = " << boolalpha << (s05 == s04) << endl;
	cout << "s05 != s04 = " << boolalpha << (s05 != s04) << endl;
	return 1;
}