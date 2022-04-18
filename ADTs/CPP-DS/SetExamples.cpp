#include <stdio.h>
#include <iostream> 
#include <algorithm> 
#include <array> 
#include <iterator> 
#include <string> 
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;  // If you omit this, then you have to refer to classes imported from std as std::, e.g., std::cout, std:array etc.


///====================================== ASSOCIATIVE CONTAINERS: SET ================================================
/// Associative Containers: set, multiset [both O(logn)], unordered_set, unordered_multiset [both expected O(1)]
///
void PrintSet(std::set<int> &set1) {
	cout << "Set elements: ";
	for (auto iter : set1) {
		cout << iter << ", ";
	} //end-for
	cout << endl;
} //end-PrintSet

void PrintSet(multiset<int> &set1) {
	cout << "Set elements: ";
	for (auto iter : set1) {
		cout << iter << ", ";
	} //end-for
	cout << endl;
} //end-PrintSet

void PrintSet(std::unordered_set<int> &set1) {
	cout << "Set elements: ";
	for (auto iter : set1) {
		cout << iter << ", ";
	} //end-for
	cout << endl;
} //end-PrintSet

void PrintSet(unordered_multiset<int> &set1) {
	cout << "Set elements: ";
	for (auto iter : set1) {
		cout << iter << ", ";
	} //end-for
	cout << endl;
} //end-PrintSet

void SetExamples() {
	set<pair<int, string>> mySet;
	mySet.insert({ 3, "Ali" });
	mySet.insert({ 3, "Veli" });
	mySet.insert({ 3, "Cem" });

	for (auto iter : mySet)
		cout << iter.first << ", " << iter.second << endl;

	auto iter = mySet.find({ 3, "Veli" });
	cout << iter->first << ", " << iter->second << endl;


#if 0
	cout << "ordered set example..." << endl;

	set<int> os;

	cout << "Insert(4)" << endl;
	os.insert(4);

	cout << "Insert(3)" << endl;
	os.insert(3);

	cout << "Insert(7)" << endl;
	os.insert(7);

	cout << "Insert(1)" << endl;
	os.insert(1);

	cout << "Insert(9)" << endl;
	os.insert(9);

	cout << "Number of elements in the set: " << os.size() << endl;
	PrintSet(os);

	auto iter = os.find(7);
	if (iter != os.cend()) printf("The key found is: %d\n", *iter);
	else                   printf("7 does not exist in the set\n");

	iter = os.find(5);
	if (iter != os.cend()) printf("The key found is: %d\n", *iter);
	else                   printf("5 does not exist in the set\n");

	cout << "Erasing 7..." << endl;
	os.erase(7);
	PrintSet(os);

	cout << "Inserting 2..." << endl;
	os.insert(2);
	PrintSet(os);

	cout << "Inserting 2 again!" << endl;
	os.insert(2);
	PrintSet(os);
	cout << "--------------------------------------------------" << endl;
#endif

#if 0
	cout << "ordered multiset example..." << endl;
	multiset<int> oms;

	cout << "Insert(4)" << endl;
	oms.insert(4);

	cout << "Insert(3)" << endl;
	oms.insert(3);

	cout << "Insert(7)" << endl;
	oms.insert(7);

	cout << "Insert(1)" << endl;
	oms.insert(1);

	cout << "Insert(9)" << endl;
	oms.insert(9);

	cout << "Number of elements in the set: " << oms.size() << endl;
	PrintSet(oms);

	cout << "Erasing 7..." << endl;
	oms.erase(7);
	PrintSet(oms);

	cout << "Inserting 2..." << endl;
	oms.insert(2);
	PrintSet(oms);

	cout << "Inserting 2 again..." << endl;
	oms.insert(2);
	PrintSet(oms);

	cout << "Inserting 9 again..." << endl;
	oms.insert(9);
	PrintSet(oms);

	cout << "Inserting 9 again..." << endl;
	oms.insert(9);
	PrintSet(oms);
	cout << "---------------------------------------------------" << endl;
#endif

#if 0
	cout << "unordered_set example..." << endl;

	unordered_set<int> uos;

	cout << "Insert(4)" << endl;
	uos.insert(4);

	cout << "Insert(3)" << endl;
	uos.insert(3);

	cout << "Insert(7)" << endl;
	uos.insert(7);

	cout << "Insert(1)" << endl;
	uos.insert(1);

	cout << "Insert(9)" << endl;
	uos.insert(9);

	cout << "Number of elements in the set: " << uos.size() << endl;
	PrintSet(uos);

	cout << "Erasing 7..." << endl;
	uos.erase(7);
	PrintSet(uos);

	cout << "Inserting 2..." << endl;
	uos.insert(2);
	PrintSet(uos);

	cout << "Inserting 2 again!" << endl;
	uos.insert(2);
	PrintSet(uos);
	cout << "---------------------------------------------------" << endl;
#endif

#if 0
	cout << "unordered_multiset example..." << endl;

	unordered_multiset<int> ums;

	cout << "Insert(4)" << endl;
	ums.insert(4);

	cout << "Insert(3)" << endl;
	ums.insert(3);

	cout << "Insert(7)" << endl;
	ums.insert(7);

	cout << "Insert(1)" << endl;
	ums.insert(1);

	cout << "Insert(9)" << endl;
	ums.insert(9);
	cout << "Number of elements in the set: " << ums.size() << endl;
	PrintSet(ums);

	cout << "Erasing 7..." << endl;
	ums.erase(7);
	PrintSet(ums);

	cout << "Inserting 2..." << endl;
	ums.insert(2);
	PrintSet(ums);

	cout << "Inserting 2 again..." << endl;
	ums.insert(2);
	PrintSet(ums);

	cout << "Inserting 9 again..." << endl;
	ums.insert(9);
	PrintSet(ums);

	cout << "Inserting 9 again..." << endl;
	ums.insert(9);
	PrintSet(ums);

	cout << "-------------------------------------------------" << endl;
#endif
} //end-SetExamples

