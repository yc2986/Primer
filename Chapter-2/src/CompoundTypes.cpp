/*
 * A compound type is a type that is defined in terms of another type.
 * C++ has several compound types.
 * Here is 2 of them: reference & pointer.
 */

#include <iostream>

using namespace std;

static void reference();
static void pointer();

int main() {
	cout << "[reference]" << endl;
	reference();
	cout << endl;
	cout << "[pointer]" << endl;
	pointer();
	return 0;
}

static void reference() {
	/*
	 * A reference is the "alias" of another object.
	 * A reference is not a object!
	 * A reference must be initialized when it is defined!
	 * A reference cannot exist without bind to another object!
	 * A reference must be initialized by an object, but not a const!
	 * A reference can only bind to one object, no way to bind it to another object!
	 */
	 int val = 1024;
	 cout << "val = " << val << endl;
	 int &refVal = val;	// define and initialize refVal with int object val.
	 cout << "reference of val = " << refVal << endl;
	 int val2 = refVal;	// refVal is the alias of val, this equals to "int val2 = val;"
	 cout << "val2 should be same as val, val2 = " << val2 << endl;
	 refVal = 512;		// modify refVal equals modify val
	 cout << "refVal is changed to: " << refVal << endl;
	 cout << "val is also changed to: " << val << endl;
}

static void pointer() {
	/*
	 * A pointer is a compound type that points to another type.
	 * A pointer is an object itself!
	 * A pointer can be assigned and copied!
	 * A pointer can point to many different object in its lifetime.
	 * A pointer can be defined withou initialized, but this is harmful.
	 * A pointer must point to the object that matched the type when it is defined!
	 */
	 int val = 1024;
	 double val_d = 1024.5;
	 cout << "val = " << val << endl;
	 int *p = &val;		// define the pointer and point it to the address of val object.
	 					// here & operator is used as "address-of" operator instead of reference.
	 cout << "int pointer p points to object: " << *p << endl;
	 double *ptr = &val_d;
	 // double *ptr = &val; //is invalid because val's type doesn't match double.
	 cout << "double pointer p points to object: " << *ptr << endl;
	 int *p_null = nullptr;	// define a pointer and initialize it to nullptr (point to nothing)
	 int *p_0 = 0;			// define a pointer and initialize it to 0 (point to nothing)
	 if (!p_null)
	 	cout << "pointer p_null is defined and initialized but is pointing to nothing." << endl;
	 if (!p_0)
	 	cout << "pointer p_0 is defined and initialized but is pointing to nothing." << endl;
	 *p = 512;			// pointer value assignment
	 cout << "pointer p is assigned with value: " << *p << endl;
	 p_null =  p;
	 cout << "pointer p_null point to the same object as p, value is: " << *p_null << endl;
	 if (!p_null)
	 	cout << "this sentence will not be printed!" << endl;
	 p_null = nullptr;	// set p_null point to nothing again.
	 if (!p_null)
	 	cout << "pointer p_null is set to point to nothing again!" << endl;
	 /*
	  * Void pointer should be used to deal with memory as memory.
	  * Void pointer should not be used to access object stored in that memory.
	  */
	 void *p_v1 = &val;	// void pointer can point to any type
	 cout << "void pointer point to int type: " << *static_cast<int*>(p_v1) << endl;
	 void *p_v2 = &val_d;
	 cout << "void pointer point to double type: " << *static_cast<double*>(p_v2) << endl;
}