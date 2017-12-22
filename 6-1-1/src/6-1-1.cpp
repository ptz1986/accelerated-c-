//============================================================================
// Name        : 6-1-1.cpp
// Author      : ptz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::find;
using std::find_if;

using namespace std;

bool space(char c)
{
	return isspace(c);
}

bool nospace(char c)
{
	return !isspace(c);
}

vector<string> split(string& s)
{
	vector<string> vec;
	string::size_type size = s.size();
//	string::size_type i = 0, j = 0;
	string::iterator i = s.begin();

	while (i != s.end())
	{
//		while (i!= size && isspace(s[i]))
//		{
//			i++;
//		}
		i = find_if(i, s.end(), nospace);

		string::iterator j = i;

//		while (j!= size && !isspace(s[j]))
//		{
//			j++;
//		}
		j = find_if(j, s.end(), space);

		if (i != j)
		{
//			vec.push_back(s.substr(i, j - i));
			vec.push_back(string(i, j));
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

	string str;

	while (getline(cin, str))
	{
		vector<string> v = split(str);

		for (vector<string>::const_iterator iter = v.begin();
				iter != v.end(); iter++)
		{
			cout << *iter << endl;
		}
	}


	return 0;
}
