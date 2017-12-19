//============================================================================
// Name        : 5-3.cpp
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
using std::max;
using std::setw;


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

double grade(struct Strudent_Info& stu)
{
	return grade(stu.mid, stu.final, stu.homework);
}

bool compare(struct Strudent_Info& s1, struct Strudent_Info& s2)
{
	return s1.name < s2.name;
}


bool fgrade(struct Strudent_Info& s)
{
	return grade(s) < 60;
}

vector<struct Strudent_Info> extract_fails(vector<struct Strudent_Info>& s)
{
	vector<struct Strudent_Info> fail;
	vector<struct Strudent_Info>::iterator iter = s.begin();

	while (iter != s.end())
	{
		if (grade(*iter))
		{
			fail.push_back(*iter);
			iter = s.erase(iter);
		}
		else
			iter++;
	}

	return fail;
}


int main(void)
{
	struct Strudent_Info stu;
	vector<struct Strudent_Info> record;
	string::size_type maxlen = 0;

	while (read(cin, stu))
	{
		maxlen = max(stu.name.size(), maxlen);
		record.push_back(stu);
	}

	sort(record.begin(), record.end(), compare);

	for (vector<struct Strudent_Info>::size_type i = 0;
			i < record.size(); i++)
	{
		cout << setw(maxlen + 1) << record[i].name;

		try
		{
			double final_grade = grade(record[i].mid, record[i].final,
					record[i].homework);
			streamsize prec = cout.precision();
			cout << "you final grades is " << setprecision(3)
					<< final_grade
					<< setprecision(prec) << endl;
		}
		catch (domain_error e)
		{
			cout << e.what() << endl;

			return 1;
		}
	}



	return 0;


}
