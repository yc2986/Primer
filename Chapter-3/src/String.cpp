#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

static void initialization();
static void basicOperation();
static void iterator();

int main() {
	cout << "[initialization]" << endl;
	initialization();
	cout << endl;

	cout << "[basic operation]" << endl;
	basicOperation();
	cout << endl;

	cout << "[iterator]" << endl;
	iterator();

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

static void basicOperation() {
	// read single string using input operator
	string word;
	cout << "Enter a string, ended by whitespace or newline." << endl;
	cin >> word;
	cout << "You have entered: " << word << endl;

	// read two string using input operator
	string word1, word2;
	cout << "Enter two strings separated by whitespace or newline." << endl;
	cin >> word1 >> word2;
	cout << "First word: " << word1 << " Second word: " << word2 << endl;

	cin.ignore(1);

	// read a line of string using getline
	string line;
	cout << "Enter a line of string ended by newline." << endl;
	getline(cin, line);
	cout << "You have entered: " << line << endl;

	// read size of the string
	auto length = line.size();	// auto is string::size_type, it is unsigned
	cout << "Its length is: " << length << endl;

	// string compare, dictionary order compare
	word = "Hello";
	word1 = "Hello World";
	word2 = "Hiya";
	// expect <
	cout << "[" << word << "]";
	cout << ((word > word1) ? ">" : "<");
	cout << "[" << word1 << "]" << endl;
	// expect >
	cout << "[" << word2 << "]";
	cout << ((word2 > word1) ? ">" : "<");
	cout << "[" << word1 << "]" << endl;

	// Adding of string and string literals
	word1 = "hello, ";
	word2 = "world\n";
	string sentence = word1 + word2;	// adding strings
	//word1 += word2;	// equivalent of word1 + word2
	cout << "Sentence adding two string is: " << sentence;

	word1 = "hello";
	word2 = "world";
	sentence = word1 + ", " + word2 + '\n';	// string can be added to string literal and singal character via + operator from both side
	cout << "Sentence adding string, string literal, string: " << sentence;
	sentence = word1 + ", " + "c++"; 	// equivalent to (word1 + ", ") + "c++"
	cout << "Sentence adding string, literal, literal: " << sentence << endl; 
	//sentence = ", " + "c++"; 	// invalide cause no string literal + string literal rule
	//sentence = "hello" + ", " + word2; // invalide same as above.
}

static void iterator() {
	// iterate through all char in a string
	string str = "string";
	cout << "all characters in " << str << "are:" << endl;
	for (auto c : str)
		cout << c << " ";
	cout << endl;

	// count white space in sentence
	string s1 = "i am super mario!";
	decltype(s1.size()) space_count = 0;	// get correct unsigned counter type
	for (auto c : s1)
		if (isspace(c))
			space_count++;
	cout << space_count << " white space in: " << s1 << endl;

	// uppercase sentence
	string s2 = s1;
	for (auto &c : s2)
		c = toupper(c);
	cout << "upper case: " << s2 << endl;

	// uppercase first word
	for (decltype(s1.size()) i = 0; i < s1.size() && !isspace(s1[i]); i++)
		s1[i] = toupper(s1[i]);
	cout << "first word upper case: " << s1 << endl;
}