#include "queenarr.h"
using namespace std;

int main()
{
	cout << "Test constructors" << endl;
	QueenArr<int> s01;
	cout << "QueenArr() = " << s01 << endl;
	QueenArr<int> s02{ 5 };
	cout << "QueenArr(5) = " << s02 << endl;
	QueenArr<int> s03{ s02 };
	cout << "QueenArr(s02) = " << s03 << endl;
	QueenArr<int> s05{ 20, 21, 23 };
	cout << "QueenArr(20, 21, 23) = " << s05 << endl;
	
	cout << "\nTest QueenArr operator=" << endl;
	QueenArr<int> s04{ 20 };
	cout << "QueenArr(20) = " << s04 << endl;
	s04 = s05;
	cout << "s04 = s05 " << s04 << endl;
	
	cout << "\nTest QueenArr push" << endl;
	cout << s02;
	s02.push(2);
	cout << ".push(2) = " << s02 << endl;
	cout << s02;
	s02.push(3);
	cout << ".push(3) = " << s02 << endl;
	cout << s02;
	s02.push(4);
	cout << ".push(4) = " << s02 << endl;
	
	cout << "\nTest QueenArr pop" << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;
	
	cout << "\nTest QueenArr getFirst" << endl;
	QueenArr<int> s06{ 20, 21, 22, 23, 24, 25 };
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;

	cout << "\nTest QueenArr recreate data_" << endl;
	QueenArr<int> s07{ 1 };
	cout << s07 << ".push(2) = ";
	s07.push(2);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".pop() = ";
	s07.pop();
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".push(3) = ";
	s07.push(3);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".push(4) = ";
	s07.push(4);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".push(5) = ";
	s07.push(5);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".pop() = ";
	s07.pop();
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".pop() = ";
	s07.pop();
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".push(6) = ";
	s07.push(6);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".push(7) = ";
	s07.push(7);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".push(8) = ";
	s07.push(8);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	return 0;
}