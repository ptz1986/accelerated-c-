//============================================================================
// Name        : 4-1-5.cpp
// Author      : ptz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::domain_error;
using std::istream;


double grade(double mid, double final, double homework)
{
	return 0.2 * mid + 0.4 * final + 0.4 * homework;
}

double median(vector<double> vec)
{
	typedef vector<double>::size_type size_vec;

	size_vec size = vec.size();

	if (size == 0)
	{
		throw domain_error("median of an empty size");
	}

	sort(vec.begin(), vec.end());

	size_vec mid_size = size / 2;

	if (size % 2)
	{
		return vec[mid_size];
	}
	else
	{
		return (vec[mid_size] + vec[mid_size - 1]) / 2;
	}
}

double grade(double mid, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("homework is empty");

	return grade(mid, final, median(hw));
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in)
	{
		hw.clear();

		double x;
		while (in >> x)
		{
			hw.push_back(x);
		}

		in.clear();
	}

	return in;
}

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

//	double x;
	vector<double> homework;

//	while (cin >> x)
//	{
//		homework.push_back(x);
//	}

	read_hw(cin, homework);

	try
	{
		double final_grade = grade(mid, final, homework);
		streamsize prec = cout.precision();
		cout << "you final grades is " << setprecision(3)
				<< final_grade
				<< setprecision(prec) << endl;
	}
	catch (domain_error)
	{
		cout << "enter your homework!" << endl;

		return 1;
	}

	return 0;


}

