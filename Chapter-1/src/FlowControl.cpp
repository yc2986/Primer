#include <iostream>

using namespace std;

static void while_sum(int start, int end);
static void for_sum(int start, int end);
static void continuous_sum();
static void target_counter();

int main() {
	/*
	 * Summation
	 */
	int start, end;
	cout << "[1] Please enter start, end values for summation." << endl;
	cin  >> start >> end;
	while_sum(start, end);
	
	cout << endl;
	cout << "[2] Please enter start, end values for summation." << endl;
	cin >> start >> end;
	for_sum(start, end);
	cout << endl;

	/*
	 * Continuous cin
	 */
	continuous_sum();

	// Ignore a CTRL-d here
	cin.clear();
	cin.ignore(1, '\n');
	cin.ignore(1, cin.eof());
	

	cout << endl;

	/*
	 * If statement target counter
	 */
	target_counter();

	return 0;
}

static void while_sum(int start, int end) {
	int sum = 0;
	if (start > end)
		swap(start, end);
	cout << "Sum " << start << " to " << end << " equals ";
	while (start <= end)
		sum += start++;
	cout << sum << endl;
}

static void for_sum(int start, int end) {
	int sum = 0;
	if (start > end)
		swap(start, end);
	for (int i = start; i <= end; i++)
		sum += i;
	cout << "Sum " << start << " to " << end << " equals " << sum << endl;
}

static void continuous_sum() {
	cout << "[3] Please enter numbers for sum, type in non integer and enter to exit." << endl;
	int sum = 0, val = 0;
	cout << "Sum of:\n";
	while (cin >> val) {
		cin.clear();
		sum += val;
	}
	cout << "\nis " << sum << endl;
}

static void target_counter() {
	int count = 0, val = 0, target = 0;
	cout << "[4] Please enter the target number." << endl;
	cin  >> target;
	cout << "Among numbers:\n"; 
	while (cin >> val) {
		cin.clear();
		if (val == target)
			count++;
	}
	cout << "\n" << target << " appears " << count << " times." << endl;
}
