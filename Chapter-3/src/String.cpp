#include <iostream>
#include <string>

using namespace std;

static void initialization();

int main() {
	cout << "[initialization]" << endl;
	initialization();
	cout << endl;

	return 0;
}

static void initialization() {
	/*
	 * clean string constructors
	 */
	string s1;				// declare a string, initialized to empty
	s1 = "string";
	string s2 = s1; 		// copy constructor
	string s3(s1);			// copy constructor
	string s4 = "string4";	// string literal initialization
	string s5("string5");	// string literal constructor
	string s6(10, 'c');		// copy char constructor 10 c

	cout << "s1: " << s1 << endl;
	cout << "s2 copy from s1: " << s2 << endl;
	cout << "s3 copy from s1: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	cout << "s5: " << s5 << endl;
	cout << "s6 stack of c's: " << s6 << endl;
}