#include <algorithm> 
#include <array> 
#include <iostream> 
#include <iterator> 

using namespace std;  // If you omit this, then you have to refer to classes imported from std as std::, e.g., std::cout, std:array etc.

///============================================= ARRAYS ================================================
/// An array is a fixed-size contiguous set of elements. C++ offers two types of fixed-size arrays
/// 1. C-style arrays with no bounds checking
/// 2. std:array class that allows bounds checking with "at" operator
///
void ArrayExamples() {
	///---------------------- C-style arrays ---------------------------------------------------------
	// C-style static fixed-size array
#define N 5
	int A[N] = { 1, 2, 3, 4, 5 };

	int sum = 0;
	for (int i = 0; i < N; i++) sum += A[i];
	cout << "Sum of the elements in A: " << sum << endl;

	// C-style dynamic fixed-size array
	int *B = new int[N];

	for (int i = 0; i < N; i++) B[i] = i + 1;  // Initialize
	sum = 0;
	for (int i = 0; i < N; i++) sum += B[i];
	cout << "Sum of the elements in B: " << sum << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	delete[] B; // Must explicitly deallocate the space used by C-style dynamic arrays

	///------------------------------------ std:array container -------------------------------------
	// The problem with C-style arrays is that it does not check for "out of bounds" error checking.
	// With std:array class, it is possible have the class check for "out of bounds" errors.
	// It is also possible to walk through the array elements using an iterator
	// This in fact corresponds to Java arrays
	array<int, N> C = { 1, 2, 3, 4, 5 };

	sum = 0;
	for (int i = 0; i < N; i++) sum += C[i];                     // With the [] operator, no bounds checking is performed!
	cout << "Sum of the elements in C: " << sum << endl;
	cout << "No of elements in C: " << C.size() << endl;
	cout << "C.front(): " << C.front() << ", Same as C[0]: " << C[0] << endl;
	cout << "C.back(): " << C.back() << ", Same as C[C.size()-1]: " << C[C.size() - 1] << endl;

	// If you want array class to do "bounds checking", then you need to use .at(index) method to access the array elements
	cout << "C.at(2): " << C.at(2) << endl;

	try {
		int x = C.at(5); // Array elements are indexed 0..4. This will generate an "out of bounds" exception
	}
	catch (exception& e) {
		cout << "Trying to access C.at(5): " << e.what() << endl;
	} //end-catch

	  // Access the array elements using an iterator
	cout << "Here are the array elements in forward direction: ";
	for (auto iter = C.begin(); iter != C.end(); iter++) {
		cout << *iter << ", ";
	} //end-for
	cout << "\n";

	cout << "Here are the array elements in forward direction: ";
	for (auto iter : C) {   // This is an alternative looping technique
		cout << iter << ", ";
	} //end-for
	cout << "\n";

	cout << "Here are the array elements in reverse direction: ";
	for (auto iter = C.rbegin(); iter != C.rend(); iter++) {
		cout << *iter << ", ";
	} //end-for
	cout << "\n";
} //end-ArrayExamples

