#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str_one;
	string str_two;
	string cat;

	cout << "Hello Sublime Text 4 and C++" << endl;

	cout <<"Please provide two strings to concatenate them." << endl;
	
	cout << "first_string: " << str_one << endl;
	
	getline(cin, str_one);

	cout << "second_string: " << str_two << endl;

	getline(cin, str_two);

	cat = str_one + str_two;

	cout << "The two strings concatenated together form: " << cat << endl;

	return 0;
}

