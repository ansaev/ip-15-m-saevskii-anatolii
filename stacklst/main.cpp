#include "stack_list.h"

int main()
{
    cout << "Test constructors" << endl;
    StackLst<int> s01;
    cout << "StackLst() = " << s01 << endl;
    StackLst<int> s02{ 13 };
    cout << "StackLst(5) = " << s02 << endl;
    StackLst<int> s03{ s02 };
    cout << "StackLst(StackLst(s02)) = " << s03 << endl;
    StackLst<int> s05{ 6, 666, 66 };
    cout << "StackLst(6, 666, 66) = " << s05 << endl;

    cout << "\nTest StackLst operator=" << endl;
    StackLst<int> s04{ 432 };
    cout << "StackLst(432) = " << s04 << endl;
    s04 = s02;
    cout << "s04 = s02 " << s04 << endl;

    cout << "\nTest StackLst push" << endl;
    cout << s02;
    s02.push(567);
    cout << ".push(567) = " << s02 << endl;
    cout << s02;
    s02.push(812);
    cout << ".push(812) = " << s02 << endl;
    cout << s02;
    s02.push(22);
    cout << ".push(22) = " << s02 << endl;

    cout << "\nTest Stack pop" << endl;
    cout << s02 << ".pop() = ";
    s02.pop();
    cout << s02 << endl;
    cout << s02 << ".pop() = ";
    s02.pop();
    cout << s02 << endl;
    cout << s02 << ".pop() = ";
    s02.pop();
    cout << s02 << endl;

    cout << "\nTest Stack getTop" << endl;
    cout << s02 << ".getTop() = " << s02.getTop() << endl;
    s02.push(92);
    cout << s02 << ".getTop() = " << s02.getTop() << endl;
    s02.push(71);
    cout << s02 << ".getTop() = " << s02.getTop() << endl;
    s02.push(42);
    cout << s02 << ".getTop() = " << s02.getTop() << endl;
    return 0;
}