#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

static void swap(int *a, int *b);
static unsigned find_char(const string &s, char c, unsigned &occurs);

int main() {
	/* passing argument by value */
	int a = 0, b = 1;
	cout << "[argument by value]" << endl;
	cout << "a = " << a << ", b = " << b << endl;
	swap(&a, &b);
	cout << "a = " << a << ", b = " << b << endl;
	cout << endl;

	cout << "[argument by reference]" << endl;
	cout << "Searching occurens of char c in string s";
	string str = "This is C++. I don't like C. I like C++";
	char c = '+';
	unsigned occurs = 0;
	auto pos = find_char(str, c, occurs);
	cout << "first occurence of '+' is at: " << pos << endl;
	cout << "total occurence of '+' is: " << occurs << endl;
	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

unsigned find_char(const string &s, char c, unsigned &occurs) {
	auto pos = s.size();
	occurs = 0;
	for (unsigned i = 0; i != s.size(); i++) {
		if (s[i] == c) {
			if (pos == s.size())
				pos = i;
			occurs++;
		}
	}
	return pos;
}