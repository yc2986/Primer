#include <iostream>
#include <string>
#include <vector>

using namespace std;

static void whileStatement();
static void forStatement();

int main() {
	cout << "[while statement]" << endl;
	whileStatement();
	cout << endl;

	cout << "[for statement]" << endl;
	forStatement();
	return 0;
}

void whileStatement() {
	unsigned count = 0;
	unsigned i = 0;
	while (++i < 5)
		count++;
	cout << "while loop execute after condition meet, count = " << count << endl;
	count = 0;
	i = 0;
	do {
		count++;
	}
	while (++i < 5);
	cout << "do while loop execute before condition meet, count = " << count << endl;
}

void forStatement() {
	vector<int> vec = {1,2,3,4,5};
	cout << "traditional for iterate through vector: " << endl;
	for (unsigned i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	cout << "double vector value using range base for: " << endl;
	for (auto &v : vec)
		v *= 2;
	for (auto &v : vec)
		cout << v << " ";
	cout << endl;
}