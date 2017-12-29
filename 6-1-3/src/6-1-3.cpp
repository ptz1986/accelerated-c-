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

bool not_url_char(char c)
{
	static string url_ch= "+-!/.:";

	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_beg(string::const_iterator b,
		string::const_iterator e)
{
	string url_flag = "://";
	string::const_iterator fb, fe, i;
	fb = url_flag.begin();
	fe = url_flag.end();
	i = b;

	while ((i = search(i, e, fb, fe)) != e)
	{
		if (i != b && i + url_flag.size() != e)
		{
			string::const_iterator beg = i;

			while (beg!= b && isalpha(beg[-1]))
				beg--;

			if (beg != i && i + url_flag.size() != e &&
					!not_url_char(i[url_flag.size()]))
				return beg;
		}

		i += url_flag.size();
	}

	return e;
}

string::const_iterator url_end(string::const_iterator b,
		string::const_iterator e)
{
	return find_if(b, e, not_url_char);
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

		string::const_iterator after;
		after = url_end(b, e);

		url.push_back(string(b, after));

		b = after;
	}

	return url;
}





int main()
{

	string str;
	vector<string> url_v;

	while (getline(cin, str))
	{
		url_v = find_url(str);

		for (vector<string>::const_iterator i = url_v.begin();
				i != url_v.end(); i++)
		{
			cout << (*i) << endl;
		}
	}

//	url_v = find_url(str);
//
//	for (vector<string>::const_iterator i = url_v.begin();
//			i != url_v.end(); i++)
//	{
//		cout << (*i) << endl;
//	}


	return 0;
}
