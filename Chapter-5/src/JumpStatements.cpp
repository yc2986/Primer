#include <iostream>
#include <vector>

using namespace std;

static void breakStatements();
static void continueStatements();
static void gotoStatements();

int main() {
	cout << "[break statements]" << endl;
	breakStatements();
	cout << endl;

	cout << "[continue statements]" << endl;
	continueStatements();
	cout << endl;

	cout << "[goto statements]" << endl;
	gotoStatements();
	return 0;
}

void breakStatements() {
	vector<int> vec = {1,2,3,4,5};
	cout << "break the loop from third element: " << endl;
	for (unsigned i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
		if (i == 2)
			break;
	}
	cout << endl;
	cout << "loop broken" << endl;
}

void continueStatements() {
	vector<int> vec = {1,2,3,4,5};
	cout << "ignore until the third element: " << endl;
	for (unsigned i = 0; i < vec.size(); i++) {
		if (i < 2)
			continue;
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << "continue executed" << endl;
}

void gotoStatements() {
	vector<int> vec = {1,2,3,4,5};
	cout << "directly goto end label at third element: " << endl;
	for (unsigned i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
		if (i == 2)
			goto end;
	}
	cout << "you will not see me" << endl;
end:
	cout << endl;
}