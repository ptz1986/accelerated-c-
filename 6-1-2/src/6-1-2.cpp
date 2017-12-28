//============================================================================
// Name        : 6-1-2.cpp
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


using namespace std;

bool ispal(const string& s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}



int main()
{

	string str;

	while (getline(cin, str))
	{
		cout << (ispal(str) ? "true" : "false") << endl;
	}


	return 0;
}
