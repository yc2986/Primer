#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

static void printVec(vector<int> num);
static void initialization();
static void addElement();
static void basicOperation();
static void bucketCount();

int main() {
	cout << "[initialization]" << endl;
	initialization();
	cout << endl;

	cout << "[push_back]" << endl;
	addElement();
	cout << endl;

	cout << "[basic operation]" << endl;
	basicOperation();
	cout << endl;

	cout << "[bucket count]" << endl;
	bucketCount();

	return 0;
}

static void printVec(vector<int> num) {
	for (auto i : num)
		cout << i << " ";
	cout << endl;
}

static void initialization() {
	/*
	 * vector can be default declared to empty
	 */
	const int n = 10, val = 2;

	vector<string> svec;		// default initialization, no element in svec
	vector<int> ivec1(n);		// ivec1 has 10 copy of default int, 0
	vector<int> ivec2(ivec1);	// copy constructor
	vector<int> ivec3 = ivec1;	// copy constructor
	vector<int> ivec4(n, val);	// ivec4 has 10 copy of 2
	vector<int> ivec5{1,2,3,4}; // list constructor
	vector<int> ivec6 = {1,2,3};// another list constructor

	cout << "no element in svec? " << svec.empty() << endl;
	cout << "default 10 elements in ivec1" << endl;
	printVec(ivec1);
	cout << "ivec2 copy ivec1 for constructor" << endl;
	printVec(ivec2);
	cout << "ivec3 copy ivec1 as well" << endl;
	printVec(ivec3);
	cout << "ivec4 initialized by 10 copy of 2" << endl;
	printVec(ivec4);
	cout << "ivec5 list initalized" << endl;
	printVec(ivec5);
	cout << "ivec6 list initalized" << endl;
	printVec(ivec6);
}

static void addElement() {
	vector<int> ivec;	// empty
	cout << "no element in ivec? " << ivec.empty() << endl;
	for (int i = 0; i < 10; i++)
		ivec.push_back(i);	// adding
	cout << "no element in ivec? " << ivec.empty() << endl;
	cout << "elements in ivec: " << endl;
	printVec(ivec);
}

static void basicOperation() {
	vector<int> ivec1 = {1, 2, 3, 4, 5};
	auto size = ivec1.size();
	cout << "size of ivec1: " << size << endl;
	vector<int> ivec2 = {1, 2, 3, 4, 5};
	cout << "ivec1: " << endl;
	printVec(ivec1);
	cout << "ivec2: " << endl;
	printVec(ivec2);
	cout << "ivec1 == ivec2 ? " << (ivec1 == ivec2) << endl;
	ivec2.push_back(6);
	cout << "ivec2 change to" << endl;
	printVec(ivec2);
	cout << "ivec1 < ivec2 ? " << (ivec1 < ivec2) << endl;
	ivec1[4] = 6;
	cout << "ivec1 change to" << endl;
	printVec(ivec1);
	cout << "ivec1 > ivec2 ? " << (ivec1 > ivec2) << endl;
}

static void bucketCount() {
	vector<int> bucket(11);
	vector<int> arr;
	int n;
	cout << "Please type in number between 0 to 100 (0, 100 included), CTRL-D to break." << endl;
	while (cin >> n)
		arr.push_back(n);
	for (auto i : arr)
		bucket[i / 10]++;
	for (auto i : bucket)
		cout << i << " ";
	cout << endl;
}