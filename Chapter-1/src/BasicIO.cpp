#include <iostream>
/*
 * Program 2:
 * Simple I/O functions
 */
using namespace std;

int main() {
	int v1 	= 0; 
	int	v2 	= 0;												// Initialize v1, v2 to take user input.
	cout 	<< "Enter two integers:" << endl;
	cin 	>> v1 >> v2;										// Take user input
	cout 	<< v1 << " + " << v2 << " = " << v1 + v2 << endl;	// Print sum of v1, v2
	cout 	<< v1 << " x " << v2 << " = " << v1 * v2 << endl; 	// Print product of v1, v2
	return 0;
}