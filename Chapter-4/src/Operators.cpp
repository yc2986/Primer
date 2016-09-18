#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

struct Sales_data {
	int revenue;
	string ISBN;
	double unit_price;
};

static void arithmeticOperators();
static void logicalOperators();
static void assignmentOperators();
static void increamentalOperators();
static void memberaccessOperators();
static void conditionalOperators();
static void bitwiseOperators();
static void sizeofOperators();
static void commaOperators();
static void typeCast();

int main() {
	cout << "[arithmetic]" << endl;
	arithmeticOperators();
	cout << endl;

	cout << "[logical]" << endl;
	logicalOperators();
	cout << endl;

	cout << "[assignment]" << endl;
	assignmentOperators();
	cout << endl;

	cout << "[increamental]" << endl;
	increamentalOperators();
	cout << endl;

	cout << "[member access]" << endl;
	memberaccessOperators();
	cout << endl;

	cout << "[conditional]" << endl;
	conditionalOperators();
	cout << endl;

	cout << "[bitwise]" << endl;
	bitwiseOperators();
	cout << endl;

	cout << "[sizeof]" << endl;
	sizeofOperators();
	cout << endl;

	cout << "[comma]" << endl;
	commaOperators();
	cout << endl;

	cout << "[type cast]" << endl;
	typeCast();

	return 0;
}

static void arithmeticOperators() {
	/* integer overflow issues */
	short short_int = 32767;	// short max
	cout << "short integer maximum 32767 + 2 will cause overflow: " << short_int + 2 << endl;
	/* bool promotion */
	bool boolean = true;
	cout << "bool variable: boolean = " << boolean << ", but -boolean = " << -boolean << " rather than 0!" << endl;	// boolean will be promoted to int when its affected by unary minus
	/* divison, remainter will be discarded */
	/* modulus, display the remainder of divison */
	cout << "21 / 6 = " << 21 / 6 << ", 21 % 6 = " << 21 % 6 << endl;
	cout << "21 / 7 = " << 21 / 7 << ", 21 % 7 = " << 21 % 7 << endl;
	cout << "-21 / -8 = " << -21 / -8 << ", -21 % -8 = " << -21 % -8 << endl;
	cout << "21 / -5 = " << 21 / -5 << ", 21 % -5 = " << 21 % -5 << endl;
}

static void logicalOperators() {
	/* logical and/or */
	int val = 0;
	cout << "(val++ > 0 && val++ == 1): " << (val++ > 0 && val++ == 1) << endl;		// logical and
	cout << "left expression should be true in order to trigger right expression, this case left is false, val = " << val << endl;
	val = 0;
	cout << "(val++ == 0 || val++ = 1): " << (val++ == 0 || val++ == 1) << endl;	// logical or
	cout << "left expression should be false in order to trigger right expression, this case left is true, val = " << val << endl;
	vector<int> arr;
	cout << "empty vector? " << arr.empty() << endl;	// logical not
	arr.push_back(0);
	cout << "empty vector? " << arr.empty() << endl;	// logical not
}

static void assignmentOperators() {
	int i, j;
	double d;
	i = j = 2;	// associative assignment
	cout << "i = " << i << ", j = " << j << endl;
	i = d = 3.5;	// type cast for i, equivalent to i = (d = 3.5)
	cout << "i = " << i << ", d = " << d << endl;
	vector<int> arr;
	arr = {0, 1, 2, 3, 4};	// list assignment
	for (auto &a : arr)
		cout << a << " ";
	cout << endl;
	if ((i = j + 3) == 5)	// assignment has low precedence
		cout << "i == 5" << endl;
}

static void increamentalOperators() {
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
	auto it = arr.cbegin();
	cout << "iterate through array using increamental iterator: ";
	while (it != arr.cend())
		cout << *it++ << " ";
	cout << endl;
}

static void memberaccessOperators() {
	string strs = "C++ is the best!", *ptr = &strs;
	cout << "ptr->size() = " << ptr->size() << endl;
}

static void conditionalOperators() {
	vector<int> scores = {59, 61, 60, 80, 75, 90, 100, 30};
	cout << "scores pass/fail system: " << endl;
	for (auto s : scores)
		cout << "scores = " << s << ", " << ((s >= 60) ? "pass" : "fail") << endl;
}

static void bitwiseOperators() {
	/*
	 * bitwise operator should be used with unsigned type
	 * signed type yeilds undefined behavior for sign bit when bit operated
	 * bit shift operation on (unsigned char) and (unsigned short) will promote the target to (int)
	 */
	unsigned char bits = 0233;	// octal literal for binary number: 10011011
	cout << "bits       = " << bitset<8>(bits) << endl;
	cout << "bits << 8  = " << bitset<32>(bits << 8) << endl;	// left shift (unsigned char) 8 bits, promoted to (signed int)!
	cout << "bits << 23 = " << bitset<32>(bits << 23) << endl; 	// left shift 8 bits, unsigned char promoted to signed int!
	cout << "bits >> 3  = " << bitset<32>(bits >> 3) << endl;	// right shift 3 bits, unsigned char promoted to signed int!
	cout << "~bits      = " << bitset<32>(~bits) << endl;		// bitwise not, unsigned char promoted to signed int!

	/*
	 * bitwise AND, OR, XOR operations
	 */
	unsigned char b1 = 0145;	// 01100101
	unsigned char b2 = 0257;	// 10101111
	cout << "b1 = " << bitset<8>(b1) << endl;
	cout << "b2 = " << bitset<8>(b2) << endl;
	cout << "b1 & b2 = " << bitset<8>(b1 & b2) << endl;	// bitwise and, 00100101
	cout << "b1 | b2 = " << bitset<8>(b1 | b2) << endl;	// bitwise or,  11101111
	cout << "b1 ^ b2 = " << bitset<8>(b1 ^ b2) << endl;	// bitwise xor, 11001010
	/* an example using bitwise operation */
	cout << "recording pass/fail status for 30 studends" << endl;
	unsigned long grades = 0;	// every student's status stored in one bits, high 2 bits unused
	bool status;	// pass/fail probe
	cout << "setting student #27 to pass: grades |= 1UL << 27" << endl;
	grades |= 1UL << 27;	// left shift unsigned long 1 27 bits
	status = grades & (1UL << 27);	// reading pass/fail status of student27
	cout << "student #27: " << (status ? "pass" : "fail") << endl;
	cout << "setting student #27 to fail: grades &= ~(1UL << 27)" << endl;
	grades &= ~(1UL << 27);
	status = grades & (1UL << 27);	// reading pass/fail status of student27
	cout << "student #27: " << (status ? "pass" : "fail") << endl;
}

static void sizeofOperators() {
	/*
	 * two forms:
	 *     sizeof (type)
	 *     sizeof expr
	 */
	Sales_data data, *p;
	cout << "size of Sales_data: " << sizeof(Sales_data) << endl;
	cout << "size of Sales_data object: " << sizeof data << endl;
	cout << "size of a pointer: " << sizeof p << endl;
	cout << "size of a Sales_data pointer memory: " << sizeof *p << endl;
	cout << "size of revenue field in Sales_data: " << sizeof Sales_data::revenue << endl;
}

static void commaOperators() {
	int i = 0, j = 4;
	for (i = 0; i < 5; i++, j--)	// double iterator, evaluate from left to right order
		cout << "(i, j) = " << "(" << i << ", " << j << ")" << endl;
}

static void typeCast() {
	/*
	 * Explicit cast, named cast:
	 *     cast-name<type>(expr)
	 */
	/* static_cast is used for case where we are trying to assign larger type to a small type */
	int i = 1, j = 2;
	double slope = static_cast<double>(i) / j;	// force floating arithmetic by static cast
	void *ptr = &slope;	// void ptr point to double object
	double *dp = static_cast<double*>(ptr);	// cast void pointer back to double pointer
	cout << "(double)slope = " << slope << endl;
	cout << "(double*)dp points to: " << *dp << endl;
	/* const_cast is used for deconst, work on the same type */
	/* only const_cast can do the deconst work, any other named cast will generate compile error when it tries to deconst */
	const char *str = "C++";
	char *p = const_cast<char*>(str);	// pointer p pointed to a writeable memory now. p must be of same type with str only without const prefix
	cout << "(const char*)str points to: " << str << endl;
	cout << "(char*)p points to: " << p << endl;
	p = "C";
	cout << "(char*)p points to modified: " << p << endl;
	cout << "(const char*)str points to: " << str << endl;
	/* reinterpret_cast low level cast, will not change anything, only interpret one data type in another form */
	/* best example is to reintepret_cast any data type for raw binary I/O */
	/* will not show example here */
}