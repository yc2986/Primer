#include <iostream>
#include <vector>

using namespace std;

static void operationOrder();

int main() {
	cout << "[order]" << endl;
	operationOrder();
	cout << endl;
	return 0;
}

static void operationOrder() {
	/*
	 * C++ operators have different precedence
	 * operators with higher precedence will be executed first
	 * operators with same precedence will execute according to associativity
	 */
	cout << "6 + 3 * 4 / 2 + 2 = " << (6 + 3 * 4 / 2 + 2) << endl;	// expected to be 14
	vector<int> arr = {0, 5};
	cout << "arr[0] = " << *arr.cbegin() << endl;
	cout << "arr[0] + 1 = " << *arr.begin() + 1 << endl;
	/*
	 * order of evaluation
	 * only 4 operators guarentee the operation order of expressions
	 * they are "&&", "||", "?:", ","
	 * other operator will generate undefined behavior if one tries to modify a same object twice on its left and right
	 */
	int i = 0;
	// cout << i << " " << ++i << endl;		// this will generate undefined behavior
	if (++i > 1 && ++i > 0)
		;
	cout << "(++i > 1 && ++i > 0), expected only ++i > 1 be executed: " << i << endl;	// expected i = 1
	i = 0;
	if (++i > 1 || ++i > 0)
		;
	cout << "(++i > 1 || ++i > 0), expected two ++i: " << i << endl;	// expected i = 2
}