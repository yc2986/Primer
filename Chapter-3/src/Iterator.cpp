#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::distance;

static void basicOperation();
static int binarySearch(vector<int> &arr, const int target);

int main() {
	cout << "[basic operation]" << endl;
	basicOperation();
	cout << endl;

	vector<int> arr = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
	cout << "[binary search]" << endl;
	cout << "binary search in arr: ";
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
	cout << "[case 1] target = 0,  index = " << binarySearch(arr, 0)  << endl;
	cout << "[case 2] target = 9,  index = " << binarySearch(arr, 9)  << endl;
	cout << "[case 3] target = 16, index = " << binarySearch(arr, 16) << endl;
	cout << "[case 4] target = 8,  index = " << binarySearch(arr, 8)  << endl;
	cout << "[case 5] target = -8, index = " << binarySearch(arr, -8) << endl;


	return 0;
}

static void basicOperation() {
	string sentence = "i am your father!";
	cout << "original sentence: " << sentence << endl;
	if (!sentence.empty()) {
		// upper case first character
		auto it = sentence.begin();	// it is of type string::iterator
		*it = toupper(*it);	// dereference iterator return reference of the memory iterator point to
	}
	cout << "sentence change to: " << sentence << endl;

	sentence = "you are a programmer!";
	cout << "original sentence: " << sentence << endl;
	// uppercase first word
	for (auto it = sentence.begin(); it != sentence.end() && !isspace(*it); it++)
		*it = toupper(*it);
	cout << "sentence change to: " << sentence << endl;

	// uppercase all words
	for (auto it = sentence.begin(); it != sentence.end(); it++)
		*it = toupper(*it);
	cout << "sentence change to: " << sentence << endl;

	// vector::iterator
	vector<int> arr(10);
	// initialization
	for (auto it = arr.begin(); it != arr.end(); it++)
		*it = (int)(it - arr.begin());
	// using const iterator for read-only operation
	cout << "elements in arr: " << endl;
	for (auto it = arr.cbegin(); it != arr.cend(); it++)
		cout << *it << " ";
	cout << endl;
}

static int binarySearch(vector<int> &arr, const int target) {
	// return -1 if array is empty or target is out of range
	if (arr.empty() || target < arr.front() || target > arr.back())
		return -1;
	auto start = arr.begin(), end = arr.end();
	while (start != end) {
		auto mid = start + (end - start) / 2;
		if (target == *mid)
			return distance(arr.begin(), mid);
		else if (target < *mid)
			end = mid;
		else
			start = mid + 1;
	}
	return -1;
}