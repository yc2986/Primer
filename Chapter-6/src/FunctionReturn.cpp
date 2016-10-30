#include <iostream>
#include <string>
#include <vector>

using namespace std;

static void swap(int &a, int &b);
static vector<string> errorMessage(const int errorCode);
static int& head(vector<int> &a);
static int& tail(vector<int> &a);
static unsigned factorial(const unsigned n);

int main() {
	cout << "[void return]" << endl;
	int a = 0, b = 1;
	cout << "a = " << a << ", b = " << b << endl;
	cout << "swap(a, b)" << endl;
	swap(a, b);
	cout << "a = " << a << ", b = " << b << endl;
	cout << endl;

	cout << "[value return]" << endl;
	cout << "error 0" << endl;
	for (auto &m : errorMessage(0))
		cout << m << endl;
	cout << "error 1" << endl;
	for (auto &m : errorMessage(1))
		cout << m << endl;
	cout << "error 2" << endl;
	for (auto &m : errorMessage(2))
		cout << m << endl;
	cout << endl;

	cout << "[reference return]" << endl;
	vector<int> arr = { 1, 2, 3, 4, 5 };
	cout << "arr = { ";
	for (auto &n : arr)
		cout << n << " ";
	cout << "}" << endl;
	cout << "arr = { ";
	head(arr) = 10;		// modify first element
	tail(arr) = 50; 	// modify last element
	for (auto &n : arr)
		cout << n << " ";
	cout << "}" << endl;
	cout << endl;

	cout << "[recursion return]" << endl;
	cout << "factorial(0) = " << factorial(0) << endl;
	cout << "factorial(1) = " << factorial(1) << endl;
	cout << "factorial(2) = " << factorial(2) << endl;
	cout << "factorial(3) = " << factorial(3) << endl;
	cout << "factorial(4) = " << factorial(4) << endl;
	cout << "factorial(5) = " << factorial(5) << endl;
	cout << endl;

	return 0;
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

vector<string> errorMessage(int errorCode) {
	switch (errorCode) {
		case 0 : return {"this is error code"}; break;
		case 1 : return {"404 not found"}; break;
		case 2 : return {"500 internal server error", "Debug your server code"}; break;
		default: return {}; break;
	}
}

int& head(vector<int> &a) {
	/* return reference by lvalue */
	return a[0];
}

int& tail(vector<int> &a) {
	/* return reference by lvalue */
	return a[a.size() - 1];
}

unsigned factorial(const unsigned n) {
	/* all the recursive function must have a non recursive return */
	if (n <= 1)
		return n;
	else
		return n * factorial(n - 1);
}