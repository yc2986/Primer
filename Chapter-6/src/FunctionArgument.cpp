#include <iostream>
#include <string>
#include <initializer_list>
#include <cstdarg>	// for elllipsis

using std::cout;
using std::endl;
using std::string;

static void swap(int *a, int *b);
static unsigned find_char(const string &s, char c, unsigned &occurs);
static void print(const int *arr, size_t size);
// static void print(int arr[]);									// same as above
// static void print(int arr[10]);								// same as above, 10 is only for documenation purpose
static void print(const int *start, const int *end);			// another way to pass in size info
static void x2(int (&arr)[10]);									// pass array by reference
static void print2D(const int (*matrix)[3], size_t row_size);	// passing pointer to an array of 3 ints
// static void print(const int *matrix[3], size_t row);			// this is array of 3 pointers, not correct
static void error_msg(std::initializer_list<string> il);		// variadic arguments with initializer_list
static void error_msg(...);										// variadic arguments with ellipsis parameter, this is only for interfacing with C

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
	cout << endl;

	cout << "[array argument]" << endl;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	print(arr, 10);
	print(arr, arr + 10);
	cout << endl;

	cout << "[array reference argument]" << endl;
	x2(arr);	// multiply by 2 for every element
	print(arr, 10);

	cout << "[multi-dim array argument]" << endl;
	int matrix[][3] = {
		{ 0, 1, 2 },
		{ 3, 4, 5 },
		{ 6, 7, 8 },
	};
	print2D(matrix, 3);
	cout << endl;

	cout << "[varying argument]" << endl;
	cout << "initializer_list method" << endl;
	error_msg({"error: 400", "page not found!"});
	cout << "ellipsis parameters" << endl;
	error_msg("error: 500", "internal server error!");

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

void print(const int *arr, size_t size) {
	for (unsigned i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void print(const int *start, const int *end) {
	while (start != end)
		cout << *start++ << " ";
	cout << endl;
}

void x2(int (&arr)[10]) {
	for (unsigned i = 0; i < 10; i++)
		arr[i] *= 2;
}

void print2D(const int (*arr)[3], size_t row_size) {
	for (unsigned i = 0; i < row_size; i++) {
		for (unsigned j = 0; j < 3; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

void error_msg(std::initializer_list<string> il) {
	for (const auto &elem : il)
		cout << elem << endl;
}

void error_msg(...) {
	va_list list;	// access ellipsis
	unsigned num = 2;
	va_start(list, num);	// initalize va_list
	for (unsigned arg = 0; arg < num; arg++)
		cout << va_arg(list, const char*) << endl;;
	va_end(list);	// clean up
}