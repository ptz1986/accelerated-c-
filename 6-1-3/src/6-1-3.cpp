//============================================================================
// Name        : 6-1-3.cpp
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
using std::equal;
using std::search;


string::const_iterator url_beg(string::const_iterator b,
		string::const_iterator e)
{
	string url_flag = "://";
	string::const_iterator fb, fe;
	fb = url_flag.begin();
	fe = url_flag.end();

	b = search(b, e, fb, fe);
	return b;
}


vector<string> find_url(const string& s)
{
	vector<string> url;
	string::const_iterator b, e;
	b = s.begin();
	e = s.end();

	while (b != e)
	{
		b = url_beg(b, e);

		while (b != e)
		{
			for (int i = 0; i < 3; i++)
			{
				cout << *(b + i);
			}
			cout << endl;
			break;
		}
	}

	return url;
}





int main()
{

	string str;

	while (getline(cin, str))
	{
		find_url(str);
	}


	return 0;
}
