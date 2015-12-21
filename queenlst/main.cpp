#include "queenlst.h"
using namespace std;

int main()
{
	cout << "Test constructors" << endl;
	QueueLst<int> s01;
	cout << "QueueLst() = " << s01 << endl;
	QueueLst<int> s02{ 1 };
	cout << "QueueLst(5) = " << s02 << endl;
	QueueLst<int> s03{ s02 };
	cout << "QueueLst(s02) = " << s03 << endl;
	QueueLst<int> s05{ 20, 21, 23 };
	cout << "QueueLst(20, 21, 23) = " << s05 << endl;
	
	
	cout << "\nTest QueueLst operator=" << endl;
	QueueLst<int> s04{ 20 };
	cout << "QueueLst(20) = " << s04 << endl;
	s04 = s05;
	cout << "s04 = s05 " << s04 << endl;
	
	cout << "\nTest QueueLst push" << endl;
	cout << s02;
	s02.push(2);
	cout << ".push(2) = " << s02 << endl;
	cout << s02;
	s02.push(3);
	cout << ".push(3) = " << s02 << endl;
	cout << s02;
	s02.push(4);
	cout << ".push(4) = " << s02 << endl;

	cout << "\nTest QueueLst pop" << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;
	
	cout << "\nTest QueueLst getFirst" << endl;
	QueueLst<int> s06{ 20, 21, 22, 23, 24, 25 };
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	return 0;
}