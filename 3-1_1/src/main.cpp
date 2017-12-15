#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

int main(void)
{
	cout << "enter name: ";

	string name;
	cin >> name;
	cout << "Hello: " << name << "!" << endl;

	cout << "enter mid and final grades: ";
	double mid, final;
	cin >> mid >> final;

	cout << "enter homework, followed by end-of-file";

	int count = 0;
	double sum = 0;
	double x;

	while (cin >> x)
	{
		sum += x;
		count++;
	}

	streamsize prec = cout.precision();
	cout << "you final grades is " << setprecision(3)
			<< 0.2 * mid + 0.4 * final + 0.4 * sum / count
			<< setprecision(prec) << endl;

	return 0;

}
