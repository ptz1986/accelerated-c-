//============================================================================
// Name        : 5-6.cpp
// Author      : ptz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cout;
using std::endl;
using std::vector;
using std::string;

vector<string> split(string& s)
{
	vector<string> vec;
	string::size_type size = s.size();
	string::size_type i = 0, j = 0;

	while (i != size)
	{
		while (i!= size && isspace(s[i]))
		{
			i++;
		}

		j = i;

		while (j!= size && !isspace(s[j]))
		{
			j++;
		}

		if (i != j)
		{
			vec.push_back(s.substr(i, j - i));
			i = j;
		}

	}

	for (vector<string>::const_iterator iter = vec.begin();
				iter != vec.end(); iter++)
	{
		cout << "subroutine: " << *iter << endl;
	}

	return vec;
}



int main()
{

	string str = "hello world!";

	cout << "origin: " << str << endl;

	vector<string> v = split(str);

	for (vector<string>::const_iterator iter = v.begin();
			iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}
	return 0;
}
