#include <iostream>

using namespace std;

static void typeAlias();
static void autoType();
static void declType();

int main() {
	cout << "[type aliasing]" << endl;
	typeAlias();
	cout << endl;

	cout << "[auto]" << endl;
	autoType();
	cout << endl;

	cout << "[decltype]" << endl;
	declType();
	return 0;
}

static void typeAlias() {
	/*
	 * legacy way of type aliasing
	 */
	typedef double wages;	// Aliasing double as wages
	wages base = 200.5;		// declare a wages object
	wages *p = &base;		// declare a wages pointer object

	/*
	 * c++11 way of type aliasing
	 */
	using workHours = int;
	workHours day = 8;
	workHours *daily = &day;

	cout << "daily work hour as int: " << day << endl;
	cout << "daily work hour pointer: " << *daily << endl;

	cout << "daily base wage as double: " << base << endl;
	cout << "daily base wage pointer: " << *p << endl;
}

static void autoType() {
	int val1 = 10;
	int val2 = 20;
	const int val_const = 30;
	auto sum = val1 + val2;
	auto divide = double(val1) / val2;
	auto *p = &val1;
	auto ptr = &val1; 	// auto as int*
	auto &ref = val2;	
	const auto val = val1;
	auto val_var = val_const;	// auto will not get top-level const

	cout << "auto iterator" << endl;
	for (auto i = 0; i < 5; i++)
		cout << i << " ";
	cout << endl;

	cout << "auto sum result for two int: " << sum << endl;
	cout << "auto divide result for double: " << divide << endl;
	cout << "auto as int to val1: " << *p << endl;
	cout << "auto as int* to val1: " << *ptr << endl;
	cout << "auto reference to val2: " << ref << endl;
	cout << "const auto initialized by val1: " << val << endl;
	cout << "auto initialized by const int: " << val_var << endl;
	val_var = 40;	// this is a int rather than const int so it can be changed
	cout << "auto initialized by const int change to: " << val_var << endl;
}

static void declType() {
	int val = 20;
	const int *p = &val;
	decltype(val) val_copy;			// int
	val_copy = val;
	decltype(&val) ptr = nullptr;	// int*
	ptr = &val;
	decltype(p) ptr_const = &val;	// const int*
	decltype(val + 2.5) val_double = 3.5;	// double
	cout << "decltype for int: " << val_copy << endl;
	cout << "decltype for int pointer: " << *ptr << endl;
	cout << "decltype for double: " << val_double << endl;
	//*ptr_const = 30;	// wrong because top-level const is copied
	cout << "const int pointer: " << *ptr_const << endl;
}