#include <iostream> 
#include <algorithm> 
#include <array> 
#include <iterator> 
#include <string> 
#include <vector>
#include <list>
#include <forward_list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;  // If you omit this, then you have to refer to classes imported from std as std::, e.g., std::cout, std:array etc.

///============================================= LISTS ================================================
/// A list or sequence is an abstract data type that represents a countable number of ORDERED values, 
/// where the same value may occur more than once.If the same value occurs multiple times, 
/// each occurrence is considered a distinct item. Unlike fixed-size arrays, lists grow and shrink dynamically.
/// Typical list operations are: insert, 
/// 
/// C++ offers 3 different implementation of lists:
/// 1. Using arrays (std::vector) and (std::deque)
/// 2. Using singly-linked lists (std::forward_list)
/// 3. Using doubly-linked lists (std::list)
///
void PrintList(std::vector<int> &v) {
	cout << "Vector elements in forward order: ";
#if 0
	for (auto iter : v) {
		cout << iter << ", ";
	} //end-for
#else
	for (auto iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << ", ";
#endif
	cout << endl;
} //end-PrintList

void PrintList(std::list<int> &l) {
	cout << "List elements in forward order: ";
	for (auto iter : l) {
		cout << iter << ", ";
	} //end-for
	cout << endl;
} //end-PrintList

void ListExamples() {
#if 0
	std::vector<int> v1; // A vector of initial capacity 0 and size=0
	cout << "v1.size(): " << v1.size() << ", v1.capacity(): " << v1.capacity() << endl;

	v1.reserve(10);  // Increase the capacity to 10 elements
	cout << "v1.size(): " << v1.size() << ", v1.capacity(): " << v1.capacity() << endl;

	cout << "Appending 3" << endl;
	v1.push_back(3); // Append at the end. List content: 3

	cout << "Appending 2" << endl;
	v1.push_back(2); // Append at the end. List content: 3, 2

	cout << "Appending 5" << endl;
	v1.push_back(5); // Append at the end. List content: 3, 2, 5

	cout << "Appending 7" << endl;
	v1.push_back(7); // Append at the end. List content: 3, 2, 5, 7

	cout << "Appending 1" << endl;
	v1.push_back(1); // Append at the end. List content: 3, 2, 5, 7, 1

	cout << "Appending 9" << endl;
	// Can also do the following to append. List content: 3, 2, 5, 7, 1, 9
	v1.insert(v1.end(), 9);

	cout << "Inserting 6 at the beginning" << endl;
	// Insert 6 at the beginning: List content: 6, 3, 2, 5, 7, 1, 9
	v1.insert(v1.begin(), 6);

	// Print the elements in forward order
	cout << "v1.size(): " << v1.size() << ", v1.capacity(): " << v1.capacity() << endl;
	PrintList(v1);

	// Access an element using [] without bounds check, and using at(index) with bounds check
	cout << "v1[2]: " << v1[2] << ", v1.at(5): " << v1.at(5) << endl;

	//v1[8] = 9; // This is out of bounds but not checked. So, the program will crash here if we run this line

	try {
		int x = v1.at(8);  // with "at", an exception is thrown if we access an out of bounds element
	} catch (std::exception e) {
		cout << "Error accessing v1.at(8): " << e.what() << endl;
	} //end-catch

	cout << "First Element: " << v1.front() << ", last element: " << v1.back() << endl;

	// Delete the last element
	cout << "After deleting the last element: " << endl;
	v1.pop_back();
	cout << "v1.size(): " << v1.size() << ", v1.capacity(): " << v1.capacity() << endl;
	PrintList(v1);

	cout << "After deleting the element at index 3:" << endl;
	v1.erase(std::next(v1.begin(), 3));
	PrintList(v1);

	// Insert at an arbitrary index
	cout << "After inserting 4 at index 2:" << endl;
	v1.insert(std::next(v1.begin(), 2), 4);
	PrintList(v1);

	// Print the elements in reverse order using an iterator
	cout << "vector elements in reverse direction: ";
	for (auto iter = v1.rbegin(); iter != v1.rend(); iter++) {
		cout << *iter << ", ";
	} //end-for
	cout << "\n";
#endif

#if 1
	/// Linked list also implement the list ADT, but does not allow random access to an element as in vector.
	/// That is, it is not possible to access a random element in a list using [] and at(index) methods.
	cout << "--------------------Linked Lists------------------------" << endl;
	cout << "Create a std::list" << endl;
	std::list<int> l1;

	cout << "l1.size(): " << l1.size() << endl;

	cout << "Appending 3" << endl;
	l1.push_back(3); // Append at the end. List content: 3

	cout << "Appending 2" << endl;
	l1.push_back(2); // Append at the end. List content: 3, 2

	cout << "Appending 5" << endl;
	l1.push_back(5); // Append at the end. List content: 3, 2, 5

	cout << "Appending 7" << endl;
	l1.push_back(7); // Append at the end. List content: 3, 2, 5, 7

	cout << "Appending 1" << endl;
	l1.push_back(1); // Append at the end. List content: 3, 2, 5, 7, 1

	cout << "Appending 9" << endl;
	// Can also do the following to append. List content: 3, 2, 5, 7, 1, 9
	l1.insert(l1.end(), 9);

	cout << "Inserting 6 at the beginning" << endl;
	// Insert 6 at the beginning: List content: 6, 3, 2, 5, 7, 1, 9
	l1.push_front(6);

	// Print the elements in forward order
	cout << "l1.size(): " << l1.size() << endl;
	PrintList(l1);

	cout << "First Element: " << l1.front() << ", last element: " << l1.back() << endl;

	// Delete the last element
	cout << "After deleting the last element:" << endl;
	l1.pop_back();
	cout << "l1.size(): " << l1.size() << endl;
	PrintList(l1);

	// Delete the first element
	cout << "After deleting the first element:" << endl;
	l1.pop_front();
	cout << "l1.size(): " << l1.size() << endl;
	PrintList(l1);

	// Delete an element at an arbitrary position
	cout << "After deleting the element at index 3:" << endl;
	l1.erase(std::next(l1.begin(), 3));
	PrintList(l1);

	// Insert an element at an arbitrary position
	cout << "After inserting 4 at index 2:" << endl;
	
	l1.insert(std::next(l1.begin(), 2), 4);
	PrintList(l1);

	// Print the elements in reverse order using an iterator
	cout << "vector elements in reverse direction: ";
	for (auto iter = l1.rbegin(); iter != l1.rend(); iter++) {
		cout << *iter << ", ";
	} //end-for
	cout << "\n";
#endif
} // end-ListExamples

