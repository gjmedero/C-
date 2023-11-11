#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

	// Open file in append mode
	ofstream f("CSC450_CT5_mod5.txt", ios::app);

	if (!f.is_open()) {
		cerr << "Error opening file" << endl;
		return 1;
	}
	
	
	// Gete user inpute
	cout << "Enter text to append to file: ";
	string userInput;
	getline(cin, userInput);

	f << userInput << endl;

	cout << "Text appended successfully." << endl;

	f.close();

	ifstream input("CSC450_CT5_mod5.txt");

	if (!input.is_open()) {
		cerr << "Error opening file for reading!" << endl;
		return 1;
	}

	// Read input file contents into a string
	string content((istreambuf_iterator<char>(input)), istreambuf_iterator<char>());

	input.close();

	//Reverse the content
	reverse(content.begin(), content.end());

	ofstream output("CSC450-mod5-reverse.txt");

	if (!output.is_open()) {
		cerr << "Error opening output file" << endl;
		return 1;
	}

	output << content;

	output.close();

	cout << "File reversed successfully." << endl;

	return 0;
}