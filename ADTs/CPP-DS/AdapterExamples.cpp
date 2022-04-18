#include <iostream> 
#include <algorithm> 
#include <array> 
#include <iterator> 
#include <string> 
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
using namespace std;  // If you omit this, then you have to refer to classes imported from std as std::, e.g., std::cout, std:array etc.

///====================================== CONTAINER ADAPTERS ================================================
/// Container adapters are stack, queue (fifo-queue), and priority_queue (binary heap) 
///
void AdapterExamples() {
#if 0
	///--------------------------------- stack ----------------------------------------
	cout << "Creating a lilo stack..." << endl;

	stack<int> S;

	cout << "push(4)" << endl;
	S.push(4);

	cout << "push(3)" << endl;
	S.push(3);

	cout << "push(7)" << endl;
	S.push(7);

	cout << "push(1)" << endl;
	S.push(1);

	cout << "push(9)" << endl;
	S.push(9);
	cout << "Number of elements in the stack: " << S.size() << endl;
	cout << "Element at the top of the stack: " << S.top() << endl;
	cout << "Removing the top element of the stack." << endl;
	S.pop();
	cout << "Element at the top of the stack now: " << S.top() << endl;
	cout << "Is the stack empty? " << (S.empty()? "Yes" : "No") << endl;

	cout << "Removing the stack elements in order: ";
	while (!S.empty()) {
		cout << S.top() << ", ";
		S.pop();
	} //end-while
	cout << endl;
	cout << "Is the stack empty? " << (S.empty() ? "Yes" : "No") << endl;
	cout << "----------------------------------------------------------" << endl;
#endif

#if 0
	///------------------------ queue ---------------------------------
	cout << "Creating a fifo queue..." << endl;

	queue<int> Q;

	cout << "Enqueue(4)" << endl;
	Q.push(4);

	cout << "Enqueue(3)" << endl;
	Q.push(3);

	cout << "Enqueue(7)" << endl;
	Q.push(7);

	cout << "Enqueue(1)" << endl;
	Q.push(1);

	cout << "Enqueue(9)" << endl;
	Q.push(9);
	cout << "Number of elements in the queue: " << Q.size() << endl;
	cout << "Element at the front of the queue: " << Q.front() << endl;
	cout << "Removing the front element of the queue." << endl;
	Q.pop();
	cout << "Element at the front of the queue now: " << Q.front() << endl;
	cout << "Is the queue empty? " << (Q.empty() ? "Yes" : "No") << endl;

	cout << "Removing the queue elements in order: ";
	while (!Q.empty()) {
		cout << Q.front() << ", ";
		Q.pop();
	} //end-while
	cout << endl;
	cout << "Is the queue empty? " << (Q.empty() ? "Yes" : "No") << endl;
	cout << "----------------------------------------------------------" << endl;
#endif

#if 0
	/// Deque example
	cout << "Creating a deque..." << endl;
	deque<int> dq;

	cout << "push_back(4)" << endl;
	dq.push_back(4);

	cout << "push_back(7)" << endl;
	dq.push_back(7);

	cout << "push_front(9)" << endl;
	dq.push_front(9);

	cout << "push_front(11)" << endl;
	dq.push_front(11);

	cout << "Number of elements in the deque: " << dq.size() << endl;
	cout << "Element at the front of the deque: " << dq.front() << endl;
	cout << "Element at the end of the deque: " << dq.back() << endl;
	cout << "Removing the front element of the deque." << endl;
	dq.pop_front();
	cout << "Element at the front of the deque now: " << dq.front() << endl;

	cout << "Removing the last element of the deque." << endl;
	dq.pop_back();
	cout << "Element at the front of the deque now: " << dq.back() << endl;

	cout << "Is the deque empty? " << (dq.empty() ? "Yes" : "No") << endl;

	cout << "Removing the deque elements from the front end: ";
	while (!dq.empty()) {
		cout << dq.front() << ", ";
		dq.pop_front();
	} //end-while
	cout << endl;
	cout << "Is the deque empty? " << (dq.empty() ? "Yes" : "No") << endl;
	cout << "----------------------------------------------------------" << endl;
#endif

#if 0
	///------------------------ priority queue ---------------------------------
	cout << "Creating a max-heap..." << endl;
	priority_queue<int> H;

	cout << "Insert(4)" << endl;
	H.push(4);

	cout << "Insert(3)" << endl;
	H.push(3);

	cout << "Insert(7)" << endl;
	H.push(7);

	cout << "Insert(1)" << endl;
	H.push(1);

	cout << "Insert(9)" << endl;
	H.push(9);
	cout << "Number of elements in the heap: " << H.size() << endl;
	cout << "Element at the top of the heap: " << H.top() << endl;
	cout << "Removing the top element of the heap." << endl;
	H.pop();
	cout << "Element at the top of the heap now: " << H.top() << endl;
	cout << "Is the heap empty? " << (H.empty() ? "Yes" : "No") << endl;

	cout << "Removing the heap elements in order: ";
	while (!H.empty()) {
		cout << H.top() << ", ";
		H.pop();
	} //end-while
	cout << endl;
	cout << "Is the heap empty? " << (H.empty() ? "Yes" : "No") << endl;
	cout << "----------------------------------------------------------" << endl;
#endif

#if 1
	///----------------------------------------------------------
	cout << "Now creating a min-heap" << endl;
#if 1
	auto cmp = [](int left, int right) { return (left >= right); };
	std::priority_queue<int, std::vector<int>, decltype(cmp)> H2(cmp);
#else
	// Alternatively, you can use standard template classes less & greater to create a max/min heap
	// This is only possible after C++17
	std::priority_queue<int, std::vector<int>, std::greater<int>> H2;
#endif

	cout << "Insert(4)" << endl;
	H2.push(4);

	cout << "Insert(3)" << endl;
	H2.push(3);

	cout << "Insert(7)" << endl;
	H2.push(7);

	cout << "Insert(1)" << endl;
	H2.push(1);

	cout << "Insert(9)" << endl;
	H2.push(9);
	cout << "Number of elements in the heap: " << H2.size() << endl;
	cout << "Element at the top of the heap: " << H2.top() << endl;
	cout << "Removing the top element of the heap." << endl;
	H2.pop();
	cout << "Element at the top of the heap now: " << H2.top() << endl;
	cout << "Is the heap empty? " << (H2.empty() ? "Yes" : "No") << endl;

	cout << "Removing the heap elements in order: ";
	while (!H2.empty()) {
		cout << H2.top() << ", ";
		H2.pop();
	} //end-while
	cout << endl;
	cout << "Is the heap empty? " << (H2.empty() ? "Yes" : "No") << endl;
	cout << "----------------------------------------------------------" << endl;
#endif
} //end-AdapterExamples

