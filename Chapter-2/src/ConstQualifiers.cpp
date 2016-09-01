/*
 * We make a variable unchangeable by defining the variable's type as const
 * Because we can't change the value of a const after we create it, it must be initialized.
 * 
 */

#include <iostream>

using namespace std;

static void initialize();
static void constReference();
static void constPointer();

int main() {
	cout << "[initialization]" << endl;
	initialize();
	cout << endl;

	cout << "[reference to const]" << endl;
	constReference();
	cout << endl;

	cout << "[const pointer]" << endl;
	constPointer();
	cout << endl;
	
	return 0;
}

static void initialize() {
	// Initialize by literal
	const int bufSize = 512;
	cout << "constant buffer size is: " << bufSize << endl;
	/*
	 * Cannot do this:
	 *     const int bufSize;
	 *     bufSize = 512;
	 */
	 // Initialize by object
	 int i = 512;
	 const int bufSize1 = i;
	 cout << "another constant buffer size is: " << bufSize1 << endl;
}

static void constReference() {
	/*
	 * Reference is always bind to an object so that each reference is a const reference
	 * Here we refer reference to const as "const reference"
	 */
	 // const reference to an const object
	 const int val = 16;
	 const int &refVal = val;
	 cout << "reference to val has value: " << refVal << endl;
	 /*
	  * Cannot do:
	  *     refVal = 24;	// because refVal is reference to a const int
	  */
	  // initialize const reference use another const reference
	  const int &refVal1 = refVal;
	  cout << "same reference as refVal is: " << refVal1 << endl;
	  const int &refVal2 = refVal * 2; 
	  cout << "double reference for refVal is: " << refVal2 << endl;
	  // initialize const reference use const literal
	  const int &refVal3 = 16;
	  cout << "const int reference initialized by number: " << refVal3 << endl;
}

static void constPointer() {
	/*
	 * Pointer is object.
	 * const pointer means a pointer whose address is const
	 * pointer to const means a pointer point to a piece of memory where store const object
	 */
	 // const pointer
	 int val = 16;
	 int *const p = &val;
	 cout << "const pointer p point to variable int: " << *p << endl;
	 // change content inside const pointer
	 *p = 24;
	 cout << "const pointer p point to another int: " << *p << endl;
	 const int val1 = 8;
	 // pointer to const
	 const int *ptr = &val1;
	 cout << "pointer to const int ptr point to constant: " << *ptr << endl;
	 // point to another const int
	 const int val2 = 4;
	 ptr = &val2;
	 cout << "pointer to const int ptr point to another constant: " << *ptr << endl;
}