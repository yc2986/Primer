#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

static void initialization();
static void pointerArray();
static void interface();
static void multiDimensionsArray();

int main () {
	cout << "[initialization]" << endl;
	initialization();
	cout << endl;

	cout << "[pointer array]" << endl;
	pointerArray();
	cout << endl;

	cout << "[interface]" << endl;
	interface();
	cout << endl;

	cout << "[multi dimension]" << endl;
	multiDimensionsArray();

	return 0;
}

static void initialization() {
	/*
	 * an array can only be initialized to known size, no variable size
	 * an array can be list initialized
	 * an array cannot be copy initialized
	 * char array is special
	 */
	const unsigned size1 = 3;
	constexpr unsigned size2 = 4;
	const unsigned size3 = 5;
	int arr1[size1] = {0, 1, 2};	// list initialization
	int arr2[] = {0, 1, 2, 3};	 	// list initialization without explicit size declare
	string strs[size2] = {"This", "is", "a", "string"};
	int arr3[size3] = {0, 1, 2};
	char c1[] = {'C', '+', '+'};	// no null at the end
	char c2[] = {'C', '+', '+'};	// explicit null at the end
	char c3[] = "C++"; 				// automatic null at end
	
	/*
	 * complicated array declarations
	 */
	int *ptr[2];	// 2 pointers to int array
	(void) ptr;
	// int &ptr[2];	// 2 reference to int array, invalid because reference need to be initialized ASAP
	int (*Parray)[3] = &arr1;	// pointer to int[3] array
	int (&arrRef)[3] = arr1;	// referecne to int[3] array

	cout << "array1 with size " << size1 << ": ";
	for (auto i : arr1)
		cout << i << " ";
	cout << endl;
	cout << "array2: ";
	for (auto i : arr2)
		cout << i << " ";
	cout << endl;
	cout << "array3 with size " << size2 << ": ";
	for (auto i : arr3)
		cout << i << " ";
	cout << endl;
	for (auto str : strs)
		cout << str << " ";
	cout << endl;
	cout << "c1: ";
	cout << c1 << endl;	// see what happend here
	cout << "c2: ";
	cout << c2 << endl;	// char array
	cout << "c3: ";
	cout << c3 << endl; // yet another char array
	cout << "Parray, pointer to int[3]: ";
	for (auto i : *Parray)
		cout << i << " ";
	cout << endl;
	cout << "arrRef, reference to int[3]: ";
	for (auto i : arrRef)
		cout << i << " ";
	cout << endl;
}

static void pointerArray() {
	int arr[] = {1, 2, 3, 4, 5};	// size of 5
	auto ptr1(arr);	// ptr1 has type int* that points to &arr[0]
	cout << "pointer to arr: " << endl;
	for (unsigned int i = 0; i < 5; i++)
		cout << *(ptr1 + i) << " ";
	cout << endl;
	decltype(arr) arr1 = {6, 7, 8, 9, 10};	// arr1 has type int[5]
	cout << "array of int[10]" << endl;
	for (unsigned int i = 0; i < 5; i++)
		cout << arr1[i] << " ";
	cout << endl;
	cout << "array iterator for int[10]" << endl;
	for (auto it = begin(arr1); it != end(arr1); it++)
		cout << *it << " ";
	cout << endl;
}

static void interface() {
	string word("hello world!");	// initialize string with c style string literal
	const char *str = word.c_str();	// assign c char array by string
	int arr[5] = {0, 1, 2, 3, 4};
	vector<int> vec(begin(arr), end(arr));	// initialize vector using array iterators
	vector<int> vec_part(begin(arr), begin(arr) + 3);	// partial initialization
	cout << "C++ string: " << word << endl;
	cout << "C char array: " << str << endl;
	cout << "size 5 vector: ";
	for (auto it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "size 3 vector: ";
	for (auto it = vec_part.cbegin(); it != vec_part.cend(); it++)
		cout << *it << " ";
	cout <<endl;
}

static void multiDimensionsArray() {
	int arr_2d_0[2][3] = {0};					// initialize everything to 0
	int arr_2d_1[2][3] = {
		{0, 1, 2},
		{3, 4, 5}
	};											// nested braces initialization
	int arr_2d_2[2][3] = {0, 1, 2, 3, 4, 5};	// equivalant to the nested braces init
	int arr_2d_3[2][3] = {0, 1, 2};				// initialize first row and leave second row to be 0
	
	cout << "all 0 array: " << endl;
	/* range iterate through 2d array */
	for (const auto &row : arr_2d_0) {
		for (auto &col : row)
			cout << col << " ";
		cout << endl;
	}
	cout << "nested bracket initialized array: " << endl;
	/* range iterate through 2d array */
	for (const auto &row : arr_2d_1) {
		for (auto &col : row)
			cout << col << " ";
		cout << endl;
	}
	cout << "flat bracket initialized array: " << endl;
	/* range iterate through 2d array */
	for (const auto &row : arr_2d_2) {
		for (auto &col : row)
			cout << col << " ";
		cout << endl;
	}
	cout << "partly initialized array: " << endl;
	/* range iterate through 2d array */
	for (const auto &row : arr_2d_3) {
		for (auto &col : row)
			cout << col << " ";
		cout << endl;
	}
}