#include <iostream>
#include <stdexcept>

using namespace std;

class stackarray
{
public:
	stackarray()
		: size{ 2 }, data{ new double[size] }
	{

	}
	~stackarray()
	{
		delete[] data;
	}
	void push(const double v)
	{
		if (itop == size)
		{
			double* newData{ new double[size * 2] };
			for (int i{ 0 }; i < size; i++)
			{
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			size *= 2;
		}
		data[itop] = v;
		itop++;
	}
	bool isempty()
	{
		return 0 == itop;
	}
	double pop()
	{
		if (!isempty())
		{
			itop--;
			double res = data[itop];
			return res;
		}
		else throw out_of_range("stack is empty");

	}

private:
	int size{ 0 };
	double* data{ nullptr };
	int itop{ 0 };
};

int main()
{
	stackarray s;
	cout << "is stack empty: " << s.isempty() << endl;
	for (double i = 0; i < 10; i++)
	{
		s.push(i);
		cout << "push(" << i << ")" << endl;
	}

	while (!s.isempty()) {
		cout << "pop() = " << s.pop() << endl;
	}
	try {
		cout << "pop() = " << s.pop() << endl;
	}
	catch (const out_of_range& ex)
	{
		cout << "exception caught " << ex.what();
	}
	getchar();
}
