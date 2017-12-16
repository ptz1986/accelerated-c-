#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;

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

	double x;
	vector<double> homework;

	while (cin >> x)
	{
		homework.push_back(x);
	}

	double median;
	vector<double>::size_type size = homework.size();

	if (size == 0)
	{
		cout << "need homework!" << endl;
	}
	else
	{
		median = size % 2 == 0 ?
				(homework[size / 2] + homework[size / 2 - 1]) / 2 :
				homework[size / 2];
	}

	streamsize prec = cout.precision();
	cout << "you final grades is " << setprecision(3)
			<< median
			<< setprecision(prec) << endl;

	return 0;

}
