#include <stdexcept>
#include <iostream>

using namespace std;

static void exceptionThrower();

int main() {
	try {
		exceptionThrower();
	}
	catch(runtime_error &e) {
		cout << e.what() << endl;
	}
	return 0;
}

void exceptionThrower() {
	cout << "type in a integer number, any number except 0 will throw a runtime exception." << endl;
	int num;
	cin >> num;
	if (num != 0)
		throw runtime_error("error: your input is not 0, exception throwed");
	else
		cout << "you entered 0, good job" << endl;
}