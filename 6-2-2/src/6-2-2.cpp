//============================================================================
// Name        : 6-2-2.cpp
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
using std::ostream;
using std::max;
using std::setw;
using std::transform;



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

struct Strudent_Info
{
	string name;
	double mid;
	double final;
	vector<double> homework;
};

istream& read(istream& is, struct Strudent_Info& stu)
{
//	cout << "enter name enter mid and final grades:" << endl;
	is >> stu.name >> stu.mid >> stu.final;
//
//	cout << "enter homework, followed by end-of-file" << endl;
	read_hw(is, stu.homework);
	return is;
}

double grade(const struct Strudent_Info& stu)
{
	return grade(stu.mid, stu.final, stu.homework);
}

bool compare(struct Strudent_Info& s1, struct Strudent_Info& s2)
{
	return s1.name < s2.name;
}

bool did_all(struct Strudent_Info& stu)
{
	return find(stu.homework.begin(), stu.homework.end(), 0) == stu.homework.end();
}

double grade_aux(const struct Strudent_Info& vec)
{
	try
	{
		return grade(vec);
	}
	catch (domain_error)
	{
		return grade(vec.mid, vec.final, 0);
	}
}

double median_analysis(const vector<struct Strudent_Info>& vec)
{
	vector<double> grades;

	transform(vec.begin(), vec.end(), back_inserter(grades), grade_aux);

	return median(grades);
}

void write_analysis(ostream& os, const string& name,
		double analysis(const vector<struct Strudent_Info>& vec),
		vector<struct Strudent_Info> v1,
		vector<struct Strudent_Info> v2)
{
	os << name << ": " << analysis(v1) << "; " <<
	 	analysis(v2) << endl;
}

int main(void)
{
	struct Strudent_Info stu;
	vector<struct Strudent_Info> did, didnt;

	while (read(cin, stu))
	{
		if (did_all(stu))
		{
			did.push_back(stu);
		}
		else
		{
			didnt.push_back(stu);
		}
	}

	if (did.empty())
	{
		cout << "no one did all homework" << endl;
	}

	if (didnt.empty())
	{
		cout << "no one did not all homework" << endl;
	}

	write_analysis(cout, "median", median_analysis, did, didnt);




	return 0;


}
